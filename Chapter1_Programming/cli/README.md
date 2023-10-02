# Command Line Interface

The Command Line Interface (CLI) is the most important interface for most programs. The CLI consists of a 
number of parameters passed on to a program when it is started from the shell (terminal). Here is a 
[HOWTO on using the shell](https://github.com/mhahsler/CS2341/blob/main/HOWTO_shell_and_ssh.md). 

Example of using the CLI: `rm file.txt` Here the program `rm` gets the command line argument `file.txt`

Code Example: [Using the CLI.](CLInterface_main.cpp)

You can manually run the built executable with command line arguments. Open the terminal

   ```
   cd build
   ./CLInterface
   ./CLInterface a b c=d e = f "g = h"
   ./CLInterface *
   ./CLInterface *.cmake
   ```

Remember that the terminal lets you use the tab key for autocompletion and the up key to recall your previous commands so you do not have to retype long argument lists every time you run your program with command line arguments.

If you want to run your program with the VS Code run button, then you can set the command line arguments in VS Code and CMake:
   * `CTRL-SHIFT+P` `settings.json` choose `Preferences: Open Work Space Settings`. This creates settings.json in the .vscode folder.
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

**Notes:** 

* Arguments cannot have a space unless they are in quotation marks or escaped using the backslash `\ `.
* `*` is expanded by the shell to matching file names in a directory.

