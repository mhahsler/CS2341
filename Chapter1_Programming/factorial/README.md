# Recursion

The factorial of an integer $n$ is defined as:

$n! = n (n-1) (n-2) \dots 1$


Recursion needs

* A base case: $1! = 1$
* And a recursive call that works towards the base case.


**Notes:** 

* A recursion can be translated into an iteration and vice versa. 
* Recursion is slower than iteration and stack frames need to store return addresses. 
  The use of recursion is supposed to create 
  shorter and simpler code that can also be more efficient.
* Using recursion instead of simple iteration like calculating the factorial
  is not a good idea since the function call stack is slow and needs memory! A better implementation is [iterative.cpp](iterative.cpp).

