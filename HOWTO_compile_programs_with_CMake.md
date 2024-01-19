# HOWTO Compile Programs With CMake

By Michael Hahsler

Compiling C++ code can be done with several tool chains.
The two popular tool chains used in this class are:

* [GCC](https://en.wikipedia.org/wiki/GNU_Compiler_Collection) (GNU Compiler Collection) contains compilers for 
   various compiled languages. The C++ compiler is often called `g++`.
* [Clang/LLVM](https://en.wikipedia.org/wiki/Clang) (C language family frontend for the [LLVM compiler toolchain](https://llvm.org/))

Compilation consists of two steps (LLVM uses a few more to allow for a source and target-independent intermediate representation):

1. **Compilation** of each `.cpp` file to object code ending in `.o`. During this step code optimization is typically performed. See [Compiler](https://en.wikipedia.org/wiki/Compiler).
2. **Linking** all `.o` files and external libraries together to create the executable. See [Linker](https://en.wikipedia.org/wiki/Linker_(computing)).

The GCC C++ compiler and linker can be called from the terminal as `g++ -O3 -o <executable name> <list all .cpp files>`.

CMake is a popular cross-platform build automation, testing and packaging tool for C++. It organizes the compilation process. It will find/configure your compiler tool chain and produce a `Makefile` (or configuration for a different build system) that does the actual compilation (i.e., how to run `g++` or `clang`). CMake is 
either run by your development environment or from the terminal 
using `cmake -b build .` and the Makefile is run using `make`. 
VS Code puts everything in the `build` subdirectory. 
CMake is configured using the `CMakeLists.txt` file. All `.cpp`
files needed to build the executable need to be specified in the `add_executable()` line or linking will fail. 


## How to Set Up a New Program

Make sure you have VS Code, build tools and the `C/C++` and `Cmake Tools` 
extensions installed.


1. Projects are directories. Make a project directory using the file manager or a terminal, start VS Code and open the directory 
   (for WSL click on the green area and use open folder in WSL; MacOS/Linux use `File>Open Folder`).
2. Create at least a `main.cpp` and a `CMakeLists.txt` file in the directory 
(you can use the ones from the [hello_world example](https://github.com/mhahsler/CS2341/tree/main/Chapter1_Programming/hello_world)).
3. Configure CMake by going in the menu to `Help>Show All Commands` (or push `Shift+CTRL+P`) and type `CMake:Configure`. Choose a compiler
   (latest version of GCC or clang), a project name, and that you want to create an executable.
4. Add all used `.cpp` files in the `add_executable()` instruction in `CMakeLists.txt`.
5. Make sure that the compiler options for warnings and verbose output are enabled in `CMakeLists.txt`.
6. Choose the CMake build variant `CMake: [Debug]` (no code optimization for debugging) or `CMake: [Release]` (fast code with code optimization).
7. Click `Build` in the status bar (at the bottom). You can choose to only build individual executables.
  `CMake` creates a `build` directory with a `Makefile` which is used to
   build the project.
1. Click the `Run` button in the status bar to execute the compiled program.

*Notes:* 

* **Only use the buttons in the bottom task bar!** These will use CMake. There are other buttons (e.g., in VS Codes top right corner). Do not use these because they will use VS Code's internal build tools which are not compatible with CMake. You may need enable visibility when prompted to be able to see the CMake task bar.
* You can also manually run `CMake` and `make`:
  Go to the project directory in your shell (a WSL shell for windows) and use 
   
   ```
   cmake . -B build
   ``` 
 
  to create a Makefile in the `build` directory and use
 
   ```
   cd build 
   make
   ``` 
 
   to compile the project. 
* Some times the `build` or `.vscode` folder are out of date and compilation fails. You can safely delete these folders (right-click delete) and then building should work again.


## How to Compile and Run the Examples in this Repository

1. Clone the repository using `git clone https://github.com/mhahsler/CS2341.git`
2. Go in your shell to an example and run `code .` You can also start VS Code and
  use `Open Folder` (on Windows you need to use `Open Folder in WSL`; click on the green square in the bottom-left corner). 
3. Follow the steps above to configure CMake and build and run the example.

## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)
