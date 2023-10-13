# Chapter 6: Priority Queues (Heaps)

**Goal:** Always find and remove the element with the smallest key in a collection quickly.

Basic Operations:
* insert (= enqueue)
* deleteMin (= dequeue)

Options:
* Unsorted array: $O(N)$
* A balanced binary search tree: $O(log\ N)$. Without balancing, the tree would get right-heavy because we always delete the minimum from the left side.
* Use a **new specialized binary heap data structure** that has faster access to the minimum and does not need rotations for balancing.

Note: This data structure is very different from regular queues and not related
to heap memory! 

## Binary Heap

A binary tree with

1. **Structure property:** a complete tree with no missing nodes. 
  The bottom level is filled left-to-right ending in "last element." The missing node next to the last element is called 
  the "hole."
  The structure property ensures that the tree has a height of $O(log\ N)$.
2. **Heap-order property:** The key of node has to be smaller than the keys 
  of its descendants. 
  The root node always has the smallest key so finding it is free.

Note: This tree is always balanced (structure property) but the heap-order property makes it much simpler to maintain than a balanced binary search tree (e.g., an AVL tree). 

### Operations

**insert:** move the "hole" up the tree till the new element can be inserted in the hole without violating the heap-order property. This operation is called _percolate up_. The worst case is to insert a new minimum with $O(log\ N)$ because the hole has to be moved up all the way to the root.

**deleteMin:** remove the root node (with the minimum key) and then move the resulting hole down the smallest of the children till the "last element" in the tree can be placed in the hole without violating the heap-order property. This operation is called _percolate down_. 
Worst case is $O(log\ N)$.

**Note:** This data structure is not good for finding an arbitrary element. We would have to scan the complete tree with $O(N)$ operations!

**Example:** Add 30, 100, 80, 25, 40 to a heap and then use delete Min to get the values back.

### Implementation

Since the binary tree is complete, it can be efficiently stored in an array/vector filled level-wise, left-to-right from the tree (the element at index 0 is left empty to make access very simple). 

For the element at index $i$:
* the left child is at index $2i$
* the right child is at index $2i + 1$
* the parent is at index $\lfloor i/2 \rfloor$ (floor function).

_Note:_ this is also an effective storage format for any balanced tree.

See example: [DSHeap](DSHeap)

There exist other variants of heaps: Leftist, Binomial Fibonacci, ...


### Min vs. Max-Heap

We have described a min-heap so far. A max-heap is a heap with the largest element at the root node by reversing the heap-order property.

## STL Implementation

STL provides [`std::priority_queue`](https://cplusplus.com/reference/queue/priority_queue/) implements a max-heap. 

See example: [STL priority_queue](STL)


### Comparison of Search Performance

Wikipedia contains a
[comparison of asymptotic worst-case analysis (Big-O)](https://en.wikipedia.org/wiki/Search_data_structure)
for all the data structures we have learned about in this class.
