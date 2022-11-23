#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::iota
#include <chrono>
#include <time.h>
#include <string>

#include "selectionSort.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "shellSort.h"
#include "heapSort.h"
#include "mergeSort.h"
#include "quicksort_original.h"
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

// Function to check if a vector is sorted
template <typename T>
bool checkSorted(const vector<T> &v)
{
     // check if the vector is sorted
     for (std::size_t i = 0; i < v.size() - 1; ++i)
          if (v[i] > v[i + 1])
               return false;
     return true;
}

/**
 * @brief     Sorts a vector using a given sorting algorithm
 * 
 * @param argc 
 * @param argv Select the data. The code understands "random", "sorted", "reverse", and "small"
 */
int main(int argc, char *argv[])
{
     const size_t NUM_ITEMS = 1000;
     string mode = "small"; // default
     
     if(argc > 1)
          mode = argv[1];
     
     // Note: To compare the runtime between the different sorting algorithms you usually run
     // the algorithms multiple times and take the average runtime. This is not done here for simplicity.  
     
      vector<int> v;

     // Run the code in the debugger with this to see how the different sorting algorithms work
     if (mode == "small") {   
          cout << "Small vector for testing with debugger." << endl;
          v = {4, 7, 9, 1, 2, 8, 0, 6, 3, 5};
     }

     // a random vector
     if (mode == "random") {
          v.resize(NUM_ITEMS);
          cout << "Random vector of size " << NUM_ITEMS << endl;
          srand(time(NULL));
          generate(v.begin(), v.end(), std::rand);
     }

     // check how the algoritms perform on already sorted vectors
     if (mode == "sorted") {
          v.resize(NUM_ITEMS);
          cout << "Sorted vector of size " << NUM_ITEMS << endl;
          iota(v.begin(), v.end(), 0);
     }

     // reverse the vector
     if (mode == "reverse") {
          v.resize(NUM_ITEMS);
          cout << "Reverse sorted vector of size " << NUM_ITEMS << endl;
          iota(v.begin(), v.end(), 0);
          reverse(v.begin(), v.end());
     }

     if (v.size() == 0) {
          cout << "Invalid mode. Use \"random\", \"sorted\", \"reverse\", or \"small\"" << endl;
          return 1;
     }

     // checkSorted(v);

     cout << boolalpha;
     cout << "\nAlgorithm, time in microseconds, sorted" << endl;

     // Bubble sort
     vector<int> v2 = v;
     auto start = high_resolution_clock::now();
     bubbleSort(v2);
     auto stop = high_resolution_clock::now();
     auto duration = duration_cast<microseconds>(stop - start);

     cout << "Bubble Sort"
          << ", "
          << duration.count() 
          << ", "
          << checkSorted(v2)
          << endl;
     
     // printVector(v2);
     
     // Selection sort
     v2 = v;
     start = high_resolution_clock::now();
     selectionSort(v2);

     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     cout << "Selection Sort"
          << ", "
          << duration.count() 
          << ", "
          << checkSorted(v2)
          << endl;
     
     // printVector(v);


     // Insertion sort
     v2 = v;
     start = high_resolution_clock::now();
     insertionSort(v2);

     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     cout << "Insertion Sort"
          << ", "
          << duration.count() 
          << ", "
          << checkSorted(v2)
          << endl;
     
     // printVector(v);

     // Shell sort
     v2 = v;
     start = high_resolution_clock::now();
     shellSort(v2);
     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     cout << "Shell Sort"
          << ", "
          << duration.count() 
          << ", "
          << checkSorted(v2)
          << endl;
     
     // printVector(v2);

     // Heap sort
     v2 = v;
     start = high_resolution_clock::now();
     heapSort(v2);
     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     cout << "Heap Sort"
          << ", "
          << duration.count() 
          << ", "
          << checkSorted(v2)
          << endl;
     
     //printVector(v2);

     // Merge sort
     v2 = v;
     start = high_resolution_clock::now();
     mergeSort(v2);
     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);

     //printVector(v2);

     cout << "Merge Sort"
          << ", "
          << duration.count() 
          << ", "
          << checkSorted(v2)
          << endl;

     // Quick sort original
     // FIXME:!!!
     
     v2 = v;
     start = high_resolution_clock::now();
     quicksort_orig(v2);
     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);


     cout << "Quicksort (Original)"
          << ", "
          << duration.count() 
          << ", "
          << checkSorted(v2)
          << endl;
     
     // printVector(v2);

     // Quick sort with median of three and insertion sort
     v2 = v;
     start = high_resolution_clock::now();
     quicksort(v2);
     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);
     
     // printVector(v2);

     cout << "Quicksort (with median of 3 and insertion sort)"
          << ", "
          << duration.count() 
          << ", "
          << checkSorted(v2)
          << endl;

     // STL sort
     v2 = v;
     start = high_resolution_clock::now();
     sort(v2.begin(), v2.end());

     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);
     
     // printVector(v2);

     cout << "Introsort (STL hybrid)"
          << ", "
          << duration.count() 
          << ", "
          << checkSorted(v2)
          << endl;

     return 0;
}
