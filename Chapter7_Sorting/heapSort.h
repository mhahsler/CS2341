#ifndef HEAPSORT_H
#define HEAPSORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

#include <vector>


/**
 * The tree for the heap is represented as a vector in the order root, left child, right child, 
 * left child of left child, right child of left child, left child of right child, right child of right child, etc.
 */

/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline std::size_t leftChild(std::size_t i)
{
    return 2 * i + 1;
}

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void percDown(std::vector<Comparable> &a, std::size_t i, std::size_t n)
{
    std::size_t child;
    Comparable tmp;

    for (tmp = std::move(a[i]); leftChild(i) < n; i = child)
    {
        child = leftChild(i);
        if (child != n - 1 && a[child] < a[child + 1])
            ++child;
        if (tmp < a[child])
            a[i] = std::move(a[child]);
        else
            break;
    }
    a[i] = std::move(tmp);
}

/**
 * Standard heapsort.
 * 
 * Note on the use of std::size_t and std::ptrdiff_t
 * 
 * Both of these types are integers used to index into a data structure.
 * * std::size_t is unsigned to represent an index (can only contain positive numbers)
 * * std::ptrdiff_t is signed to represent the difference between two indices (can contain positive and negative numbers)
 * 
 * These data types are preferred over int since they are guaranteed to be large enough to hold the 
 * size of any object in memory (while int may not). This is especially important for 64-bit systems.
 */
template <typename Comparable>
void heapSort(std::vector<Comparable> &a)
{
    for (std::ptrdiff_t i = a.size() / 2 - 1; i >= 0; --i) /* buildHeap */
        percDown(a, i, a.size());

    for (std::size_t j = a.size() - 1; j > 0; --j)
    {
        std::swap(a[0], a[j]); /* deleteMax */
        percDown(a, 0, j);
        percDown( a, 0, j );
    }
}

#endif
