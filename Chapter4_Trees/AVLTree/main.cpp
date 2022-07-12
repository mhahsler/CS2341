#include <iostream>
#include "AvlTree.h"
using namespace std;

// Test program
int main()
{
    AvlTree<int> t;

    int data[] = {1, 2, 3, 4, 5, 6};

    for (auto &d : data)
    {
        cout << "Inserting " << d << endl;
        t.insert(d);
    }

    cout << "Final tree" << endl;
    t.prettyPrintTree();



    cout << "\n\nExample that needs a double rotation.\n" << endl;
    t.makeEmpty();
    int data2[] = {6, 5, 3, 1, 2};

    for (auto &d : data2)
    {
        cout << "Inserting " << d << endl;
        t.insert(d);
    }

    cout << "Final tree" << endl;
    t.prettyPrintTree();


    return 0;
}
