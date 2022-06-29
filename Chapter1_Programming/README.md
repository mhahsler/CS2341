# Chapter 1: A Programming

## Code Examples

### Recursion, compiling and testing
* [factorial](factorial)
* Video: [Memory Diagrams](http://vimeo.com/58710057)

### Classes
* [IntCell](IntCell)

### Pointers
* [pointers](pointers)
* Reading: [References vs. Pointers](https://isocpp.org/wiki/faq/references)

### STL vector and string
* [vector_string](vector_string)
* Reading: [The C++ Standard Template Library (STL)](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)

### Parameter passing
* [parameters](parameters)

### Destructor, copy constructor and assignment
* [big-five](big-five)

### Templates
* [function_templates](function_templates)
* [class_templates](class_templates)

### Comparators
* [comparator](comparator)

### Command line parameters and file IO
* [io](io)

# HOWTOs

## How to Compile and Run the Examples in this Repository

1. Clone the repository.
2. Go in your shell to an example and run `code .` Each folder can be seen as a project.
3. Click `Build` in the status bar. `CMake` creates a `build` directory with a `Makefile` which is used to
   build the project.
4. Click the run button in the status bar.

*Note:* If you move a project directory, then you have to clean the project by removing the build folder.

## How to Set Up a New Program

1. Make a directory.
2. Create at least a `main.cpp` file.
3. Configure CMake by going in the menu to `Help>Show All Commands` (or push `CTRL+Shift P`) and type `CMake:Configure`. Choose a compiler
   (C++11) and that you want to create an executable. This creates a file called `CMakeLists.txt`.
4. Enable warnings and verbose output like in this [example](IntCell/CMakeLists.txt).
5. Additonal `.cpp` files can be added in the `add_executable()` instruction in `CMakeLists.txt`.

You are now ready to build and execute the program.

*Note:* Steps 2 and 3 can be done using `CMake:Quickstart` which will create a Hello World! program.


## How to Run Automatic Tests

CMake comes with CTest. CTest is not a testing framework but a tool to automate running tests. We also need a testing framework.
We will use a simple header-based framework called
[Catch2](https://github.com/catchorg/Catch2) which can be
easily [integrated with CMake/CTest](https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md).

Steps:

1. Install Catch2 with `sudo apt-get install catch2`
or [build it from GitHub](https://github.com/catchorg/Catch2/blob/v2.x/docs/cmake-integration.md#installing-catch2-from-git-repository). Caution: use version V2.x.
2. You need a test file like `test.cpp` in the [testing example](factorial/) to define test cases and required outputs. There are [more assertion macros](https://github.com/catchorg/Catch2/blob/v2.x/docs/assertions.md) available.
3. Add a testing section to `CMakeLists.txt`.
4. Building and testing is available in the status bar.

Testing using GitHub Actions:

1. At the repository on the Github page, click on Actions and find `CMake based projects`.
2. If you want to use Catch2 for testing, then you need to install it for the test. [See example workflow file](../.github/workflows/testing-example_cmake.yml).

## How to Debug

### In VS Code

1. Set a breakpoint next to a line of code.
2. Click the debug symbol in the status bar which starts a frontend for `gdb`.
3. Use the navigation panel and inspect and watch variables.

### Command line debugging with `gdb`

1. Find the compiled executable (in VS Code it is in the build directory)
2. Start `gdb executable`.
3. Set a breakpoint with `b` and use `run`. See the [GDB QUICK REFERENCE](https://users.ece.utexas.edu/~adnan/gdb-refcard.pdf) for available commands.

### Valgrind to detect memory leaks


[Valgrind](https://valgrind.org/) tools that can automatically detect many memory management and threading bugs.
*Note:* `valgrind` is not available on Windows and the VS Code integration is not great. It can be installed on Ubuntu with
`sudo apt install valgrind`.

1. Find the compiled executable (in VS Code it is in the build directory)
2. Run `valgrind --leak-check=full ./executable` and look for lost bytes.


