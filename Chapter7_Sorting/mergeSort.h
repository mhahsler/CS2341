#ifndef MERGESORT_H
#define MERGESORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

#include <vector>

/**
 * Internal method that merges two sorted halves of a subarray. This needs an extra temporary 
 * array.
 */
template <typename Comparable>
void merge(std::vector<Comparable> &a, std::vector<Comparable> &tmpArray,
           std::size_t leftPos, std::size_t rightPos, std::size_t rightEnd)
{
    std::size_t leftEnd = rightPos - 1;
    std::size_t tmpPos = leftPos;
    std::size_t numElements = rightEnd - leftPos + 1;

    // move through the two subarrays and merge them into the tmpArray by always picking 
    // the smaller element
    while (leftPos <= leftEnd && rightPos <= rightEnd)
        if (a[leftPos] <= a[rightPos])
            tmpArray[tmpPos++] = std::move(a[leftPos++]);
        else
            tmpArray[tmpPos++] = std::move(a[rightPos++]);
    
    // copy the remaining elements from the left subarray
    while (leftPos <= leftEnd)
        tmpArray[tmpPos++] = std::move(a[leftPos++]);

    // copy the remaining elements from the right subarray
    while (rightPos <= rightEnd)
        tmpArray[tmpPos++] = std::move(a[rightPos++]);

    // copy the tmpArray back into the original array
    for (std::size_t i = 0; i < numElements; ++i, --rightEnd)
        a[rightEnd] = std::move(tmpArray[rightEnd]);
}

/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void mergeSort(std::vector<Comparable> &a,
               std::vector<Comparable> &tmpArray, std::size_t left, std::size_t right)
{
    if (left < right)
    {
        // find the middle of the subarray
        std::size_t center = (left + right) / 2;
        
        // sort the left half
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);
        
        // merge the two halves
        merge(a, tmpArray, left, center + 1, right);
    }
}

/**
 * Mergesort algorithm (driver).
 */
template <typename Comparable>
void mergeSort(std::vector<Comparable> &a)
{
    // create a temporary array once here so it can be used by all recursive calls
    std::vector<Comparable> tmpArray(a.size());

    mergeSort(a, tmpArray, 0, a.size() - 1);
}

#endif