#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>

// This is a function to implement bubble sort. It's a simple sorting algorithm that repeatedly steps through the list,
// compares adjacent elements and swaps them if they are in the wrong order.
template <typename Comparable>
void bubbleSort(std::vector<Comparable> &a)
{
    // This boolean variable keeps track of whether any swaps have been made in a pass through the vector.
    bool swaps = true;

    // The outer loop runs for each element in the vector.
    for (std::size_t i = 0; i < a.size(); ++i)
    {
        // At the start of each pass, we assume no swaps will be made.
        swaps = false;

        // The inner loop goes through the vector, comparing each pair of adjacent elements.
        // It does not include the last `i` elements because they are already sorted.
        for (std::size_t j = 0; j < a.size() - i - 1; ++j)
            // If the elements are out of order, they are swapped.
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                // If a swap is made, the `swaps` variable is set to true.
                swaps = true;
            }

        // If no swaps were made in a pass through the vector, the `swaps` variable remains false and the outer loop is broken,
        // as the vector is already sorted.
        if (!swaps)
            break;
    }
}

#endif