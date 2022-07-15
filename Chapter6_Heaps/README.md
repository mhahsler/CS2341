# Chapter 6: Priority Queues (Heaps)

Goal: Find and remove the smallest element in a collection quickly.

Basic Operations:
* insert (= enqueue)
* deleteMin (= dequeue)

Options:
* unsorted array: $O(N)$
* binary search tree: $O(log\ N)$, but tree will get right-heavy because we always delete the minimum from the left side.
* use a new data structure.

## Binary Heap

A binary tree with

1. **Structure property:** a complete tree with no missing nodes. 
  The bottom level is filled left-to-right. This means the tree height is $O(log\ N)$.
2. **Heap-order property:** Any node has to be smaller than its descendants. 
  The root node is the smallest and can be found in $O(1)$.

Note: This tree is always balanced (structure property) and simpler to maintain than a balanced binary search tree (e.g., an AVL tree). 

### Operations

insert: move the next empty node (called a hole) up the tree till the new element can be inserted in the hole without violating the heap-order property. This operation is called _percolate up_. The worst case is to insert a new minimum with $O(log\ N)$.

deleteMin: remove the root node and then slide the resulting hole down the smaller of the children till the last element can be placed in the hole. This operation is called _percolate down_. Worst case is $O(log\ N)$

Note: This data structure is not good for finding an arbitrary element. We would have to scan the complete tree with $O(N)$!

### Implementation

Since the tree is complete, it can be efficiently stored in an array/vector (with the element at index 0 left empty). 

There is no need for pointers, since the tree is completely symmetric. 
For element at index $i$:

* left child is at index $2i$
* right child is at index $2i + 1$
* parent is at index $floor(i/2)$

See example: [DSHeap](DSHeap)

### Min vs. Max-Heap

We have described a min-heap so far. A max-heap is a heap with the largest element at the root node by reversing the heap-order property.

## STL Implementation

STL provides [`std::priority_queue`](https://cplusplus.com/reference/queue/priority_queue/) implements a max-heap. 

See example: [STL priority_queue](STL)