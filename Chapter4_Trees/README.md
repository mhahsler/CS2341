# Chapter 4: Trees, Sets, and Maps

Lists have for most operations $O(N)$ which is slow for large amounts of data.

Trees have $O(log N)$.

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


## Binary Tree
In a binary tree is a tree in which no node can have more than two children.

Complexity: The average depth of a binary tree is $O(\sqrt{N})$. The worst case depth is $N - 1$ (a single branch going all the way down).

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
The stored objects need to be `Comparable` with a definition of `bool operator<(const &) const` or a function object (see [example in Chapter 1](../Chapter1_Programming/comparator)).


Complexity: The average depth of a _binary search tree_ is lower than a general tree with $O(log N)$. Since this is relatively small, operations can be defined/implemented recursively without
running out of stack space.



