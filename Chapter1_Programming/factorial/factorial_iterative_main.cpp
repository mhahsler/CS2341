#include <iostream>

// factorials get large very quickly, so we need to use a data type that can hold large numbers.
// since negative numbers would be a problem and -1 would just be converted to a very large unsigned int for number,
// we use int and check it for negativity instead.

// compared to the iterative implementation, this code faster, needs less memory and is only slightly more complex.

double factorial_iterative(int number)
{
    if (number < 0)
        throw std::runtime_error("factorial is not defined for negative numbers!");
    
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
