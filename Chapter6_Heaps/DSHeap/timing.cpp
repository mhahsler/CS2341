// C++ program for implementation of Bubble sort
#include <algorithm>
#include <iostream>
#include <chrono>
#include <time.h>

#include "DSHeap.h"

using namespace std::chrono;

std::vector<int> randomVector(int size)
{
    std::vector<int> in(size);
    std::generate(in.begin(), in.end(), rand);
    return in;
}

// Driver code
// Make sure you compile this code with Release optimization (`CMake: [Release]`)
int main()
{
    srand(time(NULL));

    std::cout << "N, \"build time [micro sec.]\", \"build time per entry\", \"query time [micro sec.]\",  \"query time per entry\"\n";

    for (int N = 1; N <= 10000000; N *= 10)
    //for (int N = 10000; N <= 10000; N *= 10)
    // for (int N = 1; N <= 1000000; N += 10000)
    {
        DSHeap<int> heap;
        std::vector<int> in = randomVector(N);

        auto start = high_resolution_clock::now();

        for (auto const &d : in)
            heap.insert(d);

        auto stop = high_resolution_clock::now();
        auto duration_build = duration_cast<microseconds>(stop - start);

        start = high_resolution_clock::now();

        while (!heap.empty())
            heap.delete_min();

        stop = high_resolution_clock::now();
        auto duration_query = duration_cast<microseconds>(stop - start);

        std::cout << N << ", "
             << duration_build.count() << ", " 
             << double(duration_build.count()) / N << ", " 
             << duration_query.count() << ", "
             << double(duration_query.count()) / N << "\n";
    }

    return 0;
}
