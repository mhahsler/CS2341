#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <time.h>

#include "bubbleSort.h"
#include "insertionSort.h"
#include "shellSort.h"
#include "heapSort.h"
#include "mergeSort.h"
#include "quicksort.h"
//#include "radix_sort.h"

using namespace std;
using namespace std::chrono;

// This return is efficient in C++ because it uses move (see std::move)
// instead of a copy.
vector<int> randomIntVector(std::size_t size)
{
     vector<int> v(size);
     generate(v.begin(), v.end(), std::rand);
     return (v);
}

// Function to print a vector
template <typename T>
void printVector(const vector<T> &v)
{
     for (auto &e : v)
          cout << e << " ";
     cout << endl;
}

int main()
{
     const size_t NUM_ITEMS = 1000;
     srand(time(NULL));

     vector<int> v = randomIntVector(NUM_ITEMS);

     cout << "Algorithm, time in milliseconds" << endl;

     // Bubble sort
     vector<int> v2 = v;
     auto start = high_resolution_clock::now();
     bubbleSort(v2);
     // printVector(v2);

     auto stop = high_resolution_clock::now();
     auto duration = duration_cast<microseconds>(stop - start);

     cout << "Bubble Sort"
          << ", "
          << duration.count() << endl;

     // Insertion sort
     v2 = v;
     start = high_resolution_clock::now();
     insertionSort(v);
     // printVector(v);

     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     cout << "Insertion Sort"
          << ", "
          << duration.count() << endl;

     // Shell sort
     v2 = v;
     start = high_resolution_clock::now();
     shellSort(v);
     // printVector(v);

     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     cout << "Shell Sort"
          << ", "
          << duration.count() << endl;

     // Heap sort
     v2 = v;
     start = high_resolution_clock::now();
     heapSort(v);
     // printVector(v);

     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     cout << "Heap Sort"
          << ", "
          << duration.count() << endl;

     // Merge sort
     v2 = v;
     start = high_resolution_clock::now();
     mergeSort(v);
     // printVector(v);

     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     cout << "Merge Sort"
          << ", "
          << duration.count() << endl;

     // Quick sort
     v2 = v;
     start = high_resolution_clock::now();
     quicksort(v);
     // printVector(v);

     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     cout << "Quicksort"
          << ", "
          << duration.count() << endl;

     // STL sort
     v2 = v;
     start = high_resolution_clock::now();
     sort(v.begin(), v.end());
     // printVector(v);

     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     cout << "Introsort (STL hybrid)"
          << ", "
          << duration.count() << endl;

     return 0;
}
