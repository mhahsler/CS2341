#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>

// This is a function to implement selection sort. It's a simple sorting algorithm that sorts an array by 
// repeatedly finding the minimum element from the unsorted part and putting it at the beginning.
template <typename Comparable>
void selectionSort(std::vector<Comparable> &a)
{
    // This variable will hold the index of the minimum element in the unsorted part of the array.
    std::size_t minIndex;

    // This loop goes over each element in the array, except the last one.
    for (std::size_t i = 0; i < a.size() - 1; ++i)
    {
        // Assume the first element in the unsorted part is the minimum.
        minIndex = i;

        // This loop goes over the unsorted part of the array.
        for (std::size_t j = i + 1; j < a.size(); ++j)
            // If a smaller element is found, update minIndex.
            if (a[j] < a[minIndex])
                minIndex = j;

        // Swap the found minimum element with the first element of the unsorted part.
        std::swap(a[minIndex], a[i]);
    }
}

#endif