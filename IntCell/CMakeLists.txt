# Minimal CMake file
#
# you can go to the directory in your shell and use
# > cmake
#
# to create a Makefile and
#
# > make
#
# to compile the project

cmake_minimum_required(VERSION 3.0.0)
project(IntCell VERSION 0.1.0)

# add all the .cpp files here
add_executable(IntCell main.cpp IntCell.cpp)