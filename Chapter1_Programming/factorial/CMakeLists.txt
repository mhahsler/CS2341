# Minimal CMake file
#
# You can open the folder in VS Code with
# > code .
# and push build in the bottom status bar. Choose gcc11 as the compiler.
#
# you can also go to the directory in your shell and use
# > cmake . -B build
# to create a Makefile in the build directory and
#
# > cd build
# > make
# to compile the project

cmake_minimum_required(VERSION 3.0.0)
project(factorial VERSION 0.1.0)

# show compiler output
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# executables
add_executable(factorial main.cpp factorial.cpp)
add_executable(factorial_iterative iterative.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)

# testing (needs Catch2 V2 installed)
find_package(Catch2 2 REQUIRED)

add_executable(tests test.cpp factorial.cpp)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
enable_testing()

include(Catch)
catch_discover_tests(tests)