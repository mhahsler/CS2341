#include <iostream>
#include "factorial.h"

int main() {

    std::cout << "5! = " << factorial(5) << "\n";
    // run with debugger to see the function call stack

    std::cout << "0! = " << factorial(0) << "\n";
    
    // issues with the implementation:
    // 1. moderately large numbers are a problem
    
    unsigned int f = factorial(100);
    std::cout << "100! = " << f << "\n";
    // this fails!
    // unsigned int (32 bit) can represent [0 to 4294967295]!
    // we could use unsigned long long or even better a double.

    // 2. negative numbers are a problem
    //f = factorial(-1);
    //std::cout << "(-1)! = " << f << "\n";

    // the issue is that negative numbers will translate into
    // very large numbers when converted to unsigned int
    // f = -1;
    // std::cout << "-1 as an unsigned int is " << f << "\n";

    return 0;
}
