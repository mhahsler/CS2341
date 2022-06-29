unsigned int Factorial(unsigned int number)
{
    // base case
    if (number <= 1) 
    return 1;
    
    // 
    return Factorial(number - 1) * number;
}