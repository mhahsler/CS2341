cmake_minimum_required(VERSION 3.0.0)
project(sort VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(sort main.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)

