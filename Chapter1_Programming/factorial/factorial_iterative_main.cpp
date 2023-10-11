#include <iostream>
#include <cmath>

// factorials get large very quickly, so we need to use a data type that can hold large numbers.
// since negative numbers would be a problem and -1 would just be converted to a very large unsigned int for number,
// we use int and check it for negativity instead.

// compared to the recursive implementation, this code is faster, needs less memory and is only slightly more complex.

double factorial_iterative(int number)
{
    if (number < 0)
        throw std::runtime_error("factorial is not defined for negative numbers!");

    double fac = 1;
    for (auto i = number; i > 1; --i)
        fac *= i;

    return fac;
}

// Stirling's approximation for large numbers
double factorial_approx(int number) {
    return (sqrt(2 * M_PI * number) * pow(number / M_E, number));
}

int main()
{

    // some calls may throw an exception
    try
    {
        std::cout << "0! = " << factorial_iterative(0) << "\n";
        std::cout << "1! = " << factorial_iterative(1) << "\n";
        std::cout << "5! = " << factorial_iterative(5) << "\n";
        std::cout << "100! = " << factorial_iterative(100) << "\n";
        
        // Note: the approximation is not very good for small numbers!
        std::cout << "0! ~ " << factorial_approx(0) << "\n";
        std::cout << "1! ~ " << factorial_approx(1) << "\n";
        std::cout << "5! ~ " << factorial_approx(5) << "\n";
        std::cout << "100! ~ " << factorial_approx(100) << "\n";
        
        
        std::cout << "(-1)! = " << factorial_iterative(-1) << "\n";


    }
    catch (std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
