#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

#include <vector>

/**
 * Simple insertion sort.
 */
template <typename Comparable>
void insertionSort(std::vector<Comparable> &a)
{
    for (std::size_t p = 1; p < a.size(); ++p)
    {
        Comparable tmp = std::move(a[p]);

        std::size_t j;
        for (j = p; j > 0 && tmp < a[j - 1]; --j)
            a[j] = std::move(a[j - 1]);
        a[j] = std::move(tmp);
    }
}

#endif
