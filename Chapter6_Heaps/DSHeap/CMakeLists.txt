cmake_minimum_required(VERSION 3.0.0)
project(IntCell VERSION 0.1.0)

set(CMAKE_CXX_STANDARD17)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# do not inline functions for profiling
# add_compile_options(-fno-inline)
# for more GCC compiler options see https://gcc.gnu.org/onlinedocs/gcc/Invoking-GCC.html

# add all the .cpp files here
add_executable(main main.cpp)
add_executable(timing timing.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)

# testing with the single_include versions of Catch2 V2 (in directory catch2)
include(CTest)
add_executable(tests test.cpp)
add_test(NAME DSHeap COMMAND tests)
