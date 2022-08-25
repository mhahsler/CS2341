# Arrays and cstrings vs STL vectors and strings

C-style arrays are just pointers to memory (first element of the array).

C-style arrays have several drawbacks:

1. If we do not know the array size at compile time, then we need to use 
   dynamic memory allocation and pointers. 
2. Arrays cannot be assigned with `=` or compared with `==` (they are pointers to the first elements).
3. Arrays do not know its length (at least not consistently).
4. Arrays cannot be dynamically enlarged and we need to deal with dynamic memory management.

`cstrings` are character arrays terminated with a single null-character written as the escape sequence `'\0'.`

The C++ Standard Template Library (STL) offers containers (a.k.a. abstract data types, ADTs) to replace C-style arrays. The basic idea is to use

* templated containers with a consistent interface (see https://en.cppreference.com/w/cpp/container),
* iterators to work on sequences of values,
* generic algorithms (like sorting), and
* functors (to perform operations on all elements).

Details can be found at:
https://www.geeksforgeeks.org/the-c-standard-template-library-stl/

**Important Note:** Use STL containers whenever possible!

Example: [Arrays vs STL vectors and strings](main.cpp)