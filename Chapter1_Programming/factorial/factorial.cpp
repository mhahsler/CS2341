#include "factorial.h"

unsigned int factorial(unsigned int number)
{
    // base case: 0! = 1 
    // but also 1! = 1 and the unsigned data type makes sure we have no negative numbers
    if (number <= 1) 
      return 1;
    
    // recursive call that converges to the base case
    return factorial(number - 1) * number;
}
