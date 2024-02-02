cmake_minimum_required(VERSION 3.0.0)
project(vector_string VERSION 0.1.0)

# show compiler output
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# executables
add_executable(array_vs_vector main_array_vs_vector.cpp)
add_executable(std_cstring_vs_string main_cstring_vs_std_string.cpp)
add_executable(index_problem main_index_problem.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)
