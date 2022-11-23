#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>

// A function to implement bubble sort: Swap adjacent elements if they are not in order
template <typename Comparable>
void bubbleSort(std::vector<Comparable> &a)
// this tells GCC not to inline the function
//void __attribute__ ((noinline)) bubbleSort(std::vector<Comparable> &a)
{
    bool swaps = true;

    // we have to do this n times or till no more swaps are made
    for (std::size_t i = 0; i < a.size(); ++i)
    {
        swaps = false;

        // go through the vector (the last i elements are already sorted)
        for (std::size_t j = 0; j < a.size() - i - 1; ++j)
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                swaps = true;
            }

        // stop early if no swaps were performed
        if (!swaps)
            break;
    }
}

#endif