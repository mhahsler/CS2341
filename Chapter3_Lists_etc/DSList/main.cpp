#include <iostream>
#include "DSIteratorList.h"

using namespace std;

int main()
{
    cout << boolalpha;
    
    DSIteratorList<int> l;

    for (int i = 10; i > 0; --i)
        l.insert_front(i);

    cout << "size: " << l.size() << "\n\n";

    // standard loop with iterators
    for (DSIteratorList<int>::const_iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // C++11 ranges work because we have iterators and begin() and end()
    for (const auto &v : l)
        cout << v << " ";
    cout << endl;

    cout << "Contains 99? " << (l.find(99) != nullptr) << "\n" << endl;
    
    // make a deep copy
    DSIteratorList l2 = l;
    
    // modify the list with a non-const iterator. go to 3rd element 
    // and set it to 99. Remove the element after.
    cout << "Change 3rd element to 99 and remove the element after." << endl;
    DSIteratorList<int>::iterator it = l.begin();
    ++it; ++it;
    *it = 99;
    
    l.remove(it);

    for (const auto &v : l)
        cout << v << " ";
    cout << endl;
    
    cout << "Contains 99? " << (l.find(99) != nullptr) << "\n" << endl;

    cout << "Old list" << endl;
    for (const auto &v : l2)
        cout << v << " ";
    cout << endl;

    return 0;
}
