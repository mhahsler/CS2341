cmake_minimum_required(VERSION 3.0.0)
project(io VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

add_executable(CLInterface CLInterface_main.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)
