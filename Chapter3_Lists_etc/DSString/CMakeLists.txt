cmake_minimum_required(VERSION 3.15)
project(string)

set(CMAKE_CXX_STANDARD 17)
# C++17 includes a library to work with the file system
# https://en.cppreference.com/w/cpp/filesystem


# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# Create the executable
add_executable(string main.cpp DSString)

set(CMAKE_VERBOSE_MAKEFILE OFF)

