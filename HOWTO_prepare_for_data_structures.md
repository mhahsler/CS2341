# HOWTO Prepare for the Data Structures Course

This course is demanding since it builds on many things you have already learned and practiced including 
programming in C++. Below are some things to do and review before class starts.

## Install and Practice Tools
* Get a [GitHub account](https://github.com/).
* Learn how to use [git and GitHub](https://docs.github.com/en/get-started/quickstart/hello-world).
* Learn and practice how to use ssh and the [shell](https://github.com/mhahsler/CS2341/blob/main/HOWTO_shell_and_ssh.md).
* Learn how to log into a remote host. At SMU, [get an account for SMU's Genuse Linux servers](https://www.smu.edu/OIT/Services/genuse/).
* Install [VS Code and the C++ compiler toolchain with CMake](https://github.com/mhahsler/CS2341#required-tools). Even if you have used a different IDE before, you should learn to use VS Code.
* Practice how to [compile with VS Code/Cmake](https://github.com/mhahsler/CS2341/blob/main/HOWTO_compile_programs_with_CMake.md).
 

## Review C++ Language Concepts

Here are the concepts that you need to know and be able to apply:

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
* How to work with cstrings (i.e., `\0`-terminated char arrays). How to pass them on to functions you implement,
  and to an existing string function in the libraries `<cstring>` (`<string.h>`).
* Reading and writing files.
* How to use STL vectors and iterators.
 
You can brush up your knowledge using the following resources.
* Here is the Linked-in-learning course [C++ Essential Training](https://www.linkedin.com/learning-login/share?account=2139050&forceAccount=false&redirect=https%3A%2F%2Fwww.linkedin.com%2Flearning%2Fc-plus-plus-essential-training-15106801%3Ftrk%3Dshare_ent_url%26shareId%3DY6vgr5xvTmym7SM7gNWfkA%253D%253D). SMU students have a free subscription ([log in here](https://www.smu.edu/OIT/Services/linkedin)).
* You can also use [this very good series of short C++ videos](https://wVww.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb) to refresh your knowledge or learn new topics that you are missing. A good idea is to watch a 15 minute video every day or you can just find the 
video that goes with the topic below. Note that the videos use a slightly different IDE (Visual Studio instead of Visual Studio Code).

To practice applying these concepts you can:
* Solve easy and medium problems on [LeetCode](https://leetcode.com/problemset/all/) (you can log in with your GitHub account).
* Practice with [HackerRank](https://www.hackerrank.com/) (you can log in with your GitHub account).


## Review Software Design Concepts
* UML [Class diagrams](https://www.smartdraw.com/class-diagram/). A good tool is [smartdraw](https://www.smartdraw.com/uml-diagram/)
* How to break a problem down into bite-sized chunks (classes, functions, etc.). Remember, you need a problem description and 
  then nouns can become classes and verbs indicate functions.
* Good program organization means that a function should do one thing and it should only do that one thing.

To brush up your knowledge you can review the Linkedin Learning course [Programming Foundations: Object-Oriented Design](https://www.linkedin.com/learning-login/share?account=2139050&forceAccount=false&redirect=https%3A%2F%2Fwww.linkedin.com%2Flearning%2Fprogramming-foundations-object-oriented-design-3%3Ftrk%3Dshare_ent_url%26shareId%3DMy0cEP4nR%252Bmk%252Fdm%252F4xNQMA%253D%253D).


## Check Your Knowledge
* Write a program that finds the 2nd smallest value in an array with only 1 loop.
* Design a program that can help you play Powerball (5 numbers in the range of 1-69). The program should help you generate a valid random tips for playing. Make sure you have no duplicates and that the output is sorted so it is easier to fill out the lotto ticket. It should also store your tips and check them against the actual drawn numbers to tell you if you won something. Make sure you start with identifying use cases (i.e., how would the user create tips and how would the user check if she won) and a UML class diagram first.
