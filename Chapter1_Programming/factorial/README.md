# Recursion

The factorial of an integer $n$
is the product of all positive integers less than or equal to $n$.
That is:

$$n! = n (n-1) (n-2) \dots 1 = \prod_{i=1}^n i \ \text{for} \ n > 0$$

By convention: $0! = 1$.


Recursion (see [factorial.cpp](factorial.cpp)) needs

* A base case: $0! = 1$.
* And a recursive call that works towards the base case.

**Notes:** 

* A recursion can be translated into an iteration and vice versa. 
* Recursion is slower than iteration. Stack frames need additional memory 
  to store return addresses. You may run out of stack memory if the recursion is too deep. 
* The use of recursion is supposed to create 
  shorter and simpler code that can also be more efficient.
* Using recursion instead of simple iteration like calculating the factorial
  is not a good idea since the function call stack is slow and needs memory! A better implementation is [iterative.cpp](iterative.cpp).

  # Testing

  I have placed the function into its own file and added a header, so I can use it in multiple 
  executables (`main` and `test`).

  Algorithms need tests. We use `ctest` and `Catch2` library. Details on writing tests and how to setup `CMakeLists.txt` can be found in the [HOWTOs.](../HOWTOs.md)


