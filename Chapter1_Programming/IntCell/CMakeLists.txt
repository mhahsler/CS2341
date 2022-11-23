# Minimal CMake file
#
# You can open the folder in VS Code with
# > code .
# and push build in the bottom status bar. Choose gcc 11 as the compiler.
#
# you can also go to the directory in your shell and use
# > cmake . -B build
# to create a Makefile and
#
# > cd build
# > make
# to compile the project

cmake_minimum_required(VERSION 3.0.0)
project(IntCell VERSION 0.1.0)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# for more GCC compiler options see https://gcc.gnu.org/onlinedocs/gcc/Invoking-GCC.html

# add all the .cpp files here
add_executable(IntCell main.cpp IntCell.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)