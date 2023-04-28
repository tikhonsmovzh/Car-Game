cmake_minimum_required(VERSION 3.16)
project(RayLibShowcase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CheckCXXSymbolExists)
check_cxx_symbol_exists(CLOCK_MONOTONIC time.h HAVE_CLOCK_MONOTONIC)
check_cxx_symbol_exists(QueryPerformanceCounter windows.h HAVE_QPC)
set(CMAKE_REQUIRED_DEFINITIONS)
add_definitions("-pthread")

file(GLOB SOURCES src/*.cpp)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(./libs/raylib-3.7.0 ./libs/raylib)

## Building chipmunk
set(BUILD_DEMOS OFF CACHE BOOL "Chipmunk Demos" FORCE)
set(BUILD_SHARED OFF CACHE BOOL "Build and install the shared library" FORCE)
add_subdirectory(./libs/chipmunk ./libs/chipmunk)

#add_library(RayLibShowcase ${SOURCES})
add_executable(RayLibShowcase ${SOURCES})
target_include_directories(RayLibShowcase PUBLIC
        libs/chipmunk/include/chipmunk
        src)
target_link_libraries(RayLibShowcase PRIVATE raylib)
target_link_libraries(RayLibShowcase PUBLIC chipmunk_static)


