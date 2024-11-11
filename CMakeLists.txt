cmake_minimum_required(VERSION 3.10)
project(DreamDisk)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/build)

add_subdirectory(libgimbal)

file(GLOB SRCS src/*.c src/*.h)

add_executable(ddisk ${SRCS})
target_link_libraries(ddisk raylib libGimbal)
