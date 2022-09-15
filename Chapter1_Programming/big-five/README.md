# Rule of Three (Becomes in C++11 the Big Five)

## The rule of Three

The [Rule of three](https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)#:~:text=The%20rule%20of%20three%20(also,copy%20assignment%20operator) states that all classes need a default constructor and

 1. Destructor
 2. Copy constructor
 3. copy assignment operator `operator=` 

Typically, the default behavior provided by C++ works. **Exception:** If a member variable contains a pointer (i.e., we use dynamic memory allocation with `new`/`delete`) then we need 
to provide custom destructors, constructors and operators 
need to be overloaded. See [operator overloading](https://en.cppreference.com/w/cpp/language/operators).

## 4 and 5 of the Big Five

C++11 adds as 4 and 5 a move constructor and a move assignment operator which 
use [move semantics](https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html) to avoid needless copying large temporary objects
when they are returned from functions.

* This is done with overloading the constructor and `operator=` with parameters of the new reference type called _rvalue reference_ which is denoted
by `datatype &&`. lvalue means a storage location (e.g., a variable) and
rvalue means a temporary value that gets lost if it is not assigned to a variable (e.g., 
the result of an evaluation or a return value).
* They are only useful if the class uses dynamic memory allocation. 
* If they are missing then the regular copy versions are used.

We will mostly skip the move versions in the code example to make the code shorter, but for production C++11 code, you should add them.

## Examples

(main.cpp)[main.cpp] uses the following classes and shows how to detect problems with the big 5:

* [IntCell](IntCell.h) uses **no** dynamic memory allocation so we do not implement the big 5.
* [IntCellPtr](IntCellPtr.h) does use **dynamic memory allocation** for the stored `int` (unnecessarily, but to show what happens) so we have to implement the big 5. Unfortunately, the programmer forgot to add a destructor and overload the assignment operator which leads to problems. Use `valgrind` or the `AddressSanitizer` library to identify the issue.
* [IntCellPtrOK](IntCellPtrOK.h) correctly adds the destructor and the assignment operator.

See how to debug and how to detect memory leaks on the [HOWTO page](../../HOWTOs.md).
