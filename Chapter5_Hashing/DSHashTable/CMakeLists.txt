cmake_minimum_required(VERSION 3.0.0)
project(Hashtable VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# add all the .cpp files here
add_executable(main main.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)
