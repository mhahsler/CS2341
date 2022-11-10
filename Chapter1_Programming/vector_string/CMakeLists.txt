cmake_minimum_required(VERSION 3.0.0)
project(vector_string VERSION 0.1.0)

# show compiler output
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# executables
add_executable(vector_string main.cpp)
add_executable(index_problem index_problem.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)
