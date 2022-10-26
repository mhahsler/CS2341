# Binary Search Tree (Unbalanced)

Binary search trees are one of the most important tree structures used to find elements quickly.

_Assumption:_ Items can be ordered and there are no duplicates (i.e., a total order).

_Definition:_ In a binary search tree, all items in each left subtree are smaller than the items in the right subtree.

See [BinarySearchTree.h](BinarySearchTree.h) for code.

Since items are stored in sorted order, a simple **inorder traversal** results in sorted output.
If a balanced tree is used (see Balance Problem below), then inserting $N$ items takes $O(N log\ N)$ time and traversing 
the tree takes $O(N)$ which gives a sorting algorithm  called [**tree sort**](https://en.wikipedia.org/wiki/Tree_sort) that is $O(N\ log\ N)$. Note that quicksort is better (in-place with lower overhead).

## Operations
* Insertion: Descend the tree (smaller values go to the left and larger values go to the right) till a new leaf can be created.

* Deletion: 
    1. recursively find the node to delete using binary search.
    2. (a) Two children case: replace element with the smallest element in
            the right subtree (b) One child case: replace the node with the only child, if any.


## Exercises 
1. Insert the following numbers into a binary search tree: 12, 90, 3, 5, 18, 9, 99, 91
2. Delete the following nodes from the tree: 3, 90


## Complexity 
The depth $d$ of a _binary search tree_ leads to $O(d)$ operations (for all but deleting and copying the whole tree). The average tree depth $d$ is $O(log\ N)$ under the
assumption that all insertion sequences are equally likely. Remember, $O(log\ N)$ means 
that the problem size is halved with each step.

Since $O(log\ N)$ is relatively small, operations can be defined/implemented recursively without running out of stack space.


## Balance Problem
The assumption of $O(log\ N)$ average running time is only true for a random insertion order and if no 
deletions are used! 
Deletions often replace a node with a node for the right subtree, resulting in an **unbalanced tree** that is left heavy!

