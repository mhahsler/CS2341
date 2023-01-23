#include <iostream>
#include "IntCell.h"

/* Remember: <...> is a standard library and "..." is a header in the 
 * project (current directory). */

using namespace std;

int main()
{
    
    IntCell test = IntCell{5};
    // C++11 can use {} for construction
    // IntCell test = IntCell(5);
    cout << test.read() << "\n";

    // prevented by explicit constructor with single int argument.
    // test = 12;

    test.write(12);
    cout << test.read() << "\n";

    return 0;
}
