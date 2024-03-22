# Binary Search Tree (Unbalanced)

_Assumption:_ The data stored in the tree (the keys) can be ordered and there are no duplicates (i.e., a total order).

_Definition:_ A binary search tree is a binary tree where the key for each node is greater than the keys of all the nodes in its left subtree and less than all the keys in the nodes in its right subtree.
    This order property can be written as 
    
$$L < N < R$$

Binary search trees are one of the most important tree structures used to find elements quickly.


## Operations
* Insertion: Descend the tree (smaller keys go to the left and larger keys go to the right) till a new leaf can be created.

* Find $x$: Follow the tree down (maybe using recursion).
    1. Return failure if the current node does not exist (we followed a `nullptr`).
    2. Return node if the current node $c == x$.
    3. if $x < c$ go to left child, otherwise go right child. Go back to 1st step. 

* Deletion: 
    1. Find the node to delete using binary search.
    2. Cases:
        - A. No children: Just remove the node.
        - B. One child case: replace the node with the only child.
        - C. Two children case: replace element with the **smallest element in
            the right subtree**.


## Exercises 
1. Insert the following numbers into a binary search tree: 12, 90, 3, 5, 18, 9, 99, 91
2. Delete the following nodes from the tree: 3, 90
3. Read the values in the tree using inorder traversal (LNR).


## Binary Search Trees and Sorting
Since keys are stored in sorted order, a simple **inorder traversal** (LNR) results in sorted output.
If a balanced tree is used (see Balance Problem below), then inserting $N$ items takes $O(N log\ N)$ time and traversing 
the tree takes $O(N)$ which gives a sorting algorithm called [**tree sort**](https://en.wikipedia.org/wiki/Tree_sort) that is $O(N\ log\ N)$. Note that tree sort is not used in practice since other sorting algorithms 
have the same time complexity but are a better sorting algorithm (in-place with lower overhead). You will learn more about sorting later in this course and in the algorithms course.

## Implementation
See [BinarySearchTree.h](BinarySearchTree.h) for code.


## Complexity 
A depth $d$ of a _binary search tree_ leads to $O(d)$ operations (for all but deleting and copying the whole tree). The **average tree depth** $d$ is $O(log\ N)$ under the
assumption that all insertion sequences are equally likely (i.e., only use **random insertion**). Remember, $O(log\ N)$ means 
that the problem size is halved with each step.

The exact depth of a complete tree (every level, except possibly the deepest, is entirely filled) with $N$ nodes can be calculated using $d = log_2(N + 1) - 1$. (-1 since the root node has depth 0)

Examples: 
* A complete tree with 2,000,000 elements has $d = log_2(2,000,000 + 1) - 1 \approx 20$ levels.
* A complete tree with 2,000,000,000 elements has $d = log_2(2,000,000,000 + 1) - 1 \approx 30$ levels.

Since $O(log\ N)$ is relatively small, operations can be defined/implemented recursively without running out of stack memory (called a stack overflow).


## Balance Problem
$O(log\ N)$ time complexity is only true 
when the tree is balanced (all leave nodes are at roughly the same depth). This happens only
under the **assumption of random insertion order** and if **no deletions** are used! 

* Worst case insertion order is to insert sorted values which leads to a single branch of depth $d = N - 1$ and therefore
 $O(N)$ time complexity.
* Deletions for Case C replace a node with a node for the right subtree, resulting in an **unbalanced tree** that 
  will become increasingly left heavy!

