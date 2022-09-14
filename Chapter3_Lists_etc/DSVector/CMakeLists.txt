cmake_minimum_required(VERSION 3.0.0)
project(DSVector VERSION 0.1.0)

set(CMAKE_CXX_STANDARD17)
# show compiler output
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

add_executable(DSVector main.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
