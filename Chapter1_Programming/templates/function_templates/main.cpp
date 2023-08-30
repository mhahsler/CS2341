#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for max_element

#include "IntCell.h"

// Template function example

// Figures 1.19 and 1.20, but with illegal lines commented out

/**
 * Return the maximum item in array a.
 * Assumes a.size( ) > 0 
 * The objects must provide operator< and operator=
 * 
 * This is a template function which means that it only exists
 * if the compiler finds a call to the function an then write code
 * for the data type used in that call.
 */
template <typename Comparable>
const Comparable & findMax( const std::vector<Comparable> & a )
{
    int maxIndex = 0;

    for( int i = 1; i < a.size( ); ++i )
        if( a[ maxIndex ] < a[ i ] )
            maxIndex = i;
    
    return a[ maxIndex ];
}

int main( )
{
    std::vector<int>     v1 = { 3, 5, 8, 2, 4 };
    std::vector<double>  v2 = { 2.9, 5.4, 2.1, 3.3 };
    std::vector<std::string>  v3 = { "hello", "world", "apple" };
    std::vector<IntCell> v4(10);  // create a vector with 10 IntCells, we did not implement list initialization for IntCell.

    // the compiler will analyze the calls below, determine the type of the argument, and then
    // generate multiple version of the template function with each needed type. 
    std::cout << "Templated findMax() function\n"; 
    std::cout << findMax(v1) << "\n";  // OK: Comparable = int
    std::cout << findMax(v2) << "\n";  // OK: Comparable = double
    std::cout << findMax(v3) << std::endl;  // OK: Comparable = string
//    std::cout << findMax(v4).read() << std::endl;  // Illegal; operator< undefined for IntCell
// compiler error!
// [build] main.cpp: In instantiation of ‘const Comparable& findMax(const std::vector<Comparable>&) [with Comparable = IntCell]’:
// [build] main.cpp:43:20:   required from here
// [build] main.cpp:25:27: error: no match for ‘operator<’
//
// See Section Comparator on how to fix this by adding an `operator<` to your class.


    // we can call the function as findMax<int>(v1) to force the compiler to use int in the template 

    // by the way, the STL already provides https://en.cppreference.com/w/cpp/algorithm/max_element
    std::cout << "\nSTL max_element()\n"; 
    std::cout << *max_element(v1.begin(), v1.end()) << "\n";
    std::cout << *max_element(v2.begin(), v2.end()) << "\n";
    std::cout << *max_element(v3.begin(), v3.end()) << std::endl;

    return 0;
}