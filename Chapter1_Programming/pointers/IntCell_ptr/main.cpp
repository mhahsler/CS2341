#include <iostream>
#include "IntCell.h"

using namespace std;

int main()
{
    // We can statically allocate a IntCell object on the stack.
    cout << "\nStatic Memory Allocation:\n";
    IntCell m_stack(3);
    cout << "Cell m_stack: " << m_stack.read() << "\n";
    
    // We dynamically allocate a IntCell object
    cout << "\nDynamic Memory Allocation:\n";
    // Note that this is not necessary, since we know at compile time how much memory we have!
    // To allocate the memory on the stack, we would use:
    // IntCell m{0}; 
    // and there would be no need for a delete.
    
    IntCell *m;
    m = new IntCell{0};
    m->write(5);

    cout << "Cell m: " << m->read() << "\n";

    IntCell *n = new IntCell{5};
    cout << "Cell n: " << n->read() << "\n";

    /* comparison does not work as expected, it compares the pointers/addresses */
    if (m == n)
        cout << "m == n" << "\n";
    else
        cout << "m != n" << "\n";


    /* addresses and dereferencing */
    cout << "m: " << m << "\n";
    cout << "n: " << n << "\n";
    cout << "Value of m ( m->read() ): " << m->read() << "\n";
    cout << "Value of m using the dereferencing operator ( (*m).read() ): " << (*m).read() << "\n";

    /* this works for comparing*/
    if (m->read() == n->read())
        cout << "m->read() == n->read()" << "\n";
    else
        cout << "m->read() != n->read()" << "\n";

    /* every new needs a delete! It is good practice to set the pointers to nullptr after the delete. */
    delete m;
    delete n;
    n = nullptr;
    m = nullptr;
    
    //  References (lvalue references)
    // & used in a declaration (not as an operator like above!!!)
    // used as an alias (avoid copying memory, e.g., for a function call)
    // `auto` can be used. The compiler figures out the data type.
    int a = 12;
    auto &b = a;

    if (&a == &b)
        cout << "a and b occupy the same memory: " << &a << "\n";

    b = 24;
    cout << "a: " << a << "\n";

    // Pointer Arithmetic: Arrays and Pointers
    cout << "\nPointers and Arrays:\n";
    IntCell arr[] = {IntCell{100}, IntCell{101}, IntCell{102}, IntCell{103}, IntCell{104}};
    // we could also dynamically allocate the array on the heap:
    // IntCell *arr = new IntCell[5];


    cout << "arr[2].read(): " << arr[2].read() << "\n";
    cout << "(arr + 2)->read(): " << (arr + 2)->read() << "\n";
    cout << "(*(arr + 2)).read(): " << (*(arr + 2)).read() << "\n";

    IntCell* arr_ptr = arr; // array name can be used to get a pointer to the first element

    arr_ptr += 2; // move two positions forward
    cout << "arr_ptr (after +2): " << arr_ptr->read() << "\n";

    --arr_ptr; // move one positions back
    cout << "arr_ptr (after -1): " << arr_ptr->read() << "\n";

    return 0;
}