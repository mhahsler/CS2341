# Command Line Arguments

The Command Line Interface (CLI) is the most important interface for most programs. The command line arguments consists of a 
number of parameters passed on to a program when it is started from the shell (terminal). Most operating systems are implemented in C, so your program gets C data structures.
Here is a 
[HOWTO on using the shell](https://github.com/mhahsler/CS2341/blob/main/HOWTO_shell_and_ssh.md). 

Example of using the CLI: `rm file.txt` Here the program `rm` gets the command line argument `file.txt`

Code Example: [Using command line arguments.](CLInterface_main.cpp)

You can manually run the built executable with command line arguments. Open the terminal

   ```
   cd build
   ./CLInterface
   ./CLInterface a b c=d e = f "g = h"
   ./CLInterface *
   ./CLInterface *.cmake
   ```

Remember that the terminal lets you use the tab key for autocompletion and the up key to recall your previous commands so you do not have to retype long argument lists every time you run your program with command line arguments.


**Notes:** 

* Arguments cannot have a space unless they are in quotation marks or escaped using the backslash `\ `.
* `*` is expanded by the shell to matching file names in a directory.

