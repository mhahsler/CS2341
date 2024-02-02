# Rule of Three (Becomes in C++11 the Big Five)

## The Rule of Three

The [Rule of three](https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)) states that all classes need a **default constructor** and the following:
 
 1. A copy constructor `Class(const Class& rhs);`
 2. A copy assignment operator `Class& operator= (const Class& rhs);` 
 3. A destructor `~Class();`

 *Important note:* You also need to provide a custom **default constructor** that allocates the memory for a valid object! The default constructor automatically provided by C++ will not work and create memory issues. 

C++ provides these functions with default behavior (it produces a "shallow copy", i.e., it copy all class member variables) automatically. The default behavior works **unless a member variable contains a pointer**, i.e., the class used dynamic memory allocation with `new`/`delete`. In this case, we need 
to provide overloads with custom constructors, an assignment operator and a destructor to create a "deep copy", i.e., also copy the memory pointed to.

Read more on [operator overloading](https://en.cppreference.com/w/cpp/language/operators).

## The Big Five

C++11 adds [move semantics](https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html) to avoid needless copying large temporary objects when they are returned from a function (e.g., taken from an STL container). Move semantics are implemented using a new reference type called _rvalue reference_ which is denoted
by `datatype &&`. Typical C++ assignments are done by: 

```cpp
lvalue = rvalue;
``` 

lvalue has to be a storage location (e.g., a variable) and
rvalue is a temporary value (e.g., the result of an evaluation or a return value) that would get lost if it is not assigned to a variable.

To implement move semantics in a class, we need to provide the following overloads (4 and 5 in the Big Five):

4. A move constructor `Class(const Class&& rhs);`
5. A move assignment operator `Class& operator= (const Class&& rhs);`
 
The compiler determines if something is a rvalue and can be moved without copying. It then uses the move functions automatically. If they are missing then the regular copy versions are used instead.
Implementing move semantics for a class is only useful if the class uses dynamic memory allocation and
copying the allocated memory would be a significant issue (time or memory).

In this course we will mostly skip the move versions in the code example to make the code shorter, but for production C++11 code, you should always consider adding them in your classes. Especially when you intend to store objects of your class in
STL containers.

## Examples

(main.cpp)[main.cpp] uses the following classes and shows how to detect problems with the big 5:

* IntCell ([IntCell.h](IntCell.h), [IntCell.cpp](IntCell.cpp)) uses **no** dynamic memory allocation so we do not implement the big 5.
* IntCellPtr ([IntCellPtr.h](IntCellPtr.h), [IntCellPtr.cpp](IntCellPtr.cpp)) does use **dynamic memory allocation** for the stored `int` (unnecessarily, but to show what happens) so we have to implement the big 5. Unfortunately, the programmer forgot to add a destructor and overload the assignment operator which leads to problems. Use `valgrind` or the `AddressSanitizer` library to identify the issue.
* IntCellPtrOK: ([IntCellPtrOK.h](IntCellPtrOK.h), [IntCellPtrOK.cpp](IntCellPtrOK.cpp)) correctly adds the destructor and the assignment operator.

See how to detect memory leaks on the [HOWTO page](../../HOWTO_detect_memory_leaks.md).
