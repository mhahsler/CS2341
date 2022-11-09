#ifndef SHELLSORT_H
#define SHELLSORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

#include <vector>

/**
 * Shellsort: Compare and swap elements that are
 * gap elements apart. Reduce the gap and repeat until the gap is 1. The gap moves the elements
 * farther and this reaches the correct position with less moves.
 */
template <typename Comparable>
void shellSort(std::vector<Comparable> &a)
{
    // start with a gap of n/2 and half it every time till we reach 1
    for (std::size_t gap = a.size() / 2; gap > 0; gap /= 2)
        // go through all elements in the array starting with the gap-th one
        for (std::size_t i = gap; i < a.size(); ++i)
        {
            // remove an the element from the array
            Comparable tmp = std::move(a[i]);
            
            // shift the elements to the right until the right position is found
            std::size_t j = i;
            for (; j >= gap && tmp < a[j - gap]; j -= gap)
                a[j] = std::move(a[j - gap]);
            
            // insert the element into the right position
            a[j] = std::move(tmp);
        }
}

#endif
