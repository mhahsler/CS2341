cmake_minimum_required(VERSION 3.0.0)
project(DSvector VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic)

add_executable(main main.cpp DSMatrix)

# This needs BLAS libraries installed
find_package(BLAS REQUIRED)
add_executable(main_blas main_blas.cpp)