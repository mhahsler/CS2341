cmake_minimum_required(VERSION 3.0.0)
project(STD_map VERSION 0.1.0)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# add all the .cpp files here
add_executable(STD_map main.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)
