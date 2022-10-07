# Command Line Interface

Example: [How to use the CLI.](CLInterface_main.cpp)

You can

1. Manually run the built executable with command line arguments. Open the terminal, go to the build directory and try:

   ```
   ./CLInterface a b c=d e = f "g = h"
   ./CLInterface *
   ./CLInterface *.cmake
   ```

2. Set the command line arguments in VSCode and CMake:
   * `CTRL-SHIFT+P` `settings.json` choose `Preferences: Open Work Space Settings`. This creates settings.json in the .vscode folder.
   * Add the following lines: 
     ```
     {
     "cmake.debugConfig": {
        "args": [
            "argument_1",
            "argument_2"
        ]
       }
     }
     ```

Note that arguments cannot have a space unless they are in (escaped) quotation marks and that `*` is expanded to matching file names.


# File I/O


## C
C file I/O uses cstring buffers.

Example: [C file I/O example](fileIO_cstring_main.cpp)

## C++

C++ file I/O uses streams and `std::string`.
C++ also provides convenient access to filesystem operations (copy files, deal with paths, iterate over files, etc.),
C++17 incorporates `boost.filesystem` as library [filesystem.h](https://en.cppreference.com/w/cpp/filesystem). You need add `set(CMAKE_CXX_STANDARD 17)` to 
`CMakeLists.txt` to use this standard C++ version.

Example: [C++ file I/O example](fileIO_cpp_main.cpp)

