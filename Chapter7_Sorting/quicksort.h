#ifndef QUICKSORT_H
#define QUICKSORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

/**
 * Return a pivot. This implementation uses the median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable &median3(std::vector<Comparable> &a, std::size_t left, std::size_t right)
{

    // calculate center position of the subarray. This is an int division.
    std::size_t center = (left + right) / 2;

    // move the largest value to position right, the smallest to position left
    // and the "median" to position center using fast swaps.
    if (a[center] < a[left])
        std::swap(a[left], a[center]);
    if (a[right] < a[left])
        std::swap(a[left], a[right]);
    if (a[right] < a[center])
        std::swap(a[center], a[right]);

    // place pivot (the median) in the second to last position of the subarray.
    // note the last position is larger than the pivot.
    std::swap(a[center], a[right - 1]);

    // return pivot
    return a[right - 1];
}

/**
 * Internal insertion sort routine for subarrays
 * that is used by quicksort once subarrays become small and
 * insertion sort is faster than quicksort.
 */
template <typename Comparable>
void insertionSort(std::vector<Comparable> &a, std::size_t left, std::size_t right)
{
    // go through all elements in the array starting with the second one
    for (std::size_t p = left + 1; p <= right; ++p)
    {
        // take out the element
        Comparable tmp = std::move(a[p]);

        // shift the elements to the right until the right position is found
        std::size_t j;
        for (j = p; j > left && tmp < a[j - 1]; --j)
            a[j] = std::move(a[j - 1]);

        // insert the element into the right position   
        a[j] = std::move(tmp);
    }
}

/**
 * Internal quicksort method that makes recursive calls on a subarray (left to right).
 * Uses median-of-three partitioning for pivot and a use insertion sort for subarrays smaller than 10.
 */
template <typename Comparable>
void quicksort(std::vector<Comparable> &a, std::size_t left, std::size_t right)
{
    if (right - left < 10)
        // do insertion sort for small subarrays
        insertionSort(a, left, right);
    else
    {
        // find pivot and do recursive quicksort for large subarrays
        const Comparable &pivot = median3(a, left, right);

        // swap large values (larger than pivot) in the left subarray with small (smaller than pivot) 
        // values in to the right
        std::size_t i = left, j = right - 1;
        while (true)
        {
            // find the next element in the left subarray that is larger than the pivot
            while (a[++i] < pivot)
            {
            }
            // find the next element in the right subarray that is smaller than the pivot
            while (a[--j] > pivot)
            {
            }
            
            // swap or stop if we run into the pivot
            if (i < j)
                std::swap(a[i], a[j]);
            else
                break;
        }

        // put pivot back in the right position
        std::swap(a[i], a[right - 1]); 

        // sort small elements
        quicksort(a, left, i - 1); 
        // sort large elements
        quicksort(a, i + 1, right); 
    }
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quicksort(std::vector<Comparable> &a)
{
    quicksort(a, 0, a.size() - 1);
}

#endif
