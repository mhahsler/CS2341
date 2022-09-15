# HOWTO Compile Programs With CMake

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

* **Only use the buttons in the bottom task bar!** These will use CMake. There are other buttons (e.g., in VS Codes top right corner). Do not use these because they will use VS Code's internal build tools which are not compatible with CMake. You see a `.vscode` instead of a `build` folder if you used the wrong button.
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


 