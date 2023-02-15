// C++ program for implementation of Bubble sort
#include <algorithm>
#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

// A function to implement bubble sort
void bubbleSort(int array[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}

// Function to print an array
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int *randomArray(int size)
{
    int *array = new int[size];
    for (int i = 0; i < size; ++i)
        array[i] = rand() % 1000;

    return array;
}

// Driver code that reports time
int main()
{
    // set the seed for the random number generator
    srand(time(NULL));

    cout << "N, time [micro sec.]" << "\n";

    for (int N = 0; N <= 20000; N += 1000)
    //for (int N = 1; N <= 100000; N *= 10)
    {
    int *array = randomArray(N);

    auto start = high_resolution_clock::now();

    bubbleSort(array, N);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << N << ", "
         << duration.count() << "\n";

    // cout << "Sorted array: \n";
    // printArray(arr, N);

    delete[] array;
}


return 0;
}