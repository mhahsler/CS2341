#include <iostream>
#include "IntCell.h"

/* Remember: <...> is a standard library and "..." is a header in the 
 * project (current directory). */

using namespace std;

int main(int, char **)
{
    int unused; // produces a warning if -Wall is used in CMakeLists
    
    IntCell test = IntCell{5};
    // C++11 can use {} for construction
    // IntCell test = IntCell();
    cout << test.read() << endl;

    // prevented by explicit constructor with single int argument.
    // test = 12;

    test.write(12);
    cout << test.read() << endl;

    return 0;
}
