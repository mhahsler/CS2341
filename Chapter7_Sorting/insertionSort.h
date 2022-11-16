#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

#include <vector>

/**
 * Simple insertion sort. Move each element into its proper position.
 */
template <typename Comparable>
void insertionSort(std::vector<Comparable> &a)
{
    // go through all elements in the array starting with the second one
    for (std::size_t p = 1; p < a.size(); ++p)
    {
        // remove the element from the array
        Comparable tmp = std::move(a[p]);

        // shift the elements to the left of the element to the right until the right position is found
        std::size_t j;
        for (j = p; j > 0 && tmp < a[j - 1]; --j)
            a[j] = std::move(a[j - 1]);
        
        // insert the element into the right position
        a[j] = std::move(tmp);
    }
}

#endif
