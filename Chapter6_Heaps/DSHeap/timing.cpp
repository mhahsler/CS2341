// C++ program for implementation of Bubble sort
#include <algorithm>
#include <iostream>
#include <chrono>
#include <time.h>

#include "DSHeap.h"

using namespace std;
using namespace std::chrono;

vector<int> randomVector(int size)
{
    vector<int> in(size);
    generate(in.begin(), in.end(), rand);
    return in;
}

// Driver code
int main()
{
    srand(time(NULL));

    cout << "N, \"build time [micro sec.]\", \"build time per entry\", \"query time [micro sec.]\",  \"query time per entry\"" << endl;

    for (int N = 1; N <= 10000000; N *= 10)
    // for (int N = 1; N <= 1000000; N += 10000)
    {
        DSHeap<int> heap;
        vector<int> in = randomVector(N);

        auto start = high_resolution_clock::now();

        for (auto const &d : in)
            heap.insert(d);

        auto stop = high_resolution_clock::now();
        auto duration_build = duration_cast<microseconds>(stop - start);

        start = high_resolution_clock::now();

        while (!heap.empty())
            heap.deleteMin();

        stop = high_resolution_clock::now();
        auto duration_query = duration_cast<microseconds>(stop - start);

        cout << N << ", "
             << duration_build.count() << ", " 
             << double(duration_build.count()) / N << ", " 
             << duration_query.count() << ", "
             << double(duration_query.count()) / N << endl;
    }

    return 0;
}
