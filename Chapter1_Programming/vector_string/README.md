# Arrays and cstrings vs STL vectors and strings

Example: [Arrays vs STL vectors and strings](main.cpp)

## C-style Arrays
C-style arrays are just pointers to memory (first element of the array).

C-style arrays have several drawbacks:

1. If we do not know the array size at compile time, then we need to use 
   dynamic memory allocation and pointers. 
2. Arrays cannot be assigned with `=` or compared with `==` (they are pointers to the first elements).
3. Arrays do not know its length (at least not consistently).
4. Arrays cannot be dynamically enlarged and we need to deal with dynamic memory management.

`cstrings` are character arrays terminated with a single null-character written as the escape sequence `'\0'.`


## STL Containers
The C++ Standard Template Library (STL) offers containers (a.k.a. abstract data types, ADTs) to replace C-style arrays and strings. The basic idea is to use

* templated containers with a consistent interface (see https://en.cppreference.com/w/cpp/container),
* iterators to work on sequences of values,
* generic algorithms (like sorting), and
* functors (to perform operations on all elements).

STL containers handle most of the memory management for us and make programming simpler and less error-prone.
Details can be found at:
https://www.geeksforgeeks.org/the-c-standard-template-library-stl/

**Important Note:** Use STL containers whenever possible!
A good replacement for arrays is [std::vector](https://en.cppreference.com/w/cpp/container/vector),
and for `char *` use [std::string](https://en.cppreference.com/w/cpp/string/basic_string).

**A note on indices:** 64-bit systems can handle data structures with so many elements that `int` cannot represent the 
index. Since it is an signed datatype, it will eventually overflow produce a negative index and break your program. The STL introduces two new datatypes that are guaranteed to be able to represent all possible index values. These are:

* `std::size_t` for an index. It is unsigned and can only be positive.
* `std::ptrdiff_t` for the difference between indices (or pointers). Can be positive and negative.

You should use these two datatypes consistently instead of `int`.

Example: [Indexing problem](index_problem.cpp)
