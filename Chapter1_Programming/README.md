# Chapter 1: Programming

This chapter is a review of important concepts and their C++ implementation 
used in this course. Very good short explanations can be found in this
[C++ YouTube Playlist](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb).

## Classes and Templates
* Example: A simple class called [IntCell](IntCell)
* Example: [Function and class templates](templates)
* Example: [Call-by-value vs call-by-reference](parameters) and using `const`.

## Dynamic Memory Allocation
### Memory Management
* Some Questions:
  - Where do programs store variables and objects?
  - Where does memory come from and how is memory returned?
  - Why do we need dynamic memory allocation?
  - What is the difference between the stack and the heap.
  - Example: Create a memory diagram for executing the following program:

    ```cpp
    int inc(int x) return x + 1;

    int main() {
      int a = 10;
      int b = inc(a);
      return 0;
    }
    ```

  - Differences between memory management in C, C++, Java and Python.
    |                | C   | C++ | Java | Python |
    | :------------- | :-: | :-: | :--: | :----: |
    | Request memory |  ?  |  ?  |   ?  |   ?    |
    | Return memory  |  ?  |  ?  |   ?  |   ?    |

* Video: [Memory Diagrams](http://vimeo.com/58710057)
* Example: [Memory allocation](memory)
* Example: [Pointers and Dynamic Memory Allocation](pointers)
* Reading: [References vs. Pointers](https://isocpp.org/wiki/faq/references)
* Example: Destructor, copy constructor and assignment operator: [The Big five for classes](big-five)

## Standard Template Library
* Reading: [The C++ Standard Template Library (STL)](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)
* Example: [Arrays and cstrings vs STL vectors and strings](vector_string)
* Example: [Comparator](comparator)

## Recursion and Testing
* Example: [Calculate factorials](factorial)

## Command Line Interface and File IO
* Example: [CLI and file IO](io)

## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)