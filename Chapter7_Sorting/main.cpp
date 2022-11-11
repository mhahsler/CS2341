#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::iota
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
     vector<int> v(NUM_ITEMS);

     // a random vector
     cout << "Random vector of size " << NUM_ITEMS << endl;
     srand(time(NULL));
     generate(v.begin(), v.end(), std::rand);

     // a sorted vector 0, 1, 2,...
     // cout << "Sorted vector of size " << NUM_ITEMS << endl;
     // iota(begin(v), end(v), 0);

     // reverse the vector
     // cout << "Reversed vector of size " << NUM_ITEMS << endl;
     // iota(begin(v), end(v), 0);
     // reverse(v.begin(), v.end());


     cout << "\nAlgorithm, time in milliseconds" << endl;

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
