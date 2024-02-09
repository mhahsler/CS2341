// C++ program for implementation of Bubble sort
#include <algorithm>
#include <ctime>
#include <vector>
#include <iostream>

// This version uses std::vector instead of C arrays and STL generate.
// Note that there is no need to memory management (no new or delete)!

// Note: We pass a non-const reference to the vector because we want to modify the original vector
// We could also implement is by returning a new sorted vector.
void bubbleSort(std::vector<int>& array)
{
    size_t n = array.size();
    if (n < 1) return;
    
    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = 0; j < n - i - 1; ++j)
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
}

void printArray(const std::vector<int>& array)
{
    for (const auto& x : array)
        std::cout << x << " ";
    std::cout << "\n";
}

std::vector<int> randomIntVector(size_t size)
{
    std::vector<int> v(size);
    std::generate(v.begin(), v.end(), []() { return(std::rand() % 1000); });
    // Note: []() is a lambda function (an unnamed function)
    return v;
}

// Driver code you probably should have unit tests!
int main()
{
    // set the seed for the random number generator
    std::srand(unsigned(std::time(nullptr)));

    size_t N = 10;
    auto array = randomIntVector(N);

    std::cout << "Original array:\n";
    printArray(array);

    bubbleSort(array);
    
    std::cout << "Sorted array:\n";
    printArray(array);

    return 0;
}