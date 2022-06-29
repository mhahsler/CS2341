# Arrays and cstrings vs STL vectors and strings

C-style arrays are just pointers to memory (first element of the array).

C-style arrays have several drawbacks:

1. Arrays cannot be assigned with = (they are pointers)
2. Arrays do not know its length (at least not consistently).
3. Arrays cannot be dynamically enlarged.

cstrings are character arrays terminated with `'\0'.`

The C++ Standard Template Library offers containers (a.k.a. abstract data types ADT) to replace C-style arrays. The basic idea is to use

* templated containers with a consistent interface (see https://en.cppreference.com/w/cpp/container)
* iterators to work on sequences of values
* algorithms (like sorting)
* functors (to perform operations on all elements)

Details can be found at:
https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
