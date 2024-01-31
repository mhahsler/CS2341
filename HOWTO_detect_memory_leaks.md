# How to Detect Memory Leaks

By Michael Hahsler

Example code: [Big-Five for Classes](Chapter1_Programming/big-five)

### Option 1: Valgrind 
[Valgrind](https://valgrind.org/) contains tools that can automatically detect many memory management and threading bugs.
These are issues happening at run-time and the compiler cannot find them.
*Note:* `valgrind` is not available on Windows or MacOS and the VS Code integration is not great. It can be installed on Ubuntu (Windows with WSL) with the WSL shell command
`sudo apt install valgrind`. 

1. Find the compiled executable (in VSCode + CMake it is in the `build` subdirectory). use `cd build` in the terminal to get there.
2. Run 
    ```
    valgrind --leak-check=full --track-origins=yes ./executable
    ``` 
    and look for lost bytes. `executable` is your compiled program.

To make this easier, CTest automatically finds valgrind (if installed) and runs it on the tests by typing `ctest -T MemCheck` in the build directory. Note that it does not 
run it on your main program, just on the tests.

Valgrind can also be used for profiling (finding out where your code is slow).
Here is a description of [how to profile with Valgrind](https://developer.mantidproject.org/ProfilingWithValgrind.html).

### Option 2: AddressSanitizer Library

Recent versions of GCC and clang come with the [`asan` (AddressSanitizer) library.](https://github.com/google/sanitizers/wiki/AddressSanitizer)
All you need to do is add the following to your `CMakeLists.txt`:

```
# Use the AddressSanitizer library to detect memory leaks at run-time. 
add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
link_libraries(asan)
```

You need to comment these lines out if you want to compile the program for use (the sanitizer checks  slow the code down).

### MacOS

Unfortunately, `valgrind` is not available for MacOS (new M1 and M2 architecture) and the standard compilers in Xcode are missing the `asan` library. You will need to run memory leak tests on a Linux host that has the needed tools installed (e.g., using the VS Code extension `Remote - ssh`). 

## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)
