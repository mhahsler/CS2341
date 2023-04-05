# Binary Search Tree (Unbalanced)

_Assumption:_ The data stored in the tree (the keys) can be ordered and there are no duplicates (i.e., a total order).

_Definition:_ A binary search tree is a binary tree where the key for each node being is greater than the keys of all the nodes in its left subtree and less than all the keys in the nodes in its right subtree.
    This order property can be written as 
    
$$L < N < R$$

Binary search trees are one of the most important tree structures used to find elements quickly.


See [BinarySearchTree.h](BinarySearchTree.h) for code.

Since keys are stored in sorted order, a simple **inorder traversal** (LNR) results in sorted output.
If a balanced tree is used (see Balance Problem below), then inserting $N$ items takes $O(N log\ N)$ time and traversing 
the tree takes $O(N)$ which gives a sorting algorithm called [**tree sort**](https://en.wikipedia.org/wiki/Tree_sort) that is $O(N\ log\ N)$. Note that [quicksort](https://en.wikipedia.org/wiki/Quicksort) 
has the same time complexity but is a better sorting algorithm (in-place with lower overhead). You will learn more about sorting later in this course and in the algorithms course.

## Operations
* Insertion: Descend the tree (smaller keys go to the left and larger keys go to the right) till a new leaf can be created.

* Find $x$: Follow the tree down (maybe using recursion).
    1. Return failure if the current node does not exist (we followed a `nullptr`).
    2. Return node if the current node $c == x$.
    3. if $x < c$ go to left child, otherwise go right child. 

* Deletion: 
    1. Find the node to delete using binary search.
    2. Cases:
        - A. No children: Just remove the node.
        - B. One child case: replace the node with the only child.
        - C. Two children case: replace element with the smallest element in
            the right subtree.

## Complexity 
The depth $d$ of a _binary search tree_ leads to $O(d)$ operations (for all but deleting and copying the whole tree). The **average tree depth** $d$ is $O(log\ N)$ under the
assumption that all insertion sequences are equally likely (i.e., random insertion). Remember, $O(log\ N)$ means 
that the problem size is halved with each step.

The exact depth of a complete tree (every level, except possibly the deepest, is entirely filled) with $N$ nodes can be calulated using $d = log_2(N + 1) - 1$. 

Examples: 
* A complete tree with 1,000,000 elements has $d + 1 = log_2(1,000,000 + 1) - 1 \approx 20$ levels.
* A complete tree with 1,000,000,000 elements has $d + 1 = log_2(1,000,000,000 + 1) \approx 30$ levels.

Since $O(log\ N)$ is relatively small, operations can be defined/implemented recursively without running out of stack memory (called a stack overflow).


## Exercises 
1. Insert the following numbers into a binary search tree: 12, 90, 3, 5, 18, 9, 99, 91
2. Delete the following nodes from the tree: 3, 90
3. Read the values in the tree using inorder traversal (LNR).


## Balance Problem
$O(log\ N)$ average running time (= tree depth) is only true for under the **assumption of random insertion order** and if 
**no deletions** are used! 

* Worst case insertion order is to insert sorted values.
* Deletions for case C replace a node with a node for the right subtree, resulting in an **unbalanced tree** that 
  is left heavy!

