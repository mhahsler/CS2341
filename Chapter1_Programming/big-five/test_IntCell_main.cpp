#include <iostream>
#include "IntCell.h"

using namespace std;

// Run with debugger: Set breakpoint to the first line of main() and watch the variables.

int main()
{
    /* Regular IntCell. Defaults work as expected */
    IntCell A(10);

    IntCell B = A; // uses implicit copy constructor (copy all member variables)

    A.write(20);

    B = A; // uses operator= (copy all member variables)

    return 0;
}
