#ifndef SHELLSORT_H
#define SHELLSORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

#include <vector>

/**
 * Shellsort, using Shell's (poor) increments.
 */
template <typename Comparable>
void shellSort(std::vector<Comparable> &a)
{
    for (std::size_t gap = a.size() / 2; gap > 0; gap /= 2)
        for (std::size_t i = gap; i < a.size(); ++i)
        {
            Comparable tmp = std::move(a[i]);
            std::size_t j = i;

            for (; j >= gap && tmp < a[j - gap]; j -= gap)
                a[j] = std::move(a[j - gap]);
            a[j] = std::move(tmp);
        }
}

#endif
