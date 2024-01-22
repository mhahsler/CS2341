# Minimal CMake file
#
# You can open the folder in VS Code with
# > code .
# and push build in the bottom status bar. Choose GCC with the latest version as the compiler.
#
# you can also go to the directory in your shell and use
# > cmake . -B build -G "Unix Makefiles"
# to create a Makefile and
#
# > cd build
# > make
# to compile the project

cmake_minimum_required(VERSION 3.0.0)
project(hello_world VERSION 0.1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)
# for more GCC compiler options see https://gcc.gnu.org/onlinedocs/gcc/Invoking-GCC.html

# add all components that need to be compiled and linked (the .cpp and .h files with code)
# Syntax: add_executable(Executable_Name <list of files to compile>)
add_executable(hello_world main.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)
