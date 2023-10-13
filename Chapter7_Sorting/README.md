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
| Selection Sort |  $O(n^2)$                  | no      | no      |
| Insertion Sort |  $O(n^2)$                  | no      | yes     |
| Shell Sort     |  $O(n^2)$                  | no      | no      |
| Heap Sort      |  $O(n\ log\ n)$            | no      | no      |
| Merge Sort     |  $O(n\ log\ n)$            | yes $O(n)$ merge list    | yes     |
| Quicksort      |  $O(n^2)$ (avg. is $O(n\ log\ n)$ )  | yes $O(log\ n)$ for recursion   |    no     |
| IntroSort (STL Hybrid) | $O(n\ log\ n)$     |      yes        |    no     |


Sort: 4, 7, 9, 1, 2, 8, 0, 6, 3, 5

## Popular Algorithms

### Bubble Sort
A simple sorting algorithm that repeatedly steps through the input list element by element, comparing the current element with the one after it, swapping their values if needed. Note that the last element is the maximum after the first pass.
These passes through the list are repeated until no swaps had to be performed during a pass, meaning that the list has become fully sorted. The maximum number of passes is $n$. 

### Selection Sort
Find (i.e., select) the minimum in one pass over the array and place it at the beginning of the array. Repeat the procedure with all but the first element till all elements are sorted. Instead of the minimum, the maximum can be selected and placed at
the end of the array. 

This is similar to bubble sort, but performs fewer swaps.

### Insertion Sort
Insertion sort goes through the array once from left to right.
At each iteration, insertion sort removes the current element from the input data, finds the location it belongs within the sorted list (to the left), and inserts it there.

Goes only once through the array and performs moves.

### Shell Sort
Shell Sort can be seen as either a generalization of sorting by exchange (bubble sort) or sorting by insertion (insertion sort). Instead of sorting pairs of elements next to each other, it compares elements far apart from each other, then progressively reducing the gap between elements to be compared. 

By starting with far apart elements, it can move some out-of-place elements into position faster than a simple neighbor exchange.

### Heapsort
The algorithm first builds a max-heap stored in the original array and then repeatedly removes the top item to produce a sorted array.

### Mergesort
Merge sort always merges two sorted lists into a new sorted list. It consists of the steps:

1. Divide the unsorted list into $n$ sublists, each containing one element (a list of one element is considered sorted).
2. Repeatedly merge pairs of adjacent sublists to produce new sorted sublists until there is only one list remaining. This will be the sorted list.

Mergesort needs an external data structure for the sublists.

### Quicksort
Quicksort is a type of divide and conquer algorithm for sorting an array, based on a partitioning routine; the details of this partitioning can vary somewhat, so that quicksort is a family of closely related algorithms. Applied to a range of at least two elements, partitioning produces a division into two consecutive non-empty sub-ranges, in such a way that no element of the first sub-range is greater than any element of the second sub-range. After applying this partition, quicksort then recursively sorts the sub-ranges.

Algorithm:

1. Choose pivot element
2. Perform swaps such that all elements to the left are smaller than the pivot and elements to the right are larger.
3. Place the pivot in its correct place
4. Recursively quicksort the two subarrays to the left and to the right of the pivot.

_Choice of pivot:_ Originally, the leftmost element of the partition would often be chosen as the pivot element. Unfortunately, this causes worst-case behavior on already sorted arrays, which is a rather common use-case. The problem was easily solved by choosing either a random index for the pivot, choosing the middle index of the partition or (especially for longer partitions) choosing the median of the first, middle and last element of the partition for the pivot.

### IntroSort
The STL currently implements a hybrid sorting algorithm using Quicksort, Heapsort and Insertion Sort to consistently 
provide good performance.


##  Comparing different algorithms

### Understanding how Different Algorithms Work

You can use the debugger to analyze what the different sorting algorithms do. By default,
`sort` uses a small, manually defined array which can be used for debugging. Set the breakpoint 
in `main.cpp` right before the algorithm you are interested in.


Here is a website with a useful visualization: https://math.hws.edu/eck/js/sorting/xSortLab.html


### Compare Runtime

Run 
```
./sort random
```

several times and look at the average run time (this runs sorting on large random arrays).

Then run
```
./sort sorted
./sort reverse
```

to see how the algorithms perform if the array is already sorted.

Try with larger random arrays.
```
./sort random 100000
```

**A note on compiler optimization:**      
Compilers use [code optimization](https://en.wikipedia.org/wiki/Optimizing_compiler) ([GCC optimizations](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)).
In VS Code, compile the code using in the bottom bar `CMake:[Release]` (i.e., with speed optimization) instead of `CMake: [Debug]` (optimizer disabled). 


## Profiling Code
To write efficient code, it is often useful to see what parts of the code take the most time 
to run or use the most amount of memory. This process is called profiling. 
Here is how to [profile with `valgrind`](../HOWTO_profile_code.md).


Run (replace `xxxxx`)
```
valgrind --tool=callgrind --dump-instr=yes --simulate-cache=yes --collect-jumps=yes ./sort random
kcachegrind callgrind.out.xxxxx
```

Check the impact of optimization on profiling (use `[CMake: RelWithDebInfo]`). One important optimization is inlining functions (see bubbleSort).

## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)