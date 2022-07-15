cmake_minimum_required(VERSION 3.0.0)
project(IntCell VERSION 0.1.0)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# add all the .cpp files here
add_executable(main main.cpp)
add_executable(timing timing.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)

# testing (needs Catch2 V2 installed)
find_package(Catch2 2 REQUIRED)

add_executable(tests test.cpp)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
enable_testing()

include(Catch)
catch_discover_tests(tests)
