#include <iostream>

#include "DSHeap.h"

int main()
{
    auto myheap = DSHeap<int>{};

    myheap.insert(30);
    myheap.insert(100);
    myheap.insert(80);
    myheap.insert(25);
    myheap.insert(40);
    
    myheap.print_tree();

    std::cout << "Removing elements...\n";
    while (!myheap.empty())
        std::cout << myheap.delete_min() << "\n";
    std::cout << std::endl;

    // myheap.delete_min(); // this throws an error

    //heapify a vector
    std::cout << "Heapifying a vector...\n";
    std::vector<int> v = { 30, 100, 80, 25, 40 };

    auto myheap2 = DSHeap<int>(v);
    std::cout << "Removing elements...\n";
    while (!myheap2.empty())
        std::cout << myheap2.delete_min() << "\n";
    std::cout << std::endl;

    return 0;
}
