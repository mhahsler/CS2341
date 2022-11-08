#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>

// A function to implement bubble sort to sort and modify a
template <typename Comparable>
void bubbleSort(std::vector<Comparable> &a)
{
    for (std::size_t i = 0; i < a.size(); ++i)
        for (std::size_t j = 0; j < a.size() - i - 1; ++j)
            if (a[j] > a[j + 1])
                std::swap(a[j], a[j + 1]);
}

#endif