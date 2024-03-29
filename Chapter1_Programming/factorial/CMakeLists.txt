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

set(CMAKE_CXX_STANDARD17)
# show compiler output
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# Executables
add_executable(factorial_iterative factorial_iterative_main.cpp)

# main function with tests
add_executable(tests_main factorial_test_main.cpp factorial.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)

# Tests

# testing with the single_include versions of Catch2 V2 (in directory catch2)
include(CTest)
add_executable(tests_catch factorial_test_catch.cpp factorial.cpp)
add_test(NAME SimpleTest COMMAND tests_catch)
# you can add more tests with mote add_executable and add_test lines
# you should have a test for each class

# Code Coverage
# Needs: 
#   * lcov (sudo apt-get install lcov)
#   * CMakeModules/CodeCoverage.cmake
# Run with: make coverage. It produces coverage output in build/coverage

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    if(LCOV_PATH)
        append_coverage_compiler_flags_to_target(tests_catch)
        setup_target_for_coverage_lcov(
           NAME coverage
           EXECUTABLE tests_catch
    )
    endif()
endif()