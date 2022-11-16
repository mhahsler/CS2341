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
| Merge Sort     |  $O(n\ log\ n)$            | yes $O(n)$     | yes     |
| Quicksort      |  $O(n^2)$                  | recursive $O(log\ n)$   |    no     |
| IntroSort (STL Hybrid) |  ?                 |      ?        |    ?     |



### Bubble Sort
A simple sorting algorithm that repeatedly steps through the input list element by element, comparing the current element with the one after it, swapping their values if needed. These passes through the list are repeated until no swaps had to be performed during a pass, meaning that the list has become fully sorted. 

### Selection Sort
Select the minimum and place it at the beginning of the array. Repeat the procedure with all but the first element till all
elements are sorted.

### Insertion Sort
Insertion sort goes through the array once from left to right.
At each iteration, insertion sort removes the element from the input data, finds the location it belongs within the sorted list (to the left), and inserts it there.

### Shell Sort
Shell Sort can be seen as either a generalization of sorting by exchange (bubble sort) or sorting by insertion (insertion sort). Instead of sorting pairs of elements next to each other, it compares elements far apart from each other, then progressively reducing the gap between elements to be compared. By starting with far apart elements, it can move some out-of-place elements into position faster than a simple nearest neighbor exchange.

### Heapsort
The algorithm first builds a max-heap stored in the original array and then repeatedly removes the top item to produce a sorted array.

### Mergesort
Merge sort consists of the steps:

1. Divide the unsorted list into $n$ sublists, each containing one element (a list of one element is considered sorted).
2. Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

### Quicksort
Quicksort is a type of divide and conquer algorithm for sorting an array, based on a partitioning routine; the details of this partitioning can vary somewhat, so that quicksort is a family of closely related algorithms. Applied to a range of at least two elements, partitioning produces a division into two consecutive non empty sub-ranges, in such a way that no element of the first sub-range is greater than any element of the second sub-range. After applying this partition, quicksort then recursively sorts the sub-ranges.

_Choice of pivot:_ Originally, the leftmost element of the partition would often be chosen as the pivot element. Unfortunately, this causes worst-case behavior on already sorted arrays, which is a rather common use-case. The problem was easily solved by choosing either a random index for the pivot, choosing the middle index of the partition or (especially for longer partitions) choosing the median of the first, middle and last element of the partition for the pivot.

### IntroSort
The STL currently implements a hybrid sorting algorithm using Quicksort, Heapsort and Insertion Sort to consistently 
provide good performance.

## Visualization of different algorithms

https://math.hws.edu/eck/js/sorting/xSortLab.html

## Profiling Code

[Profiling Software](https://en.wikipedia.org/wiki/Profiling_(computer_programming)) measures the space (memory) or time complexity of a program, the usage of particular instructions, or the frequency and duration of function calls. Most commonly, profiling information serves to aid program optimization.

Several open-source and commercial profilers are available (see [List of performance analysis tools](https://en.wikipedia.org/wiki/List_of_performance_analysis_tools)). Here I use 
`callgrind` and `KCachegrind`. Alternatives are [`perf`](https://perf.wiki.kernel.org/) for Linux and WSL2, and  [Dtrace](http://dtrace.org/blogs/about/) for MacOS.

Details on `callgrind` can be found in the [callgrind manual](https://developer.mantidproject.org/ProfilingWithValgrind.html). callgrind records each function call and how many machine code instructions were fetched. It can also calculate approximate run time by translating the instructions into cycle estimates.

### How to use callgrind/KCachgrind to Profile Runtime

**Installation:** You need to install `valgrind` and `KCachgrind` on your machine (Linux, WSL2; not available for Mac; for use on SMU's genuse machines, you need to [set up putty and VNC](https://www.smu.edu/OIT/Services/genuse)).

1. Run your executable with `valgrind`:
   ```
   valgrind --tool=callgrind --dump-instr=yes --simulate-cache=yes --collect-jumps=yes ./<executable> [args...]
   ```

2. This will produce a `callgrind.out.xxxxx` file. Open the file with:
   ```
   kcachegrind callgrind.out.xxxxx
   ```

3. Find the file/class you are interested in (e.g., `main.cpp`), click on the function below and choose [`Call Graph`](https://en.wikipedia.org/wiki/Call_graph) in the bottom right window. You should now see what gets called, how often, and how long it takes (in % of the caller). By default only calls that take long are shown. You can change his by right-click on the graph `Graph > Min. Node Cost`. 
4. Identify the functions that takes the most time and are called often. Optimize the code (loops, used algorithms, and data structure) there and profile again to se if and by how much you have improved the runtime (this can be judged by the number of instructions fetched).
