#include <iostream>

// DEBUG is defined in AvlTree.h and enables showing used rotations.
#define DEBUG
#include "AvlTree.h"


int main()
{
    AvlTree<int> t;

    
    std::cout << "\n\nExample that needs a single rotations.\n\n"; 
    int data[] = {1, 2, 3, 4, 5, 6};

    for (auto &d : data)
    {
        cout << "Inserting " << d << endl;
        t.insert(d);
    }

    cout << "Final tree" << endl;
    t.prettyPrintTree();



    std::cout << "\n\nExample that needs a double rotation\n" 
        << " (inside: inserting 2 on the left side into the right subtree of 1).\n\n";
    t.makeEmpty();
    int data2[] = {5, 1, 6, 3, 2, 7};

    for (auto &d : data2)
    {
        cout << "Inserting " << d << endl;
        t.insert(d);
    }

    cout << "Final tree\n";
    t.prettyPrintTree();
    cout << endl;

#ifdef DEBUG
    std::cout << "\n\nTest if the tree is balanced (throws exception if not).\n";
    std::cout << "root node height is: " <<  t.check_balance() << std::endl;
#endif

    return 0;
}
