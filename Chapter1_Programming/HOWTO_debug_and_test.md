# HOWTO Debug and Test


## How to Debug

### In VS Code

1. You may have to configure CMake for debugging by clicking in the status bar on `CMake: [Debug]` and select `Debug`.
2. Set a breakpoint (red dot) to the left of a line number in the source code.
3. Click the debug symbol in the status bar which starts a frontend for `gdb`.
4. Use the navigation panel (appearing on the top of VS Code) and inspect and watch variables.

### Command Line Debugging With `gdb`

1. Find the compiled executable (in VS Code it is in the build directory)
2. Start `gdb executable`.
3. Set a breakpoint with `b` and use `run`. See the [GDB QUICK REFERENCE](https://users.ece.utexas.edu/~adnan/gdb-refcard.pdf) for available commands.


## How to Run Tests

We will use a simple header-based testing framework called
[Catch2](https://github.com/catchorg/Catch2). It can be can be [integrated with CMake/CTest](https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md), but we will use the stand alone version.
Here is an [example with tests.](factorial)

Steps:

1. Add the directory with the single include version of Catch2 to your project (copy directory `catch2` from [this example.](factorial)). 
2. You need a test file like `test.cpp` in the [testing example](factorial/) to define test cases and required outputs. There are [more assertion macros](https://github.com/catchorg/Catch2/blob/v2.x/docs/assertions.md) available.
3. Add the test to `CMakeLists.txt`. The lines should look like (see [testing example](factorial/) for complete file):
   ```
   # testing with the single_include versions of Catch2 V2 (in directory catch2)
   include(CTest)
   add_executable(tests test.cpp <other.cpp you need for compiling the test>)
   add_test(NAME SimpleTest COMMAND tests)
   ```

  With some compilers you also need to specify the C++ standard with 
  `set(CMAKE_CXX_STANDARD17)`.

4. Build the project and then run the tests using the button on the status bar. The test program will print the test results to the screen.

**Note:** Compiling the test with Catch2 takes a while. You can change the build target in the status bar from `[all]` to `[main]` or whatever your executable is called to only compile the program and not the tests.  

Testing using GitHub Actions:

1. At the repository on the Github page, click on Actions and find `CMake based projects`.
2. If you want to use Catch2 for testing, then you need to install it for the test. [See example workflow file](../.github/workflows/testing-example_cmake.yml).

## How to Detect Memory Leaks

Example code: [Big-Five for Classes](big-five)

### Option 1: Valgrind 
[Valgrind](https://valgrind.org/) contains tools that can automatically detect many memory management and threading bugs.
These are issues happening at run-time and the compiler cannot find them.
*Note:* `valgrind` is not available on Windows and the VS Code integration is not great. It can be installed on Ubuntu (Windows with WSL) with the WSL shell command
`sudo apt install valgrind`.

1. Find the compiled executable (in VS Code + CMake it is in the build directory). use `cd build` in the terminal to get there.
2. Run `valgrind --leak-check=full --track-origins=yes ./executable` and look for lost bytes. `executible` is your compiled program.

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

Unfortunately, `valgrind` is not available for MacOS and the standard compilers in Xcode are missing the `asan` library. You will need to run memory leak tests on a Linux host that has the needed tools installed (e.g., using the VS code extension `Remote - ssh`). 
