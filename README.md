# <img src="images/DS_Weiss_Book.jpg" align="right"> Code Examples for Data Structures

This course is designed to teach basic data structures, their implementation
for current hardware, and their performance tradeoffs.  We will use C++, a
language widely used to implement performance-critical components of
applications.  C++ provides access to low-level memory management facilities
and is therefore well-suited for learning about data structures and their
efficient implementations. It will provide the basis for understanding the
impact of the used data structures on memory consumption and runtime.  This
knowledge is especially important when using managed programming languages like
Java or Python which hide important aspects from the programmer.

**Textbook:** Data Structures and Algorithm Analysis in C++ (Fourth Edition), by Mark Allen Weiss.
Source Code by Mark Allen Weiss can be found [here.](https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/)

## Preparation for this course 

This course assumes that you know the basics of C++ programming, object-oriented design, and memory management from
an introductory C++ course. To make sure you are ready, work through [HOWTO prepare for this data structures course](HOWTO_prepare_for_data_structures.md).

## Course Material

| Book Chapter | Lecture Notes and Code                            |
| :----------: | :------------------------------------------------ |
|      1       | [Programming](Chapter1_Programming)               |
|      2       | [Algorithm Analysis](Chapter2_Algorithm_Analysis) |
|      3       | [Lists, Stacks, and Queues](Chapter3_Lists_etc)   |
|      4       | [Trees](Chapter4_Trees)                           |
|      5       | [Hashing](Chapter5_Hashing)                       |
|      6       | [Heaps](Chapter6_Heaps)                           |
|      7       | [Sorting](Chapter7_Sorting)                       |
|      9       | [Graphs](Chapter9_Graphs)                         |

Code developed in class can be found in the [CS2341_Scratch repository.](https://github.com/mhahsler/CS2341_Scratch)

Course material and assignments for CS 2341 at SMU can be found on [Canvas](https://www.smu.edu/OIT/Services/Canvas/).



## Required Tools

### Installation on your own computer
* Install [Visual Studio Code](https://code.visualstudio.com/) (VS Code)
* Install compilers and `cmake`:
    - On **Linux** you most likely have already everything you need installed (`gcc`, `cmake`, `valgrind`). If not, 
      then install the missing packages using your package manager (e.g., on Ubuntu using `sudo apt-get install build-essential cmake valgrind`). 
    - On **Windows** you will need to [install WSL](https://code.visualstudio.com/docs/cpp/config-wsl) and install and use the VS Code remote-WSL Extension ([here is a video](https://www.youtube.com/watch?v=NY5izJWXi0U)). You also need to install `cmake` and `valgrind` using the WSL shell (`sudo apt-get install build-essential cmake valgrind`). You will always need to open folders by clicking on the green `><` at the bottom left corner of VS Code and select open folder in WSL.
    - On **MacOS** you need to install [clang](https://code.visualstudio.com/docs/cpp/config-clang-mac) and 
      set up the path using [shell command](https://code.visualstudio.com/docs/setup/mac). You also need to install [cMake](https://cmake.org/install/) (follow the instructions carefully and set the PATH). 
      An installation option is [Homebrew](https://brew.sh/).
* Install [git](https://git-scm.com/) and then you can use the [VS Code integration](https://code.visualstudio.com/docs/editor/versioncontrol).
* Install [VS Code extensions for C++ and CMake](https://code.visualstudio.com/docs/languages/cpp). 
  The extensions are: `C/C++`, `C/C++ Extension Pack`, `CMake Tools`. VS Code will prompt you to install these. Make sure that you install the extensions **after** you have the software above installed or it might not find it during setting up the extension. 


### Using VS Code With a Remote Linux Server
If you have access to a linux host server with all development tools installed (see [Genuse servers](https://www.smu.edu/OIT/Services/genuse) for SMU students) then you can work on the server by installing only VS Code and the VS Code extension `Remote - SSH` on your computer. You can then connect to the linux host by clicking on the green `><` at the bottom left corner of VS Code ([details](https://code.visualstudio.com/docs/remote/ssh)). 
This is a good option if certain tools
are not available for your computer architecture (e.g., `valgrind` is not available for MacOS with M1 and M2 processors).
Details on how to use ssh and the shell can be found below.


## HOWTOs
* [HOWTO prepare for this data structures course](HOWTO_prepare_for_data_structures.md)
* [GitHub Quickstart](https://docs.github.com/en/get-started/quickstart)
* [HOWTO Use a Shell and SSH](HOWTO_shell_and_ssh.md)
* [HOWTO Compile Programs With VS Code and CMake](HOWTO_compile_programs_with_CMake.md)
* [HOWTO Good Coding Practice](HOWTO_good_coding_practice.md)
* [HOWTO Debug](HOWTO_debug.md)
* [HOWTO Detect Memory Leaks](HOWTO_detect_memory_leaks.md)
* [HOWTO Test](HOWTO_test.md)
* [HOWTO Profile Code](HOWTO_profile_code.md)


## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)
