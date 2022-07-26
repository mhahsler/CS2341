# Command Line Interface and I/O

## CLI

Example: [How to use the CLI.](CLInterface_main.cpp)

## (File I/O)

I/O is organized as streams.

Example: [How to read from a file.](fileIO_main.cpp)

To perform operations on the filesystem (copy files, deal with paths, iterate over files, etc.),
C++17 incorporates `boost.filesystem` as library [filesystem.h](https://en.cppreference.com/w/cpp/filesystem). You need add `set(CMAKE_CXX_STANDARD 17)` to 
`CMakeLists.txt` to use this standard C++ version.
