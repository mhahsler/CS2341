#ifndef QUICKSORT_H
#define QUICKSORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable &median3(std::vector<Comparable> &a, std::size_t left, std::size_t right)
{
    std::size_t center = (left + right) / 2;

    if (a[center] < a[left])
        std::swap(a[left], a[center]);
    if (a[right] < a[left])
        std::swap(a[left], a[right]);
    if (a[right] < a[center])
        std::swap(a[center], a[right]);

    // Place pivot at position right - 1
    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}

/**
 * Internal insertion sort routine for subarrays
 * that is used by quicksort.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void insertionSort(std::vector<Comparable> &a, std::size_t left, std::size_t right)
{
    for (std::size_t p = left + 1; p <= right; ++p)
    {
        Comparable tmp = std::move(a[p]);
        std::size_t j;

        for (j = p; j > left && tmp < a[j - 1]; --j)
            a[j] = std::move(a[j - 1]);
        a[j] = std::move(tmp);
    }
}

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quicksort(std::vector<Comparable> &a, std::size_t left, std::size_t right)
{
    if (left + 10 <= right)
    {
        const Comparable &pivot = median3(a, left, right);

        // Begin partitioning
        std::size_t i = left, j = right - 1;
        for (;;)
        {
            while (a[++i] < pivot)
            {
            }
            while (pivot < a[--j])
            {
            }
            if (i < j)
                std::swap(a[i], a[j]);
            else
                break;
        }

        std::swap(a[i], a[right - 1]); // Restore pivot

        quicksort(a, left, i - 1);  // Sort small elements
        quicksort(a, i + 1, right); // Sort large elements
    }
    else // Do an insertion sort on the subarray
        insertionSort(a, left, right);
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
