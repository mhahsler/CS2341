#include <iostream>
#include "factorial.h"

// this main function is used to test the factorial function

int main() {

    std::cout << "5! = " << factorial(5) << "\n";
    // run with debugger to see the function call stack

    // test
    if (factorial(5) != 120)
        std::cerr << "** 5! failed" << "\n";

    std::cout << "0! = " << factorial(0) << "\n";
    
    // test
    if (factorial(0) != 1)
        std::cerr << "** 0! failed" << "\n";

    // issues with the implementation:
    // 1. moderately large numbers are a problem
    
    std::cout << "100! = " << factorial(100) << "\n";
    // this fails!
    // unsigned int (32 bit) can represent [0 to 4294967295]!
    // we could use unsigned long long or even better a double.
    // Also, why does it return 0???
    
    if (factorial(100) != 9.332622e+157)
        std::cerr << "** 100! failed" << "\n";

    // 2. negative numbers are a problem
    std::cout << "(-1)! = " << factorial(-1) << "\n";

    // what should it return?
    //if (factorial(-1) > ???)
    //    std::cerr << "** -1! failed" << "\n";

    // the issue is that negative numbers will translate into
    // very large numbers when converted to unsigned int (e.g., as the 
    // argument of the factorial function). Note how long the program runs!
    
    // here is what happens to -1 when converted to unsigned int
    std::cout << "int -1 as an unsigned int is " << (unsigned int) -1 << "\n";

    return 0;
}
