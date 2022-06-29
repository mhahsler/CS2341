// C++ program for implementation of Bubble sort
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

// Function to print a vector
template <typename T>
void printVector(const vector<T> &v)
{
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
}

// This return is efficient in C++ because it uses move (see std::move) 
//instead of copy.
vector<int> randomIntVector(int size)
{
    vector<int> v(size);
    generate(v.begin(), v.end(), std::rand);
    return (v);
}

// Driver code
int main()
{
    srand(time(NULL));

    cout << "N, time [micro sec.]" << endl;

    for (int N = 1; N <= 10000000; N *= 10)
    // for (int N = 1; N <= 20000; N += 1000)
    {
        vector<int> v = randomIntVector(N);

        auto start = high_resolution_clock::now();

        sort(v.begin(), v.end());
        // printVector(v);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << N << ", "
             << duration.count() << endl;
    }

    return 0;
}