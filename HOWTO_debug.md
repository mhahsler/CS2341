# HOWTO Debug C++ Code

By Michael Hahsler

You need to have `gdb` ([GNU Project Debugger](https://www.sourceware.org/gdb/)) installed. 

### In VS Code

1. You may have to configure CMake for debugging by clicking in the status bar on `CMake: [Debug]` and select `Debug`.
2. Set a breakpoint (red dot) to the left of a line number in the source code.
3. Click the debug symbol in the status bar which starts a frontend for `gdb`.
4. Use the navigation panel (appearing on the top of VS Code) and inspect and watch variables.

If you want to debug your program with the VS Code run button and command line arguments, then you can set the command line arguments in VS Code and CMake:
   * `CTRL-SHIFT+P` type `settings.json` and choose `Preferences: Open Work Space Settings`. This creates settings.json in the .vscode folder.
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


### Command Line Debugging With `gdb`

1. Find the compiled executable (in VS Code it is in the build directory)
2. Start `gdb executable`.
3. Set a breakpoint with `b` and use `run`. See the [GDB QUICK REFERENCE](https://users.ece.utexas.edu/~adnan/gdb-refcard.pdf) for available commands.



## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)
