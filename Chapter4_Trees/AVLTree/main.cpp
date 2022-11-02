#include <iostream>
#include "AvlTree.h"
using namespace std;

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



    cout << "\n\nExample that needs a double rotation\n" 
        << " (inside: inserting 2 on the left side into the right subtree of 1).\n" << endl;
    t.makeEmpty();
    int data2[] = {5, 1, 6, 3, 2};

    for (auto &d : data2)
    {
        cout << "Inserting " << d << endl;
        t.insert(d);
    }

    cout << "Final tree" << endl;
    t.prettyPrintTree();


    return 0;
}
