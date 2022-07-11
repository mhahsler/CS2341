#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> t;
    
    int data[] = {6, 2, 1, 8, 3, 4};

    for (auto & d : data) {
        t.insert(d);
    }

    cout << "Max: " << t.findMax() << endl;
    cout << "Min: " << t.findMin() << endl;

    cout << "Max depth:" <<  t.maxDepth() << endl;

    cout << "Contains 10?: " << t.contains(10) << endl;

    cout << "Contains 4?: " << t.contains(4) << endl;
    t.remove(4);
    cout << "Contains 4?: " << t.contains(4) << endl;

    cout << "Max depth:" <<  t.maxDepth() << endl;

    // worst case tree depth.
    // use the debugger to see why
    t.makeEmpty();
    int data2[] = {6, 5, 4, 3, 2, 1};

    for (auto & d : data2) {
        t.insert(d);
    }

    cout << "Max depth:" <<  t.maxDepth() << endl;


    return 0;
}
