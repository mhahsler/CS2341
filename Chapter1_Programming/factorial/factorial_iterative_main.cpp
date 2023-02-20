#include <iostream>

double factorial_iterative(int number)
{
    if (number < 0) {
        std::cerr << "factorial is not defined for negative numbers!" << "\n";
        return -1;
    }
    
    double fac = 1;
    for (auto i = number; i > 1; --i)
        fac *= i;
    
    return fac;
}

int main() {

    std::cout << "5! = " << factorial_iterative(5) << "\n";
    std::cout << "0! = " << factorial_iterative(0) << "\n";  
    std::cout << "100! = " << factorial_iterative(100) << "\n";
    std::cout << "(-1)! = " << factorial_iterative(-1) << "\n";

    return 0;
}
