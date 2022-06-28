// C++ program for implementation of Bubble sort
#include <algorithm>
#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int *randomArray(int size)
{
    int *arr = new int[size];
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 1000;

    return arr;
}

// Driver code
int main()
{
    srand(time(NULL));

    cout << "N, time [micro sec.]" << endl;

    for (int N = 1; N <= 100000; N *= 10)
    //for (int N = 1; N <= 20000; N += 1000)
    {
    int *arr = randomArray(N);

    auto start = high_resolution_clock::now();

    bubbleSort(arr, N);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << N << ", "
         << duration.count() << endl;

    // cout << "Sorted array: \n";
    // printArray(arr, N);

    delete[] arr;
}


return 0;
}