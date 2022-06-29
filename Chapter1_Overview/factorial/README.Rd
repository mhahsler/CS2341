# Opening, compiling and runing Code

Using the shell, you can open the folder in VS Code with

`code .`

## CMake was already configured (i.e., there is a `CMakeLists.txt`)

* Push build in the bottom status bar. Choose gcc11 as the compiler.

* You can also go to the directory in your shell and use
  
   `cmake . -B build`

   to create a Makefile in the build directory and

   `cd build`
   `make`

   to compile the project.

## CMake has not been configured

Push `CTRL+Shift P`, type `CMake: Configure` and follow the instructions.
