#include <iostream>
//#include "DSVector.h"
#include "DSVector_impl.h"

using namespace std;

int main()
{

    DSVector<int> e{0};
    cout << "size: " << e.size() << endl;
    cout << "capacity: " << e.capacity() << endl;
    cout << "empty? " << e.empty() << endl << endl;

    e.push_back(10);
    cout << "size: " << e.size() << endl;
    cout << "capacity: " << e.capacity() << endl;
    cout << "empty? " << e.empty() << endl << endl;

    DSVector<int> v{5};
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    cout << "empty? " << v.empty() << endl << endl;

    // populate the vector
    for (int i = 0; i < v.size(); ++i)
    {
        v[i] = i * 10;
    }

    cout << endl;

    // print the vector using ranges from C++11. This requires v to have 
    // a begin() and end() method returning pointers to the 1st and last element
    // and ++ that works for the pointer. The for loop below is syntactic sugar for:
    // for (Object* it = v.begin(); it != v.end(); ++it) { Object& x = *it ; ...}
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v.resize(20);

    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    cout << "empty? " << v.empty() << endl << endl;

    // print the vector
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl << endl;

    // illegal operation
    try
    {
        cout << v[100];
    }
    catch (const std::exception &e) // caught by reference to base
    {
        std::cerr << " a standard exception was caught, with message '"
                  << e.what() << "'\n\n";
    }

    // assigne the vector to v2 and make sure that changing v does not affect
    // v2!
    DSVector<int> v2 = v;
    v[0] = 99;

    for (auto &x : v2)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
