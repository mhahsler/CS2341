// C++ program for implementation of Bubble sort
// Note: For Timing you should compile with -O3 (CMake release setting)

#include <algorithm>
#include <iostream>
#include <chrono>
#include <ctime> // for srand(time(NULL))

// A function to implement bubble sort
void bubbleSort(int array[], size_t n)
{
    if (n < 1)
        return;

    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = 0; j < n - i - 1; ++j)
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
}

// Function to print an array
void printArray(int array[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int *randomArray(size_t size)
{
    int *array = new int[size];
    for (size_t i = 0; i < size; ++i)
        array[i] = rand() % 1000;

    return array;
}

// Driver code that reports time
int main()
{
    // set the seed for the random number generator
    srand(time(NULL));

    std::cout << "N, time [micro sec.]"
              << "\n";

    // for (int N = 1; N <= 100000; N *= 10)
    for (size_t N = 0; N <= 20000; N += 1000)
    {
        int *array = randomArray(N);

        auto start = std::chrono::high_resolution_clock::now();

        bubbleSort(array, N);

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        std::cout << N << ", "
                  << duration.count() << "\n";

        // cout << "Sorted array: \n";
        // printArray(arr, N);

        // this needs to be in the for loop!
        delete[] array;
        array = nullptr;
    }

    return 0;
}