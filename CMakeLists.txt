cmake_minimum_required(VERSION 3.9)
project(deterministic_physics_2d CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSION OFF)

# collect source files
file(
    GLOB_RECURSE ${PROJECT_NAME}_SOURCE_FILES
    "src/*.cpp"
    "src/*.cc"
    "src/*.h")

include_directories(${PROJECT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE_FILES})

option(${PROJECT_NAME}_BUILD_TESTS OFF "Build unit tests for ${PROJECT_NAME}")
if(${PROJECT_NAME})
    find_package(GTest REQUIRED)
    enable_testing(ON)

    # collect source files
    file(
        GLOB_RECURSE ${PROJECT_NAME}_TEST_SOURCE_FILES
        "tests/*.cpp"
        "tests/*.h")

    add_executable(all_tests ${${PROJECT_NAME}_TEST_SOURCE_FILES})
    add_test(all_tests all_tests)
    target_link_libraries(all_tests GTest::GTest GTest::GTestMain)
endif(${PROJECT_NAME})
