// C++ program using the STL sort algorithm
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <ctime>


// Function to print a vector
template <typename T>
void printVector(const std::vector<T> &v)
{
    for (auto &e : v)
        std::cout << e << " ";
    std::cout << std::endl;
}

// This return is efficient in C++ because it uses move (see std::move) 
//instead of copy.
std::vector<int> randomIntVector(size_t size)
{
    std::vector<int> v(size);
    std::generate(v.begin(), v.end(), std::rand);
    return (v);
}

// Driver code
int main()
{
    srand(time(NULL));

    std::cout << "N, time [micro sec.]" << "\n";

    
    // Note that this goes up to 10 million!
    //for (size_t N = 1; N <= 10000000; N *= 10)
    for (int N = 1; N <= 20000; N += 1000)
    {
        std::vector<int> v = randomIntVector(N);

        auto start = std::chrono::high_resolution_clock::now();

        // sorting a container (see https://cplusplus.com/reference/algorithm/sort/)
        sort(v.begin(), v.end());
        // printVector(v);

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        std::cout << N << ", "
             << duration.count() << "\n";
    }

    return 0;
}