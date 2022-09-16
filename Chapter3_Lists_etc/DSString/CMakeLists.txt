cmake_minimum_required(VERSION 3.15)
project(string)

set(CMAKE_CXX_STANDARD 17)
# C++17 includes a library to work with the file system
# https://en.cppreference.com/w/cpp/filesystem


# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# Use the AddressSanitizer library to detect memory leaks at run-time.
#add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
#link_libraries(asan)


# Create the executable
add_executable(string main.cpp DSString)

set(CMAKE_VERBOSE_MAKEFILE OFF)

