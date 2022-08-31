# HOWTOs

## How to Set Up a New Program

1. Make a project directory using the file manager, start VS Code and open the directory 
   (for WSL click on the green area and use open folder in WSL; MacOS/Linux use `File>Open Folder`).
2. Create at least a `main.cpp` file in the directory (right-click and choose new file).
3. Configure CMake by going in the menu to `Help>Show All Commands` (or push `CTRL+Shift P`) and type `CMake:Configure`. Choose a compiler
   (latest version of GCC or clang), a project name and that you want to create an executable. This creates a file called `CMakeLists.txt`.
4. Optional: Enable warnings and verbose output like in this [example](IntCell/CMakeLists.txt).
5. Optional: Additional `.cpp` files can be added in the `add_executable()` instruction in `CMakeLists.txt`.
6. Click `Build` in the status bar (at the bottom).
  `CMake` creates a `build` directory with a `Makefile` which is used to
   build the project.
7. Click the `Run` button in the status bar to execute the compiled program.


*Notes:* 

* Only use the buttons in the bottom task bar! These will use CMake. There are other buttons (e.g., in VS Codes top right corner). Do not use these because they will use VS Code's internal build tools which are not compatible with CMake. You see a `.vscode` instead of a `build` folder if you used the wrong button.
* Steps 2 and 3 can be done using `CMake:Quickstart` which will create a Hello World! program.
* You can also manually run `CMake` and `make`:
  Go to the project directory in your shell (a WSL shell for windows) and use 
   
   `cmake . -B build` 
 
  to create a Makefile in the `build` directory and use
 
   `cd build` 
   `make` 
 
   to compile the project. 
* Some times the `build` or `.vscode` folder are out of date and compilation fails. You can safely delete these folders (right-click delete) and then building should work again.


## How to Compile and Run the Examples in this Repository

1. Clone the repository.
2. Go in your shell to an example and run `code .` You can also start VS Code and
  open the folder. 
3. Follow steps above.


## How to Run Automatic Tests

We will use a simple header-based testing framework called
[Catch2](https://github.com/catchorg/Catch2). It can be can be [integrated with CMake/CTest](https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md), but we will use the stand alone version.
Here is an [example with tests.](factorial)

Steps:

1. Add the directory with the single include version of Catch2 to your project (directory catch2 from [this example.](factorial)). 
2. You need a test file like `test.cpp` in the [testing example](factorial/) to define test cases and required outputs. There are [more assertion macros](https://github.com/catchorg/Catch2/blob/v2.x/docs/assertions.md) available.
3. Add a target called `tests` with `test.cpp` to `CMakeLists.txt`. The line should look like
  `add_executable(tests test.cpp <other.cpp files needed>)`.
  With some compilers you also need to specify the C++ standard with 
  `set(CMAKE_CXX_STANDARD17)`.
4. Build the project and then run the target tests (select `[tests]` next to the run symbol in the status bar).

**Note:** Compiling the test with Catch2 takes a while. You can change the build target in the status bar from `[all]` to `[main]` or whatever your executable is called to only compile the program and not the tests.  

Testing using GitHub Actions:

1. At the repository on the Github page, click on Actions and find `CMake based projects`.
2. If you want to use Catch2 for testing, then you need to install it for the test. [See example workflow file](../.github/workflows/testing-example_cmake.yml).

## How to Debug

### In VS Code

1. Set a breakpoint next to a line of code.
2. Click the debug symbol in the status bar which starts a frontend for `gdb`.
3. Use the navigation panel and inspect and watch variables.

### Command Line Debugging With `gdb`

1. Find the compiled executable (in VS Code it is in the build directory)
2. Start `gdb executable`.
3. Set a breakpoint with `b` and use `run`. See the [GDB QUICK REFERENCE](https://users.ece.utexas.edu/~adnan/gdb-refcard.pdf) for available commands.

## How to Detect Memory Leaks

Example code: [Big-Five for Classes](big-five)

### Option 1: Valgrind 
[Valgrind](https://valgrind.org/) contains tools that can automatically detect many memory management and threading bugs.
These are issues happening at run-time and the compiler cannot find them.
*Note:* `valgrind` is not available on Windows and the VS Code integration is not great. It can be installed on Ubuntu (Windows with WSL) with the WSL shell command
`sudo apt install valgrind`.

1. Find the compiled executable (in VS Code + CMake it is in the build directory)
2. Run `valgrind --leak-check=full ./executable` and look for lost bytes.

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
