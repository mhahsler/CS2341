unsigned int Factorial(unsigned int number)
{
    // base case
    if (number <= 1) 
    return 1;
    
    // recursive call
    return Factorial(number - 1) * number;
}