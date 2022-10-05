# Chapter 4: Trees, Sets, and Maps

Lists have for many operations $O(N)$ (e.g., search, insertion at an arbitrary location) 
which is slow for large amounts of data.
Trees can have an average time complexity of $O(log\ N)$.

Recursive definition: A tree $T$

* is a collection of __nodes__.
* is empty or has a single __root node__ $r$.
* has zero or more nonempty subtrees $T_1, T_2, ..., T_k$ whose roots are connected by a 
  __directed edge__ from $r$.


More naming conventions:
* Two nodes are called __parent__ and __child__ of each other if the parent as a directed edge 
    to the child.
* Nodes without children are called __leaves.__
* A __path__ is a sequence along edges. The __path length__ is the number of edges.
* The __depth__ of a node is the length of the path from the root node $r$ to the node 
  (there is only on path). 
* The path from a node to the farthest leaf node is called the node's __height.__
* A tree where a node can have at most $M$ children is called an __$M$-ary tree.__

Observations:
* A tree is a special type of graph with only a single path from the root to each leaf.
* A collection of $N$ nodes (one is the root node) has $N - 1$ edges.

### Implementation

We implement a tree as a set of connected `Nodes`.

Each node in a general tree ($M$-ary tree) can have a variable list of children. We can store it
in a [singly-linked list](https://en.cppreference.com/w/cpp/container/forward_list).

```cpp
template <typename Comparable>
class MaryTree {

private:
  class Node
  {
  public:
    Comparable element;
    std::forward_list<Node> children;
  };

  Node *root;

public:
  // Rule-of-3 + functions to add, find and remove nodes
};
```

![m-ary tree](m-ary_tree.png)


Note: Some implementations only implement the node class and represent the tree as a reference or pointer to the root node.


## Binary Trees
A binary tree is a tree in which no node can have more than two children.

Complexity: The average depth of a binary tree is (under some assumptions: random insertion and no deletions) $O(\sqrt{N})$. The worst case depth is $N - 1$ (a single branch going all the way down).

The node structure is similar to a linked list node

```cpp
template <typename Comparable>
class BinaryNode
{
public:
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;
}
```

`nullptr` represents missing children.


### Types of tree traversals

Visiting nodes is called [tree traversal](https://en.wikipedia.org/wiki/Tree_traversal). Traversal works for m-ary trees, but we define it here for the special case of binary trees with 
a node N and a left (L) and right (R) subtree as children.

**Depth-first traversals:**

* **preorder** (NLR): process node before children.
* **inorder** (LNR) follow each path to the leaf-node (left to right). 
* **postorder** (LRN): process all subtrees before the node.

Coming back up from a leaf to a node to process a different subtree is called _backtracking_.

**Breath-first traversal***

* **level-order**: process the tree by level (may need an extra data structure like a queue or a stack).


### Application Examples: Expression Trees

An expression tree represent an expression with binary operators like $(a + b) * c * (d + e)$.
It can be used to create 
  - infix notation: inorder transversal (LNR) = left expression in parentheses then operator and then the right subtree in parentheses. 
  - postfix notations: postorder traversal (LRN) = process operator after the children (no need for parentheses). 
  - prefix notations: preorder traversal (NLR) = process operator first (no need for parentheses). 

  Construction from postfix notation with a stack: 
  1. Read postfix expression one symbol at a time
  2. If the next symbol is an operand then push a pointer to it on the stack.
  3. If it is a operator then 
     a. pop two operand pointers from the stack and 
     b. create a tree with the operator as its root and the two operands as its children. 
     c. Push a pointer to the tree on the stack

[Parse trees](https://en.wikipedia.org/wiki/Parse_tree) are $M$-ary expression trees that are used in co1mpiler design. In natural language processing such trees are called syntax trees. 


## Binary Search Tree

Binary search trees are one of the most important tree structures used to find elements quickly.

_Assumption:_ Items can be ordered and the are no duplicates (i.e., a total order).

_Definition:_ In a binary search tree, all items in each left subtree are smaller than the items in the right subtree.

See [BinarySearchTree](BinarySearchTree) for code.

Since items are stored in sorted order, a simple **inorder traversal** results in sorted output.
Inserting $N$ items takes $O(N log\ N)$ time and traversing the tree takes $O(N)$
which gives a sorting algorithm that is $O(N\ log\ N)$. 

### Complexity 
The depth $d$ of a _binary search tree_ leads to $O(d)$ operations (for all but deleting and copying the whole tree). The average tree depth $d$ is $O(log\ N)$ under the
assumption that all insertion sequences are equally likely. Remember, $O(log\ N)$ means 
that the problem size is halved with each step.

Since $O(log\ N)$ is relatively small, operations can be defined/implemented recursively without running out of stack space.

_Problem:_ The assumption of $O(log\ N)$ average running time is only true if no deletions are 
used! Deletions often replace a node with a node for the right subtree, resulting in an **unbalanced tree** that is left heavy!

## AVL Trees

An AVL (Adelson-Velskii and Landis) tree is a binary search tree with the following **balance condition:**

> For every node in the tree, the height of the left and the right subtree can
differ by at most 1.

We can maintain the balance information (height) in the node structure. The height of an empty tree is defined as -1.

```cpp
template <typename Comparable>
class AVLNode
{
public:
    Comparable element;
    AVLNode *left;
    AVLNode *right;
    int height;
}
```

If the difference is larger, then the tree needs to be organized where the 
last insertion happened.
This keeps the tree balanced with a depth close to $O(log\ N)$.


### Balancing

Insertion/deletion may break the balancing condition and we will need to rebalance the tree using a **rotation**. 
We need 

* a single rotation for "outside" insertions (left-left and right-rigth) and 
* a double rotation for "inside" insertions (left-right and right-left).

See [slides](https://github.com/mhahsler/CS2341/blob/main/Chapter4_Trees/slides/AVL_trees.pdf) for details.

See [AVLTree](AVLTree) for complete code.

## B-Trees

We need secondary storage access for data that does not fit into main memory. Secondary storage
is typically organized in blocks (file system, disk) and access is slow compared to main memory access so the Big-Oh method does not work (remember that it assumes that all operations take the same amount of time).

_Problem:_ Every level in the tree requires a storage access.

_Idea:_ Reduce tree depth by making the tree wider leading to a balanced M-ary search tree.

Common implementations are the [B-tree](https://en.wikipedia.org/wiki/B-tree) and the [B+ tree](https://en.wikipedia.org/wiki/B%2B_tree).

B-tree properties:
* Data is organized in sorted order.
* All data is stored in the leaf nodes as a sorted array with space for $L$ values. 
  At least $ceil(L/2)$ are occupied.
* Each non-leaf node has space for $M$ key/pointer pairs. At least $ceil(M/2)$ are occupied. 
  The key is the minimum value of the entries following the pointer.
* $M$ and $L$ are chosen to fit into a storage block that can be accessed with a single read.    
  Pointers are block addresses.

The requirement that at least half the places are filled balances the tree. Insertion may lead to a split of a node into two half full nodes.

Operations are $O(log\ N)$


## STL Implementations of Binary Search trees

STL provides the associative containers [std::set](https://cplusplus.com/reference/set/set/) and [std::map](https://cplusplus.com/reference/map/map/) based on binary search trees.
The stored objects need to be `Comparable` with a definition of `bool operator<(const &) const` 
(since $a < b$ can be used for $b < a$, we can also get $a == b$) or a function object (see [comparator example in Chapter 1](../Chapter1_Programming/comparator)).


Examples: [How to use STL sets and maps](STLSetMap)

