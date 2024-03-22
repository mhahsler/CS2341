# Self-Balancing Binary Search Trees: AVL Trees

An AVL (Adelson-Velskii and Landis) tree is a binary search tree that always satisfies the
 following **balance condition:**

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

If the difference is larger, then the tree needs to be organized. 
This typically happens right after the insertion/deletion that creates the imbalance. 
This keeps the tree always balanced with a depth close to $O(log\ N)$.


## Balancing

Insertion/deletion may break the balancing condition and we will need to re-balance the tree using a **rotation**. 
We need 

* a single rotation for "outside" insertions (left-left and right-right) and 
* a double rotation for "inside" insertions (left-right and right-left).

**Slides:** [Balancing AVL trees](https://github.com/mhahsler/CS2341/blob/main/Chapter4_Trees/slides/AVL_trees.pdf).

**Visualization:** Here is an [AVL tree visualization](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)
to study how the algorithm rebalances the tree. 


## Exercises
Insert the following sequences into an AVL tree:

* `5, 1, 6, 3, 2`
* `1, 2, 3, 4`


## Implementation
Balancing using rotation is implemented in the `balance()` function in [AvlTree.h](AvlTree.h) which is performed after each `insert()`/`delete()`.


## Other Self-Balancing Binary Search Trees

Another popular self-balancing binary search tree is the [red-black tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree).
Read more about different types of [self-balancing binary search trees](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree).

