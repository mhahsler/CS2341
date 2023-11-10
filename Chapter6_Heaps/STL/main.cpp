#include <iostream>
#include <queue>

int main()
{
    // Note: The STL defaults to a max-heap!
    std::cout << "Making it a min-heap...\n";
    std::priority_queue<int> max_heap;

    // push is insert()
    max_heap.push(30);
    max_heap.push(100);
    max_heap.push(25);
    max_heap.push(40);

    // pop is deleteMax()
    std::cout << "Popping out elements from the max-heap...\n";
    while (!max_heap.empty())
    {
        std::cout << max_heap.top() << "\n";
        max_heap.pop();
    }

    // Make it a min-heap (using std::vector as the storage structure and std::greater as the comparator)
    std::cout << "Making it a min-heap...\n";
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    // push is insert()
    min_heap.push(30);
    min_heap.push(100);
    min_heap.push(25);
    min_heap.push(40);

    // pop is deleteMax()
    std::cout << "Popping out elements from the min-heap...\n";
    while (!min_heap.empty())
    {
        std::cout << min_heap.top() << "\n";
        min_heap.pop();
    }

    return 0;
}