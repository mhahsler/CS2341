# Rule of Three (Becomes in C++11 the Big-Five)

All classes need a default constructor and

 1. Destructor
 2. Copy constructor
 3. copy assignment operator `operator=` 

C++11 adds as 4 and 5 a move constructor and a move assignment operator which 
use [move semantics](https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html) to avoid needless copying large temporary objects
when they are returned from functions.
This is done with overloadinf the constructor and `operator=` with parameters of the new reference type called _rvalue reference_ which is denoted
by `dataype &&`.

Typically, the default big five provided by C++ works.

**Exception:** If a member variable contains a pointer (i.e., we use dynamic memory allocation with new/delete), destructor, constructors and operators 
need to be overloaded. See [operator overloading](https://en.cppreference.com/w/cpp/language/operators).
