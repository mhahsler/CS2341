#include <iostream>
#include "IntCell.h"
/* Remember: <...> is a standard library and "..." is a header in the 
 * project (current directory). */

// Write the main function first and then write the class. The main function should test the class.
int main()
{
    
    IntCell test = IntCell{5};
    // C++11 can use {} for construction
    // It is the same as IntCell test = IntCell(5);
    std::cout << test.read() << "\n"; // std::endl flushes the buffer and is slow so use it sparingly

    // prevented by explicit constructor with single int argument.
    // test = 12;

    test.write(12);
    std::cout << test.read() << "\n";

    return 0; // 0 signals to the Operating System that the program ran successfully
}
