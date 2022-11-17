#include <iostream>

#include "DSHeap.h"

using namespace std;

int main()
{
    DSHeap<int> myheap = DSHeap<int>{};

    myheap.insert(30);
    myheap.insert(100);
    myheap.insert(80);
    myheap.insert(25);
    myheap.insert(40);
    
    myheap.prettyPrintTree();

    cout << "Removing elements...\n";
    while (!myheap.empty())
    {
        cout << myheap.deleteMin() << "\n";
    }
    cout << endl;

    // myheap.deleteMin(); // this throws an error

    return 0;
}
