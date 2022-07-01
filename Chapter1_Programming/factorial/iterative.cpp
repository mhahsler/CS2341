#include <iostream>

using namespace std;

unsigned int Factorial(unsigned int number)
// double Factorial(unsigned int number)
{
    unsigned int fac = 1;
    // double fac = 1;
    for (unsigned int i = number; i > 1; --i)
        fac *= i;
    
    return fac;
}

int main() {

    cout << "5! = " << Factorial(5) << endl;
    // run with debugger

    cout << "0! = " << Factorial(0) << endl;
    
    cout << "100! = " << Factorial(100) << endl;
    // run with debugger to see the issue
    // unsigned int (32 bit) can represent [0 to 4294967295]!
    // we could use unsigned long long or a double.

    return 0;
}
