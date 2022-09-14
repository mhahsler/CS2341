#include <iostream>
#include "DSVector.h"

using namespace std;

int main()
{
    DSVector<int> e{0};

    cout << boolalpha;
    cout << "size: " << e.size() << "\n"
         << "capacity: " << e.capacity() << "\n"
         << "empty? " << e.empty() << "\n\n";

    e.push_back(10);
    cout << "size: " << e.size() << "\n"
         << "capacity: " << e.capacity() << "\n"
         << "empty? " << e.empty() << "\n\n";

    DSVector<int> v{5};
    cout << "size: " << v.size() << "\n"
         << "capacity: " << v.capacity() << "\n"
         << "empty? " << v.empty() << "\n\n";

    // populate the vector
    for (size_t i = 0; i < v.size(); ++i)
        v[i] = i * 10;

    // print the vector using an iterator
    cout << "With iterator: ";
    for (DSVector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // print the vector using ranges from C++11. This requires v to have
    // a begin() and end() method returning pointers to the 1st and last element
    // and ++ that works for the pointer. This is just syntactic sugar for the loop above.
    cout << "With ranges: ";
    for (auto &x : v)
        cout << x << " ";
    cout << endl;

    cout << "resize the vector to 20\n";
    v.resize(20);

    cout << "size: " << v.size() << "\n"
         << "capacity: " << v.capacity() << "\n"
         << "empty? " << v.empty() << "\n\n";

    // print the vector
    for (auto &x : v)
        cout << x << " ";
    cout << "\n\n";

    // try an illegal operation
    try
    {
        cout << v[100];
    }
    catch (const std::exception &e) // caught by reference to base
    {
        std::cerr << "A standard exception was caught, with message '"
                  << e.what() << "'\n\n";
    }

    // assign the vector to v2 and make sure that changing v does not affect
    // v2!
    DSVector<int> v2 = v;
    v[0] = 99;

    for (auto &x : v2)
        cout << x << " ";
    cout << endl;

    return 0;
}
