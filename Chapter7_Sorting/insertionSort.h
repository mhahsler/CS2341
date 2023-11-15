#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

#include <vector>

// This is a function to implement insertion sort. It's a simple sorting algorithm that builds the final sorted array one item at a time.
template <typename Comparable>
void insertionSort(std::vector<Comparable> &a)
{
    // This loop goes through all elements in the array starting with the second one.
    for (std::size_t p = 1; p < a.size(); ++p)
    {
        // Remove the element from the array. The std::move function is used to indicate that a[j] may be "moved" without copying.
        Comparable tmp = std::move(a[p]);

        // This loop shifts the elements to the left of the current element to the right until the right position for the current element is found.
        std::size_t j;
        for (j = p; j > 0 && tmp < a[j - 1]; --j)
            a[j] = std::move(a[j - 1]);
        
        // Insert the current element into the right position.
        a[j] = std::move(tmp);
    }
}

#endif
