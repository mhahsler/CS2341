# Recursion

[Recursion](https://en.wikipedia.org/wiki/Recursion) appears when a problem can be defined in terms of 
a simpler version of itself.

**Example:** The factorial of an integer $n$
is the product of all positive integers less than or equal to $n$.
That is:

$$n! = n (n-1) (n-2) \dots 1 = \prod_{i=1}^n i \ \text{for} \ n > 0$$

By convention: $0! = 1$.

From the definition we see that $n! = n (n-1)!$


Recursion needs:
1. A base known case.
2. A recursive definition.
3. Convergence to the base case.

For the factorial problem we have (see [factorial.cpp](factorial.cpp)):
1. Base case:  $0! = 1$ (we can also use $1! = 1$)
2. Recursive definition: $n! = n (n-1)!$
3. Convergence: n is reduced by one in every step so we will converge to a base case with n = 1

**Notes:** 

* Recursion is **slower than iteration** and stack frames **need additional memory** 
  to store return addresses. You may run out of stack memory if the recursion is too deep. 
* The use of recursion is supposed to create 
  **shorter and simpler code** that can also be **more efficient** (meaning that we save some computation). Typical applications are [divide-and-conquer algorithms](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm). Examples are search in a binary search tree (we will talk about this later) and [dynamic programming]().
* Using recursion instead of simple iteration like calculating the factorial
  is **not a good idea** since the function call stack is much slower than a loop and needs extra memory! A better implementation is in [factorial_iterative_main.cpp](factorial_iterative_main.cpp).
* A recursion can be translated into an iteration and vice versa.


# Testing

I have placed the function `factorial` into its own file and added a header, so I can use it in multiple 
executables (`factorial_main` and `factorial_test`).

Algorithms need tests. We use `ctest` and `Catch2` library. Details on writing tests and how to setup `CMakeLists.txt` can be found in the [HOWTO Test.](../../HOWTO_test.md)

Note: compiling Catch2 is very slow. You can build instead of `[all]` 
just the executable that you are working on to speed up your development cycle.
