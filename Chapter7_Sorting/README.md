# Chapter 7: Sorting

Sorting is an important task and choosing the right sorting algorithm can make a big difference
in performance. 
Important characteristics of [sorting algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)
are:

* Time complexity
* Memory complexity (do they sort in-place or need auxiliary data structures)
* Stability (stable sort algorithms sort equal elements in the same order that they appear in the input)


Here are some popular algorithms:


| Algorithm      | Worst Case Time Complexity | Auxiliary Data Structure | Stable? | 
| -------------- | -------------------------- | ---------------- | ------- |
| Bubble Sort    |  $O(n^2)$                  | no      | yes     |
| Insertion Sort |  $O(n^2)$                  | no      | yes     |
| Shell Sort     |  $O(n^2)$                  | no      | no      |
| Heap Sort      |  $O(n\ log\ n)$            | no      | no      |
| Merge Sort     |  $O(n\ log\ n)$            | yes $O(n)$     | yes     |
| Quicksort      |  $O(n^2)$                  | recursive $O(log\ n)$   |    no     |
| IntroSort (STL Hybrid) |  ?                 |      ?        |    ?     |



## Bubble Sort
A simple sorting algorithm that repeatedly steps through the input list element by element, comparing the current element with the one after it, swapping their values if needed. These passes through the list are repeated until no swaps had to be performed during a pass, meaning that the list has become fully sorted. 

## Insertion Sort
Insertion sort goes through the array once from left to right.
At each iteration, insertion sort removes the element from the input data, finds the location it belongs within the sorted list (to the left), and inserts it there.

## Shell Sort
Shell Sort can be seen as either a generalization of sorting by exchange (bubble sort) or sorting by insertion (insertion sort). Instead of sorting pairs of elements next to each other, it compares elements far apart from each other, then progressively reducing the gap between elements to be compared. By starting with far apart elements, it can move some out-of-place elements into position faster than a simple nearest neighbor exchange.

## Heapsort
The algorithm first builds a max-heap stored in the original array and then repeatedly removes the top item to produce a sorted array.

## Mergesort
Merge sort consists of the steps:

1. Divide the unsorted list into $n$ sublists, each containing one element (a list of one element is considered sorted).
2. Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

## Quicksort
Quicksort is a type of divide and conquer algorithm for sorting an array, based on a partitioning routine; the details of this partitioning can vary somewhat, so that quicksort is a family of closely related algorithms. Applied to a range of at least two elements, partitioning produces a division into two consecutive non empty sub-ranges, in such a way that no element of the first sub-range is greater than any element of the second sub-range. After applying this partition, quicksort then recursively sorts the sub-ranges.

Choice of pivot: Originally, the leftmost element of the partition would often be chosen as the pivot element. Unfortunately, this causes worst-case behavior on already sorted arrays, which is a rather common use-case. The problem was easily solved by choosing either a random index for the pivot, choosing the middle index of the partition or (especially for longer partitions) choosing the median of the first, middle and last element of the partition for the pivot.

## IntroSort
The STL currently implements a hybrid sorting algorithm using Quicksort, Heapsort and Insertion Sort to consistently 
provide good performance.

## Visualization of different algorithms

https://math.hws.edu/eck/js/sorting/xSortLab.html
