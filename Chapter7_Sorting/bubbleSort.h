#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>

// A function to implement bubble sort: Swap adjacent elements if they are not in order
// Possible improvement: stop when no swaps are made
template <typename Comparable>
void bubbleSort(std::vector<Comparable> &a)
{
    // we have to do this n times
    for (std::size_t i = 0; i < a.size(); ++i)
        // go through the vector (the last i elements are already sorted)
        for (std::size_t j = 0; j < a.size() - i - 1; ++j)
            if (a[j] > a[j + 1])
                std::swap(a[j], a[j + 1]);
}

#endif