#include <iostream>
#include "IntCellPtrOK.h"

using namespace std;

// Big-five Example

// Run with debugger: Set breakpoint to the first line of main() and watch the variables.

int main()
{

    /* IntCellPtrOK has a destructor, a copy constructor and an operator= */

    IntCellPtrOK A(10);

    IntCellPtrOK B = A; // uses our copy constructor (allocates memory to copy the stored value)

    A.write(20);

    B = A; // uses implicit operator= (allocates memory to copy the stored value)

    return 0;

    /*
    run valgrind in the VS Code terminal to detect memory leaks: 
    > valgrind --leak-check=full --track-origins=yes ./test_IntCellPtrOK
       
       valgrind says: 
        ...
        ==27246== HEAP SUMMARY:
        ==27246==     in use at exit: 0 bytes in 0 blocks
        ==27246==   total heap usage: 4 allocs, 4 frees, 73,740 bytes allocated
        ==27246== 
        ==27246== All heap blocks were freed -- no leaks are possible
        ==27246== 
        ==27246== For lists of detected and suppressed errors, rerun with: -s
        ==27246== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


    */
}
