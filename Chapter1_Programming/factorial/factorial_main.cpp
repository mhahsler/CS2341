#include <iostream>
#include "factorial.h"

int main() {

    std::cout << "5! = " << Factorial(5) << "\n";
    // run with debugger to see the function call stack

    std::cout << "0! = " << Factorial(0) << "\n";
    
    unsigned int f = Factorial(100);
    std::cout << "100! = " << f << "\n";
    // this fails!
    // unsigned int (32 bit) can represent [0 to 4294967295]!
    // we could use unsigned long long or even better a double.

    return 0;
}
