#ifndef QUICKSORT_H
#define QUICKSORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable &median3(std::vector<Comparable> &a, int left, int right)
{
    int center = (left + right) / 2;

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
void insertionSort(std::vector<Comparable> &a, int left, int right)
{
    for (int p = left + 1; p <= right; ++p)
    {
        Comparable tmp = std::move(a[p]);
        int j;

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
void quicksort(std::vector<Comparable> &a, int left, int right)
{
    if (left + 10 <= right)
    {
        const Comparable &pivot = median3(a, left, right);

        // Begin partitioning
        int i = left, j = right - 1;
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

/**
 * Internal selection method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * Places the kth smallest item in a[k-1].
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 * k is the desired rank (1 is minimum) in the entire array.
 */
template <typename Comparable>
void quickSelect(std::vector<Comparable> &a, int left, int right, int k)
{
    if (left + 10 <= right)
    {
        const Comparable &pivot = median3(a, left, right);

        // Begin partitioning
        int i = left, j = right - 1;
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

        // Recurse; only this part changes
        if (k <= i)
            quickSelect(a, left, i - 1, k);
        else if (k > i + 1)
            quickSelect(a, i + 1, right, k);
    }
    else // Do an insertion sort on the subarray
        insertionSort(a, left, right);
}

/**
 * Quick selection algorithm.
 * Places the kth smallest item in a[k-1].
 * a is an array of Comparable items.
 * k is the desired rank (1 is minimum) in the entire array.
 */
template <typename Comparable>
void quickSelect(std::vector<Comparable> &a, int k)
{
    quickSelect(a, 0, a.size() - 1, k);
}

template <typename Comparable>
void SORT(std::vector<Comparable> &items)
{
    if (items.size() > 1)
    {
        std::vector<Comparable> smaller;
        std::vector<Comparable> same;
        std::vector<Comparable> larger;

        auto chosenItem = items[items.size() / 2];

        for (auto &i : items)
        {
            if (i < chosenItem)
                smaller.push_back(std::move(i));
            else if (chosenItem < i)
                larger.push_back(std::move(i));
            else
                same.push_back(std::move(i));
        }

        SORT(smaller); // Recursive call!
        SORT(larger);  // Recursive call!

        std::move(begin(smaller), end(smaller), begin(items));
        std::move(begin(same), end(same), begin(items) + smaller.size());
        std::move(begin(larger), end(larger), end(items) - larger.size());

        /*
                items.clear( );
                items.insert( end( items ), begin( smaller ), end( smaller ) );
                items.insert( end( items ), begin( same ), end( same ) );
                items.insert( end( items ), begin( larger ), end( larger ) );
        */
    }
}

#endif
