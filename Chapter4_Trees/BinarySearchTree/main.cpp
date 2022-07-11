#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> t;
    
    int data[] = {2, 8, 6, 4, 1, 3};

    for (auto & d : data) {
        t.insert(d);
    }

    cout << "Max: " << t.findMax() << endl;
    cout << "Min: " << t.findMin() << endl;

    cout << "contains 4: " << t.contains(4) << endl;
    cout << "contains 10: " << t.contains(10) << endl;

    return 0;
}
