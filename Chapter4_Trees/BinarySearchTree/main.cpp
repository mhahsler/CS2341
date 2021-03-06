#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main( )
{
    BinarySearchTree<int> t;
    
    int data[] = {6, 2, 1, 8, 4, 3};
    // average depth should be O(log N). log2(6) = 2.6

    for (auto & d : data) {
        t.insert(d);
    }

    t.prettyPrintTree();

    cout << "Max: " << t.findMax() << endl;
    cout << "Min: " << t.findMin() << endl;
    cout << "Max depth:" <<  t.maxDepth() << endl;

    cout << "Contains 10?: " << t.contains(10) << endl;

    cout << "Contains 4?: " << t.contains(4) << endl;
    t.remove(4);

    t.prettyPrintTree();

    cout << "Contains 4?: " << t.contains(4) << endl;

    cout << "Max depth:" <<  t.maxDepth() << endl;

    // worst case tree depth.
    // use the debugger to see why
    t.makeEmpty();
    int data2[] = {1, 2, 3, 4, 5, 6};

    for (auto & d : data2) {
        t.insert(d);
    }

    t.prettyPrintTree();

    cout << "Max depth for inserting values in order: " <<  t.maxDepth() << endl;

      t.makeEmpty();
    int data3[] = {6, 5, 4, 3, 2, 1};

    for (auto & d : data3) {
        t.insert(d);
    }

    t.prettyPrintTree();

    cout << "Max depth for inserting sorted values in reverse order: " <<  t.maxDepth() << endl;


    return 0;
}
