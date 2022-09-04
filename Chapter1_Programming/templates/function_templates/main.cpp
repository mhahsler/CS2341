#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for max_element

#include "IntCell.h"

using namespace std;

// Template function example

// Figures 1.19 and 1.20, but with illegal lines commented out

/**
 * Return the maximum item in array a.
 * Assumes a.size( ) > 0 
 * The objects must provide operator< and operator=
 */
template <typename Comparable>
const Comparable & findMax( const vector<Comparable> & a )
{
    int maxIndex = 0;

    for( int i = 1; i < a.size( ); ++i )
        if( a[ maxIndex ] < a[ i ] )
            maxIndex = i;
    
    return a[ maxIndex ];
}

int main( )
{
    vector<int>     v1 = { 3, 5, 8, 2, 4 };
    vector<double>  v2 = { 2.9, 5.4, 2.1, 3.3 };
    vector<string>  v3 = { "hello", "world", "apple" };
    vector<IntCell> v4( 75 );

    // Additional code to fill in the vectors
    cout << "Templated findMax() function\n"; 
    cout << findMax( v1 ) << endl;  // OK: Comparable = int
    cout << findMax( v2 ) << endl;  // OK: Comparable = double
    cout << findMax( v3 ) << endl;  // OK: Comparable = string
//    cout << findMax( v4 ).read() << endl;  // Illegal; operator< undefined for IntCell
// compiler error!
// [build] main.cpp: In instantiation of ‘const Comparable& findMax(const std::vector<Comparable>&) [with Comparable = IntCell]’:
// [build] main.cpp:43:20:   required from here
// [build] main.cpp:25:27: error: no match for ‘operator<’
//
// See Section Comparator on how to fix this by adding an `operator<` to your class.



    // by the way, the STL already provides https://en.cppreference.com/w/cpp/algorithm/max_element
    cout << "\nSTL max_element()\n"; 
    cout << *max_element(v1.begin(), v1.end()) << endl;
    cout << *max_element(v2.begin(), v2.end()) << endl;
    cout << *max_element(v3.begin(), v3.end()) << endl;

    return 0;
}