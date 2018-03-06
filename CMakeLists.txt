cmake_minimum_required(VERSION 3.9)
project(deterministic_physics_2d CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSION OFF)

add_subdirectory("${PROJECT_SOURCE_DIR}/3rd_party/libSDL2pp")
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${SDL2PP_INCLUDE_DIRS})
find_library(SDL2GFX SDL2_gfx DOC "SDL2_gfx library")
if (NOT SDL2GFX)
    message(FATAL_ERROR "Can not found SDL2 gfx library")
else ()
    message(STATUS "Found SDL2_gfx library - ${SDL2GFX}")
endif ()

file(GLOB_RECURSE TESTBED_SOURCE_FILES
        "src/*.h"
        "testbed/*.cpp"
        "testbed/*.h")
add_executable(testbed ${TESTBED_SOURCE_FILES})
target_link_libraries(testbed ${SDL2PP_LIBRARIES} ${SDL2GFX})
