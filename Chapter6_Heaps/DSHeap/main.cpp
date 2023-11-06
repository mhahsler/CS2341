#include <iostream>

#include "DSHeap.h"

using namespace std;

int main()
{
    auto myheap = DSHeap<int>{};

    myheap.insert(30);
    myheap.insert(100);
    myheap.insert(80);
    myheap.insert(25);
    myheap.insert(40);
    
    myheap.print_tree();

    cout << "Removing elements...\n";
    while (!myheap.empty())
        cout << myheap.delete_min() << "\n";
    cout << endl;

    // myheap.delete_min(); // this throws an error

    //heapify a vector
    vector<int> v = { 30, 100, 80, 25, 40 };

    auto myheap2 = DSHeap<int>(v);
    cout << "Removing elements...\n";
    while (!myheap2.empty())
        cout << myheap2.delete_min() << "\n";
    cout << endl;



    return 0;
}
