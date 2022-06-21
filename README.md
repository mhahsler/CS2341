# CS 2342 Code Examples

Requirements:

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
3. Configure cmake by going in the menu to `Help>Show All Commands` and type `cmake:Configure`. This creates
   a file called `CMakeLists.txt`
4. Additonal `.cpp` files can be added in the `add_executable()` instruction in `CMakeLists.txt`.

You are now ready to build and execute the program.

## How to debug

1. Set a breakpoint next to a line of code.
2. Click the debug symbol in the status bar which starts a frontend for `gdb`.
3. Use the navigation pannel and inspect and watch variables.


## How to test

To come