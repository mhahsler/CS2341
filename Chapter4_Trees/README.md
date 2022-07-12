# Chapter 4: Trees, Sets, and Maps

Lists have for most operations $O(N)$ which is slow for large amounts of data.
Trees can have an average runtime of $O(log\ N)$.

Recursive definition: A tree $T$

* is a collection of _nodes_.
* is empty or has a single _root node_ $r$.
* has zero or more nonempty subtrees $T_1, T_2, ..., T_k$ whose roots are connected by a 
  _directed edge_ from $r$.

More naming conventions:
* Two nodes are called _parent_ and _child_ of each other if the parent as a directed edge 
    to the child.
* Nodes without children are called _leaves._
* A _path_ is a sequence along edges. The _length_ of the path is the number of edges.
* The _depth_ of a node is the length of the path from the root node $r$ to the node 
  (there is only on path). 

A collection of $N$ nodes (one is the root node) has $N - 1$ edges.


## Binary Trees
In a binary tree is a tree in which no node can have more than two children.

Complexity: The average depth of a binary tree is (under some assumptions of no deletions) $O(\sqrt{N})$. The worst case depth is $N - 1$ (a single branch going all the way down).

The node structure is similar to a linked list node

```cpp
template <typename T>
class BinaryNode
{
public:
    T element;
    BinaryNode *left;
    BinaryNode *right;
}
```

`nullptr` represent missing children.

See [BinarySearchTree](BinarySearchTree) for complete code.

### Application Examples: Expression Trees (parse trees) 

An expression tree represent an expression with binary operators like $(a + b) * c * (d + e)$.
It can be used to create 
  - infix notation: inorder transversal = create left expression in parentheses first. 
  - postfix notations: postorder traversal = process operator after the children. 

  Construction from postfix notation with a stack: 
  1. Read postfix expression one symbol at a time
  2. If the next symbol is an operand then push a pointer to it on the stack.
  3. If it is a operator then 
     a. pop two operand pointers from the stack and 
     b. create a tree with the operator as its root and the two operands as its children. 
     c. Push a pointer to the tree on the stack

## Binary Search Tree

_Assumption:_ Items can be ordered and the are no duplicates (i.e., a total order).

_Definition:_ In a binary search tree, all items in each left subtree are smaller than the items in the right subtree.

STL provides the associative containers [std::set](https://cplusplus.com/reference/set/set/) and [std::map](https://cplusplus.com/reference/map/map/) based on binary search trees.
The stored objects need to be `Comparable` with a definition of `bool operator<(const &) const` 
(since $a < b$ can be used for $b < a$, we can also get $a == b$) or a function object (see [example in Chapter 1](../Chapter1_Programming/comparator)).

### Complexity 

The depth of a _binary search tree_ $d$ leads to $O(d)$ operations (for all but deleting and copying the whole tree). The average tree depth $d$ is $O(log\ N)$ under the
assumption that all insertion sequences are equally likely. Remember, $O(log\ N)$ means 
that the problem size is halved with each step.

Since $O(\mathem{log}\  N)$ is relatively small, operations can be defined/implemented recursively without running out of stack space.

_Problem:_ The assumption of $O(log \N)$ average running time is only true if no deletions are 
used! Deletions often replace a node with a node for the right subtree, resulting in an **unbalanced tree** that is left heavy!

## AVL Trees

An AVL (Adelson-Velskii and Landis) tree is a binary search tree with the **balance condition**
that the height (= max depth) of the left and right subtree can only differ by 1. This keeps the tree depth close to $O(log\ N)$.

We can maintain the balance information (height) in the node structure. The height of an empty tree is defined as -1.

Insertion: We need to update the height information on the way back to the root. Issue: insertion may break the balancing condition and we will need to rebalance the tree using a **rotation**.

Single vs double rotation.

See [AVLTree](AVLTree) for complete code.







