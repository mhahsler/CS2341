# File I/O

We will use reading text files in this class. Reading files involves asking the operating system for the file content. There are two options in C++.

**Important:** Do not mix these two approaches! If you have a choice, then use C++-style since it is easier and safer!

## C++-Style File I/O
   
   C++ file I/O uses streams and `std::string` and is much more convenient.
   C++ also provides convenient access to filesystem operations (copy files, deal with paths, iterate over files, etc.),
   C++17 incorporates `boost.filesystem` as library [filesystem.h](https://en.cppreference.com/w/cpp/filesystem). You need add `set(CMAKE_CXX_STANDARD 17)` to 
   `CMakeLists.txt` to use this standard C++ version.

   Example: [C++ file I/O example](fileIO_cpp_main.cpp)
 
## C-Style File I/O
   
   C file I/O uses cstrings and buffers. It interacts more directly with the operating system. You need to be careful about buffer overflows (a type of memory leak)!

   Example: [C file I/O example](fileIO_cstring_main.cpp)

## Organizing files in your project

Here are some considerations about where files in your project should be and where your program should write files:

1. **Never use absolute paths** starting with `/` or on Windows with `C:`. Use relative paths starting with `./`
2. VS Code creates a build directory and your program will be executed in that directory. All data files should 
   be in that directory and the files your program creates should go the there as well. **Never read from or write to the directory with your source code** using `../`! Data is copied to the build directory by the `CMakeLists.txt` 
   with lines like `file(COPY test.txt DESTINATION .)`.



