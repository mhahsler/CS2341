#include <iostream>
#include "IntCellPtr.h"

using namespace std;

// Big-five Example
// Run with debugger: Set breakpoint to the first line of main() and watch the variables.

// NOTE: This implementation is broken and has a Memory leak!!!

int main()
{
    /* IntCellPtr. Defaults do not work because of dynamic memory allocation */

    IntCellPtr A(10);

    IntCellPtr B = A; // uses implicit copy constructor (only copies the pointers!)

    A.write(20);

    B = A; // uses implicit operator= (only copies the pointers!)


    /* the pointer gets copied: we need a copy constructor and a copy assignment. Also, there is a new but no
       delete (destructor is missing) so we have a memory leak!

       You can activate the AddressSanitizer library in CMakeLists.txt (and run the program) or
       run valgrind in the VS Code terminal to detect memory leaks: 
       > valgrind --leak-check=full --track-origins=yes ./test_IntCellPtr
       
       valgrind says: 
       
            ==25904== Memcheck, a memory error detector
            ==25904== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
            ==25904== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
            ==25904== Command: ./test_IntCellPtr
            ==25904==
...
            ==25904== HEAP SUMMARY:
            ==25904==     in use at exit: 8 bytes in 2 blocks
            ==25904==   total heap usage: 3 allocs, 1 frees, 73,736 bytes allocated
            ==25904== 
            ==25904== 4 bytes in 1 blocks are definitely lost in loss record 1 of 2
            ==25904==    at 0x4C2A593: operator new(unsigned long) (vg_replace_malloc.c:344)
            ==25904==    by 0x4008EE: IntCellPtr::IntCellPtr(int) (in /users4/csefac/mhahsler/CS2341/Chapter1_Programming/big-five/build/test_IntCellPtr)
            ==25904==    by 0x40088A: main (in /users4/csefac/mhahsler/CS2341/Chapter1_Programming/big-five/build/test_IntCellPtr)
            ==25904== 
            ==25904== 4 bytes in 1 blocks are definitely lost in loss record 2 of 2
            ==25904==    at 0x4C2A593: operator new(unsigned long) (vg_replace_malloc.c:344)
            ==25904==    by 0x4008EE: IntCellPtr::IntCellPtr(int) (in /users4/csefac/mhahsler/CS2341/Chapter1_Programming/big-five/build/test_IntCellPtr)
            ==25904==    by 0x4008B4: main (in /users4/csefac/mhahsler/CS2341/Chapter1_Programming/big-five/build/test_IntCellPtr)
            ==25904== 
            ==25904== LEAK SUMMARY:
            ==25904==    definitely lost: 8 bytes in 2 blocks
            ==25904==    indirectly lost: 0 bytes in 0 blocks
            ==25904==      possibly lost: 0 bytes in 0 blocks
            ==25904==    still reachable: 0 bytes in 0 blocks
            ==25904==         suppressed: 0 bytes in 0 blocks
            ==25904== 
            ==25904== For lists of detected and suppressed errors, rerun with: -s
            ==25904== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
       */

        return 0;

}
