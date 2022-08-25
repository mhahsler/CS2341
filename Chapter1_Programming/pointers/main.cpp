#include <iostream>
#include "IntCell.h"

using namespace std;

int main()
{
    // We dynamically allocate a IntCell object
    // Note that this is not necessary, since we know at compile time how much memory we have!
    // To allocate the memory on the stack, we would use:
    // IntCell m{0}; 
    // and there would be no need for a delete.
    
    IntCell *m;
    m = new IntCell{0};
    m->write(5);

    cout << "Cell m: " << m->read() << endl;

    IntCell *n = new IntCell{5};
    cout << "Cell n: " << n->read() << endl;

    /* comparison does not work as expected, it compares the pointers */
    if (m == n)
        cout << "m == n" << endl;
    else
        cout << "m != n" << endl;


    /* addresses and dereferencing */
    cout << "m: " << m << endl;
    cout << "Address of m (&m): " << &m << endl;
    cout << "Derefereced m ( *m.read() ): " << (*m).read() << endl;

    /* this works */
    if (m->read() == n->read())
        cout << "m->read() == n->read()" << endl;
    else
        cout << "m->read() != n->read()" << endl;

    /* every new needs a delete! */
    delete m, n;

    /*
     * References (lvalue references)
     * * & used in a declaration (not as an operator like above!!!)
     * * used as an alias (avoid copying memory, e.g., for a function call)
     * * auto can be used. The compiler figures out the data type.
     */
    int a = 12;
    auto &b = a;

    if (&a == &b)
        cout << "a and b occupy the same memory!" << endl;

    b = 24;
    cout << "a: " << a << endl;

    return 0;
}