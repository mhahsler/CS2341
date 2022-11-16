#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>

// Find the minimum and place it in the first position
template <typename Comparable>
void selectionSort(std::vector<Comparable> &a)
{
    std::size_t minIndex;
    for (std::size_t i = 0; i < a.size() - 1; ++i)
    {
        minIndex = i;
        for (std::size_t j = i + 1; j < a.size(); ++j)
            if (a[j] < a[minIndex])
                minIndex = j;

        std::swap(a[minIndex], a[i]);
    }
}

#endif