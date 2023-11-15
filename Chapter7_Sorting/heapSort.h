#ifndef HEAPSORT_H
#define HEAPSORT_H

// Code from https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
// Modified by MFH to fix compiler warnings

/* Note: This uses a Max-Heap! */

#include <vector>

/**
 * The tree for the heap is represented as a vector in the order root, left child, right child,
 * left child of left child, right child of left child, left child of right child, right child of right child, etc.
 * 
 * Note: Standard heap implementation leave the first element of the array empty (i.e. a[0] is not used).
 * We have to modify the code to use a[0] as the first element of the heap.
 * We can calculate the index of the left child of node with index i as 2 * (i + 1) - 1 = 2 * i + 1 
 * and the right child as lft child index + 1.
 * 
 * inline: tells the compiler to insert the code of the function into the calling code instead of 
 * making an expensive function call.
 */
inline std::size_t leftChild(std::size_t i)
{
    return 2 * i + 1; // this heap uses element 0!
}

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap (maxheap).
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void percDown(std::vector<Comparable> &a, std::size_t i, std::size_t n)
{
    std::size_t child;
    Comparable tmp = std::move(a[i]);

    while (leftChild(i) < n)
    {
        // find smaller child (right child is right after left child)
        child = leftChild(i);
        if (child != n - 1 && a[child] < a[child + 1])
            ++child;
        
        // Found insertion spot
        if (tmp > a[child])
            break;

        a[i] = std::move(a[child]);
        i = child;
    }

    a[i] = std::move(tmp);
 
}

/**
 * Standard heapsort: build a max-heap stored in the original array and then repeatedly
 * remove the top item to produce a sorted array.
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
    // convert the array into a max-heap. Percolate down. All elements above  n/2 are leaf
    // nodes and do not need percolate down.
    for (std::ptrdiff_t i = a.size() / 2 - 1; i >= 0; --i)
        percDown(a, i, a.size());

    // repeat deleteMax
    for (std::size_t j = a.size() - 1; j > 0; --j)
    {
        // deleteMax (a[0]) from the heap and place at the end of the unsorted part of the array (j)
        std::swap(a[0], a[j]);
        // fix the heap (percolate down twice)
        percDown(a, 0, j);
        percDown(a, 0, j);
    }
}

#endif
