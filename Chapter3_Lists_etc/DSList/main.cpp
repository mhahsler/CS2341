#include <iostream>
#include "DSList_iter.h"

using namespace std;

int main()
{
    DSList_iter<int> l;

    for (int i = 10; i > 0; --i)
        l.push_front(i);

    cout << "size: " << l.size() << "\n\n";

    // standard loop with iterators
    for (DSList_iter<int>::const_iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // C++11 ranges work because we have iterators and begin() and end()
    for (const auto &v : l)
        cout << v << " ";
    cout << endl;

    // modify the list with a non-const iterator. got to 3rd element and set it to 99.
    DSList_iter<int>::iterator it = l.begin();
    ++it; ++it;
    *it = 99;

    for (const auto &v : l)
        cout << v << " ";
    cout << endl;

    return 0;
}
