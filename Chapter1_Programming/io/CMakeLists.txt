cmake_minimum_required(VERSION 3.0.0)
project(io VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

## copy test.txt to the build directory
file(COPY test.txt DESTINATION .)


# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(CLInterface CLInterface_main.cpp)
add_executable(fileIO_cstring fileIO_cstring_main.cpp)
add_executable(fileIO_cpp fileIO_cpp_main.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)
