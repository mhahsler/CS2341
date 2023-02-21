#include <iostream>
#include "DSIteratorList.h"


int main()
{
    std::cout << std::boolalpha;
    
    DSIteratorList<int> l;

    for (size_t i = 10; i > 0; --i)
        l.insert_front(i);

    std::cout << "size: " << l.size() << "\n\n";

    // standard loop with iterators
    for (DSIteratorList<int>::const_iterator it = l.begin(); it != l.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    // C++11 ranges work because we have iterators and begin() and end()
    for (const auto &v : l)
        std::cout << v << " ";
    std::cout << "\n";

    std::cout << "Contains 99? " << (l.find(99) != nullptr) << "\n" << "\n";
    
    // make a deep copy
    DSIteratorList l2(l);
    
    // modify the list with a non-const iterator. go to 3rd element 
    // and set it to 99. Remove the element after. Go one more element down
    // and insert 100.
    std::cout << "Change 3rd element to 99 and remove the element after." << "\n";
    DSIteratorList<int>::iterator it = l.begin();
    ++it; ++it;
    *it = 99;
    l.remove(it);

    ++it;
    l.insert(100, it);

    for (const auto &v : l)
        std::cout << v << " ";
    std::cout << "\n";
    
    std::cout << "size: " << l.size() << "\n\n";
    std::cout << "Contains 99? " << (l.find(99) != nullptr) << "\n" << "\n";

    // Old list should be unchanged since we made a deep copy
    std::cout << "Old list" << "\n";
    for (const auto &v : l2)
        std::cout << v << " ";
    std::cout << "\n";

    return 0;
}
