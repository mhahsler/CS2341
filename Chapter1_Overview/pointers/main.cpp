#include <iostream>
#include "IntCell.h"

using namespace std;

int main()
{
    /*
     * Pointers
     * * new: dynamic memory allocation on the heap
     * * delete: C++ does not use garbage collection! Memory leaks!!!
     *     use new only when it is needed (it is not needed in the following program!)
     * * -> (arrow operator) accesses members with a pointer to an object
     * * == pointer addresses are compared not the objects
     * * & (address-of-operator) returns the address of a variable (i.e., a pointer to the variable)
     * * (dereference operator) returns the object at the address the pointer points to.
     */
    IntCell *m;

    m = new IntCell{0};
    m->write(5);

    cout << "Cell m: " << m->read() << endl;

    IntCell *n = new IntCell{5};
    cout << "Cell n: " << n->read() << endl;

    /* comparison */
    if (m == n)
        cout << "m == n" << endl;
    else
        cout << "m != n" << endl;

    /* addresses and dereferencing */
    cout << "m: " << m << endl;
    cout << "Address of m (&m): " << &m << endl;
    cout << "Derefereced m ( *m.read() ): " << (*m).read() << endl;

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