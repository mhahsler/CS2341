# <img src="images/DS_Weiss_Book.jpg" align="right"> CS 2342 Code Examples

Textbook: Data Structures and Algorithm Analysis in C++ (Fourth Edition), by Mark Allen Weiss

Source Code by Mark Allen Weiss:
https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/

## Tool Requirements

* Install Visual Studio Code: https://code.visualstudio.com/
* On Windows you will need to install WSL: https://code.visualstudio.com/docs/cpp/config-wsl
* Install Extensions for C++ and cmake: https://code.visualstudio.com/docs/languages/cpp


## How to compile and run the examples in this repository

1. Clone the repository.
2. Go in your shell to an example and run `code .` Each folder can be seen as a project.
3. Click `Build` in the status bar. `cmake` creates a `build` directory with a `Makefile` which is used to 
   build the project.
4. Click the run button in the status bar.

*Note:* If you move a project directory, then you have to clean the project by removing the build folder.

## How to set up a new program

1. Make a directory.
2. Create at least a `main.cpp` file.
3. Configure cmake by going in the menu to `Help>Show All Commands` and type `cmake:Configure`. Choose a compiler 
   (C++11) and that you want to create an executable. This creates a file called `CMakeLists.txt`.
4. Additonal `.cpp` files can be added in the `add_executable()` instruction in `CMakeLists.txt`.

You are now ready to build and execute the program.

*Note:* Steps 2 and 3 can be done using `cmake:Quickstart` which will create a Hello World! program.

## How to debug

### In VS Code:

1. Set a breakpoint next to a line of code.
2. Click the debug symbol in the status bar which starts a frontend for `gdb`.
3. Use the navigation pannel and inspect and watch variables.

### Command line debuging with `gdb`.

1. Find the compiled executable (in VS Code it is in the build directory)
2. Start `gdb executable`.
3. set a break point with `b` and use `run`. See the [GDB QUICK REFERENCE](https://users.ece.utexas.edu/~adnan/gdb-refcard.pdf) for available commands.

### Valgrind to detect memory leaks

*Note:* `valgrind` is not available on Windows and the VS Code integration is not great. On Ubuntu it can be installed with
`sudo apt install valgrind`.

1. Find the compiled executable (in VS Code it is in the build directory)
2. Run `valgrind --leak-check=full ./executable` and look for lost bytes.

## How to test

To come
