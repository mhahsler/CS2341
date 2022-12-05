# HOWTO Prepare for the Data Structures Course

This course is demanding since it builds on many things you have already learned and practiced including 
programming in C++. Below are some things to do and review before class starts.

## Install and Practice Tools
* Get a [GitHub account](https://github.com/).
* Learn how to use [git and GitHub](https://docs.github.com/en/get-started/quickstart/hello-world).
* Learn and parctice how to use ssh and the [shell](https://github.com/mhahsler/CS2341/blob/main/HOWTO_shell_and_ssh.md).
* Learn how to log into a remote host. At SMU, [get an account for SMU's Genuse Linux servers](https://www.smu.edu/OIT/Services/genuse/).
* Install [VS Code and the C++ compiler toolchain with CMake](https://github.com/mhahsler/CS2341#required-tools). Even if you have used a different IDE before, you should learn to use VS Code.
* Practice how to [compile with VS Code/Cmake](https://github.com/mhahsler/CS2341/blob/main/HOWTO_compile_programs_with_CMake.md).
 

## Review C++ Language Concepts
You can use [this very good series of short C++ videos](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb) to refresh your knowledge or learn new topics that you are missing. Just find the 
video that goes with the topic below. Note that the videos use a slightly different IDE (Visual Studio instead of Visual Studio Code).


* Make use of control structures like ifs and loops.
* How to declare classes and their main methods (constructors, rule-of-3, etc).
* Operator overloading in a class.
* Object composition and generalization (inheritance).
* C++ templates.
* Pass-by-value vs. pass-by-reference vs. pass-by-pointer.
* How to declare a pointer.
* The & operator and the * operator.
* What is the difference between a pointer (int* p) and a reference (int& r)?
* The relationship between pointers and arrays (i.e., pointer arithmetic).
* How to dynamically allocate memory on the heap.
* How to work with cstrings (i.e., `\0`-terminated char arrays). How to pass them on to functions,
  and string functions in the libraries `<cstring>` (or `<string.h>`).
* Reading and writing files.
* How to use STL vectors and iterators.
 

## Review Software Design Concepts
* UML Class diagrams.
* How to break a problem down into bite-sized chunks (classes, functions, etc.). Remember, you need a problem description and 
  then nouns can become classes and verbs indicate functions.
* The idea is that a function should do one thing and it should only do that one thing.


## Exercises
* Write a program that finds the 2nd smallest value in an array with only 1 loop.
* Write a program that can generate a valid random tip for playing Powerball (5 numbers in the range of 1-69). Make sure you have no duplicates and that the output is sorted so it is easier to fill out the lotto ticket. 