cmake_minimum_required(VERSION 3.0.0)
project(class_templates VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(class_templates main.cpp MemoryCell.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
