# Balanced Binary Search Trees: AVL Trees

An AVL (Adelson-Velskii and Landis) tree is a binary search tree with the following **balance condition:**

> For every node in the tree, the height of the left and the right subtree can
differ by at most 1.

We can maintain the balance information (height) in the node structure. The height of an empty tree is defined as -1.

```cpp
template <typename Comparable>
class AVLNode
{
public:
    Comparable key;
    AVLNode *left;
    AVLNode *right;
    int height;
}
```

If the difference is larger, then the tree needs to be organized where the 
last insertion happened.
This keeps the tree balanced with a depth close to $O(log\ N)$.


## Balancing

Insertion/deletion may break the balancing condition and we will need to re-balance the tree using a **rotation**. 
We need 

* a single rotation for "outside" insertions (left-left and right-right) and 
* a double rotation for "inside" insertions (left-right and right-left).

**Slides:** [Balancing AVL trees](https://github.com/mhahsler/CS2341/blob/main/Chapter4_Trees/slides/AVL_trees.pdf).

**Visualization:** Here is an [AVL tree visualization](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html) for inserting and deleting integers.

**Code:** Balancing using rotation is implemented in the `balance()` function in [AvlTree.h](AvlTree.h) which is performed after each `insert()`/`delete()`.


## Exercises

Insert the following sequences into an AVL tree:

* `5, 1, 6, 3, 2`
* `1, 2, 3, 4`
