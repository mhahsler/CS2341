cmake_minimum_required(VERSION 3.0.0)
project(big-five VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

# show compiler output
#set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# sanitize is an alternative to valgrind on newer versions of gcc and clang
#add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
#link_libraries(asan)

add_executable(test_IntCell test_IntCell_main.cpp IntCell.cpp)
add_executable(test_IntCellPtr test_IntCellPtr_main.cpp IntCellPtr.cpp)
add_executable(test_IntCellPtrOK test_IntCellPtrOK_main.cpp IntCellPtrOK.cpp)

#set(CMAKE_VERBOSE_MAKEFILE OFF)
