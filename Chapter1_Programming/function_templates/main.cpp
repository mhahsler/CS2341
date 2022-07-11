#include <iostream>
#include <string>
#include <vector>
//#include "IntCell.h"

using namespace std;


/*
 * Templates let us define algorithms that are type independent.
 * 
 * Function templates define a pattern. The typename is just a placeholder for the 
 * actual type and the compiler will compile all needed versions
 * of the function (can lead to code bloat).
 * 
 
 * 
 * Note: 
 * * Always assume that the type is not a primitive type (this is why findMax returns a const reference).
 * * IntCell does not have operator< implemented and compilation fails.
 * * Template function matching can be ambiguous which will lead to a compilation error.
 */


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
//          vector<IntCell> v4( 75 );

    // Additional code to fill in the vectors

    cout << findMax( v1 ) << endl;  // OK: Comparable = int
    cout << findMax( v2 ) << endl;  // OK: Comparable = double
    cout << findMax( v3 ) << endl;  // OK: Comparable = string
//          cout << findMax( v4 ) << endl;  // Illegal; operator< undefined

    return 0;
}