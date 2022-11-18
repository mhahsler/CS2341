# Command Line Interface

The Command Line Interface (CLI) is the most important interface for most programs. The CLI consists of a 
number of parameters passed on to a program then it is started from the shell (terminal). Here is a 
[HOWTO on using the shell](https://github.com/mhahsler/CS2341/blob/main/HOWTO_shell_and_ssh.md). 


Code Example: [Using the CLI.](CLInterface_main.cpp)

You can

1. Manually run the built executable with command line arguments. Open the terminal, go to the build directory and try:

   ```
   ./CLInterface a b c=d e = f "g = h"
   ./CLInterface *
   ./CLInterface *.cmake
   ```

2. Set the command line arguments in VS Code and CMake:
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

We will use reading text files in this class. Reading files involves asking the operating system for the file content. There are two options in C++.

1. C-Style File I/O
   
   C file I/O uses cstring buffers and interacts more directly with the operating system.

   Example: [C file I/O example](fileIO_cstring_main.cpp)

2. C++-Style File I/O
   
   C++ file I/O uses streams and `std::string` and is much more convenient.
   C++ also provides convenient access to filesystem operations (copy files, deal with paths, iterate over files, etc.),
   C++17 incorporates `boost.filesystem` as library [filesystem.h](https://en.cppreference.com/w/cpp/filesystem). You need add `set(CMAKE_CXX_STANDARD 17)` to 
   `CMakeLists.txt` to use this standard C++ version.

   Example: [C++ file I/O example](fileIO_cpp_main.cpp)

