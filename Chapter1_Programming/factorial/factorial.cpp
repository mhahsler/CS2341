unsigned int Factorial(unsigned int number)
{
    // base case: 0! = 1 
    // but also 1! = 1 and the unsigned data type makes sure we have no negative numbers
    if (number <= 1) 
    return 1;
    
    // recursive call
    return Factorial(number - 1) * number;
}