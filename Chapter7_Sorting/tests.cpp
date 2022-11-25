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


// Define my own test macro
#define TEST(func, name) {                                                               \
    v2 = v;                                                                              \
    (func)(v2);                                                                          \
    if (!checkSorted(v2)) { cerr << "\t" << (name) << (" sort failed!\n"), ++failed; }   \
}


using namespace std;

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
 */
int main()
{
    int failed = 0;
    const size_t NUM_ITEMS = 1000;
    vector<int> v, v2;

    v.resize(NUM_ITEMS);
    srand(time(NULL));
    generate(v.begin(), v.end(), std::rand);

    TEST(bubbleSort, "Bubble sort")
    TEST(selectionSort, "Selection sort")
    TEST(insertionSort, "Insertion sort")
    TEST(shellSort, "Shell sort")
    TEST(heapSort, "Heap sort")
    TEST(mergeSort, "Merge sort")
    TEST(quicksort_orig, "Quick sort")
    TEST(quicksort, "Quick sort (improved)")

    // STL sort uses a different interface
    v2 = v;
    std::sort(v2.begin(), v2.end());
    if (!checkSorted(v2)) { cerr << ("\tSTL sort failed!\n"), ++failed; }

    cerr << "\nNumber of failed tests: " << failed << endl;

    return failed > 0;
}
