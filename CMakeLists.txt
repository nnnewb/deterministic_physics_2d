cmake_minimum_required(VERSION 3.9)
project(deterministic_physics_2d CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSION OFF)

add_subdirectory("${PROJECT_SOURCE_DIR}/3rd_party/libSDL2pp")
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${SDL2PP_INCLUDE_DIRS})

file(
	GLOB_RECURSE TESTBED_SOURCE_FILES
	"testbed/*.cpp"
	"testbed/*.h")
add_executable(testbed ${TESTBED_SOURCE_FILES})
target_link_libraries(testbed ${SDL2PP_LIBRARIES})
