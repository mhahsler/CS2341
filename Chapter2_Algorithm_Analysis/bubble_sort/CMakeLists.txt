cmake_minimum_required(VERSION 3.0.0)
project(bubble_sort VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(bubble_sort main.cpp)
add_executable(bubble_sort_timing timing.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
