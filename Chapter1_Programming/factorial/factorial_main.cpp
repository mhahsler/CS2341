#include <iostream>
#include "factorial.h"

using namespace std;


int main() {

    cout << "5! = " << Factorial(5) << "\n";
    // run with debugger to see the function call stack

    cout << "0! = " << Factorial(0) << "\n";
    
    cout << "100! = " << Factorial(100) << "\n";
    // this fails!
    // unsigned int (32 bit) can represent [0 to 4294967295]!
    // we could use unsigned long long or a double.

    return 0;
}
