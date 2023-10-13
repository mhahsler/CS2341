# Recursion

[Recursion](https://en.wikipedia.org/wiki/Recursion) appears when a problem can be defined in terms of 
a simpler version of itself.

## Example: Computation of the Factorial of a Number

The factorial of an integer $n$
is the product of all positive integers less than or equal to $n$.
That is:

$$n! = n (n-1) (n-2) \dots 1 = \prod_{i=1}^n i \ \text{for} \ n > 0$$

By convention: $0! = 1$.

From the definition we see that $n! = n (n-1)!$

[Factorial](https://en.wikipedia.org/wiki/Factorial) is used in many areas of mathematics. In combinatorics it gives the number of permutations (different arrangements) of $n$ elements. For example the time complexity class $O(n!)$ is typical for solving 
hard combinatorial problems like the [traveling salesman problem](https://en.wikipedia.org/wiki/Travelling_salesman_problem). 


**Recursive Formulation**

Recursion needs:
1. A known base case.
2. A recursive definition.
3. Convergence to the base case.

For the factorial problem we have (see [factorial.cpp](factorial.cpp)):
1. Base case:  $0! = 1$ and we also know that $1! = 1$
2. Recursive definition: $n! = n (n-1)!$
3. Convergence: $n$ is reduced by one in every step so we will converge to a base case with $n = 1$.

**Notes:** 

* Recursion uses the **function call stack** as a stack data structure. 
  It is **slower than iteration** and stack frames **need additional memory** 
  to store return addresses. You may run out of stack memory if the recursion is too deep. 
* The use of recursion is supposed to create 
    - **shorter and simpler code** that can also be 
    - **more efficient** (meaning that we save some computation). 
   
   Typical applications are [divide-and-conquer algorithms](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm). Examples are search in a binary search tree (we will talk about this later) and [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming).
* Using recursion where simple iteration is sufficient (e.g., for calculating the factorial) 
  is **not a good idea** since the function call stack is much slower than a loop and needs extra memory! A better implementation is in [factorial_iterative_main.cpp](factorial_iterative_main.cpp).
* Many functions have good approximations that do not require iteration at all. E.g., factorial can be approximated for large $n$ using the Stirling's approximation $n! \sim \sqrt{2 \pi n} \left(\frac{n}{e}\right)^n$. 


# Testing

Algorithms need tests. I have placed the function `factorial` into its own file and added a header, so I can use it in multiple 
executables. There are two versions of tests here:

* `factorial_test_main` using a simple main function and the tests are checked with `if` statements.
* `factorial_test_catch` contains tests using the `Catch2` library. 

You only need one version of tests!

Details on writing tests and how to setup `CMakeLists.txt` can be found in the [HOWTO Test.](../../HOWTO_test.md)

Note: compiling Catch2 is very slow. You can build instead of `[all]` 
just the executable that you are working on to speed up your development cycle.
