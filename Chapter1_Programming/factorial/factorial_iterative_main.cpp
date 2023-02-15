#include <iostream>

double Factorial(unsigned int number)
{
    double fac = 1;
    for (auto i = number; i > 1; --i)
        fac *= i;
    
    return fac;
}

int main() {

    std::cout << "5! = " << Factorial(5) << "\n";
    std::cout << "0! = " << Factorial(0) << "\n";  
    std::cout << "100! = " << Factorial(100) << "\n";

    return 0;
}
