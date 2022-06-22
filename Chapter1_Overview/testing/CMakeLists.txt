cmake_minimum_required(VERSION 3.0.0)
project(factorial VERSION 0.1.0)

# regular main
add_executable(factorial main.cpp factorial.cpp)

# testing
find_package(Catch2 2 REQUIRED)

add_executable(tests test.cpp factorial.cpp)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
enable_testing()

include(Catch)
catch_discover_tests(tests)