#include <iostream>
#include "IntCell.h"

/* Remember: <...> is a standard library and "..." is a header in the 
 * project (current directory). */

using namespace std;

int main(int, char **)
{
    int unused; // produces a warning
    
    IntCell test = IntCell();
    cout << test.read() << endl;

    test.write(12);
    cout << test.read() << endl;

    return 0;
}
