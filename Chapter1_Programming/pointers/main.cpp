#include <iostream>
#include "IntCell.h"

using namespace std;

int main()
{
    // We can statically allocate a IntCell object on the stack.
    IntCell m_stack(3);
    cout << "Cell m_stack: " << m_stack.read() << "\n";
    
    // We dynamically allocate a IntCell object
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

    /* comparison does not work as expected, it compares the pointers */
    if (m == n)
        cout << "m == n" << "\n";
    else
        cout << "m != n" << "\n";


    /* addresses and dereferencing */
    cout << "m: " << m << "\n";
    cout << "Address of m (&m): " << &m << "\n";
    cout << "Dereferenced m ( *m.read() ): " << (*m).read() << "\n";

    /* this works */
    if (m->read() == n->read())
        cout << "m->read() == n->read()" << "\n";
    else
        cout << "m->read() != n->read()" << "\n";

    /* every new needs a delete! */
    delete m, n;

    //  References (lvalue references)
    // & used in a declaration (not as an operator like above!!!)
    // used as an alias (avoid copying memory, e.g., for a function call)
    // `auto` can be used. The compiler figures out the data type.
    int a = 12;
    auto &b = a;

    if (&a == &b)
        cout << "a and b occupy the same memory!" << "\n";

    b = 24;
    cout << "a: " << a << "\n";

    return 0;
}