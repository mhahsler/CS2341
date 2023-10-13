# Chapter 4: Trees, Sets, and Maps

Lists have for many operations $O(N)$ (e.g., search, insertion at an arbitrary location) 
which is slow for large amounts of data.
Trees can have an average time complexity of $O(log\ N)$.

Recursive definition: A tree $T$

* is a collection of __nodes__ which contain the information stored in the tree.
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
* The path from a node to the farthest leaf node is called the node's __height.__ Note that the height is the number of levels minus 1.
* A tree where a node can have at most $M$ children is called an __$M$-ary tree.__

Observations:
* A tree is a special type of graph with only a single path from the root to each leaf.
* A collection of $N$ nodes (one is the root node) has $N - 1$ edges.

## Implementation of General Trees

We implement a tree as a set of connected `Nodes`. The data that is stored in each node is often called the _key_.

Each node in a general tree ($M$-ary tree) can have a variable list of children. We can store it
in a singly-linked list like the [`std::forward_list`](https://en.cppreference.com/w/cpp/container/forward_list).

```cpp
template <typename Object>
class MaryTree {

private:
  class Node
  {
  public:
    Object key;  // the data that the node stores
    std::forward_list<Node> children;
  };

  Node *root;

public:
  // Rule-of-3 + functions to add, find and remove nodes
};
```

![m-ary tree](m-ary_tree.png)


Note: Some implementations only use the node class and represent the tree as a reference or pointer to the root node.

Example: Unix file system. Try the `tree` command on a linux machine. It performs a preorder traversal (depth-first; children are processed after the parent).



## Binary Trees
A binary tree is a tree in which no node can have more than two children.

Complexity: The average depth of a binary tree is (under some assumptions: random insertion and no deletions) $O(\sqrt{N})$. The worst case depth is $N - 1$ (a single branch going all the way down).

The node structure is similar to a linked list node

```cpp
template <typename Object>
...

class BinaryNode
{
public:
    Object key;
    BinaryNode *left;
    BinaryNode *right;
}
```

`nullptr` represents missing children.


## Tree Traversal

Visiting all nodes in a tree is called [tree traversal](https://en.wikipedia.org/wiki/Tree_traversal). There are several ways we can traverse a tree.


### Depth-first traversal
Depth-first traversal works for any m-ary tree, but we define it here for the special case of binary trees.
We will use the following notation:

* **N** stands for processing the **node.** For example, printing the value stored in the node.
* **L** means going to the **left child.**
* **R** means going to the **right child.**

Once a leaf node is reached and processed, then we go back to the node we came from to process a different subtree. 
This is often called _backtracking_.

The three traversal orders are:

* **preorder** (NLR): process node before children. **Pre** means the node is processed fist.
* **inorder** (LNR) fist follow the left child and then process the node before following down the right child.
  **In** means that the node is processed in the middle. For binary search trees this results in processing the 
  nodes in sort order.
* **postorder** (LRN): process the left and then the right subtree before the node is processed. **Post** means the node
  is processed last.

Recursive implementation

```cpp
void traverseNLR(Node& n) {
  cout << n.key;            // N
  taverseNLR(n.leftChild);  // L
  taverseNLR(n.rightChild); // R
}

void traverseLNR(Node& n) {
  taverseLNR(n.leftChild);  // L
  cout << n.key;            // N
  taverseLNR(n.rightChild); // R
}

void traverseLRN(Node& n) {
  taverseLRN(n.leftChild);  // L
  taverseLRN(n.rightChild); // R
  cout << n.key;            // N
}
```

For an iterative implementation, you need a stack.


### Breadth-first traversal

Also called **level-order**: process the tree by level (may need an extra data structure like a queue to store unprocessed nodes).
You will learn more about breadth-first traversal when you learn about graphs in algorithms. 



## Application Examples: Expression Trees

An expression tree represent an expression with binary operators like $6 * (5 + (2 + 3) * 8 + 3)$.

**Construction** 

If we have infix notation then we can convert it first to postfix notation using a stack: 
  `6 * (5 + (2 + 3) * 8 + 3) => 6 5 2 3 + 8 * + 3 + *`

*Algorithm:* 
```
Read the expression left-to-right. Do the following for:
  - Operand: Add any operand (here a number) directly to the output.
  - `(`: push ( on the stack.
  - `)`: pop all operators from the stack and add them to the output till an opening
    parenthesis is reached on the stack (also pop the `(` and ignore it).
  - Operator: pop all operators with higher or equal precedence (order of operations) 
    than the new operator from the stack and add them to the output (if any).
    Push the new operator on the stack.
  Once the expression is done, pop any remaining operator and add it to the output.
```


We can create an expression tree from postfix notation with a stack.

*Algorithm:*
```
  Read postfix expression one symbol at a time.
  - Operand: create a new node for the operand and push a pointer to the node on the stack.
  - Operator: 
     a. pop two operand nodes from the stack and 
     b. create a tree with the operator as its root and the two operands as its children. 
     c. push a pointer to the tree on the stack
  Once the expression is completely processes, you should have a pointer to the expression tree on the stack.
```

Example: [Converter](https://www.web4college.com/converters/infix-to-postfix-prefix.php) 

Applications of the parse tree: create 
  - infix notation: inorder tree transversal (LNR) = left expression in parentheses then operator and then the right subtree in parentheses. 
  - postfix notations: postorder tree traversal (LRN) = process operator after the children (no need for parentheses). 
  - prefix notations: preorder tree traversal (NLR) = process operator first (no need for parentheses). 


[Parse trees](https://en.wikipedia.org/wiki/Parse_tree) are $M$-ary expression trees that are used in compiler design. In natural language processing such trees are called syntax trees. 

## Exercises
1. Draw the stack operations to convert $6 * (5 + (2 + 3) * 8 + 3)$ into postfix notation.  
2. Convert the postfix notation into an expression tree.
3. Convert the expression tree back into infix notation.

## Binary Search Tree

* [Unbalanced Binary Search Trees](BinarySearchTree).
* [Balanced Binary Search Trees (AVL Trees)](AVLTree).


STL implementations of Binary Search trees: STL provides 
  [std::set](https://cplusplus.com/reference/set/set/) and [std::map](https://cplusplus.com/reference/map/map/) based on binary search trees.
  The stored key objects need to be `Comparable` with a definition of `bool operator<(const &) const` 
  (since $a < b$ can be used for $b < a$, we can also get $a == b$) or a function object 
  (see [comparator example in Chapter 1](https://github.com/mhahsler/CS2341/tree/main/Chapter1_Programming/comparator)).

Examples: [How to use STL sets and maps](STLSetMap)

Example: **Binary Tree Search is equivalent to Binary Search.** A balanced search tree can be stored compactly in a vector using inorder traversal.

## Maps

Maps are [associative containers](https://en.wikipedia.org/wiki/Associative_containers) that relate a key to a value. That is, it maps
the set of keys onto the set of values in a 1-1 fashion.

$$f: keys \rightarrow values$$

The purpose is to access the value fast given that we know the key. Note that a value can also be a collection of individual values (e.g., a list or a vector).

Requirements:
* keys need to be unique.
* keys need to be orderable (be comparable with `operator<()`).

Implementations:
* A binary search tree. The node has in addition to the key also a member variable to store the value.
  ```cpp
  template <typename KeyType, Typename ValueType>
  ...

  class MapTreeNode
  {
  public:
    KeyType key;
    ValueType value;
    BinaryNode *left;
    BinaryNode *right;
  }
  ```


* A hash table (we will talk about hashing later).

STL provides [std::map](https://cplusplus.com/reference/map/map/).


## B-Trees

We need **secondary storage** access for data that does not fit into main memory. Secondary storage
is typically organized in blocks (file system, disk) and access is slow compared to main memory access 
(takes 100,000x for random access)
so the **Big-Oh method does not work** (remember that it assumes that all operations take the same amount of time).

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

### Applications 
* File systems: Quick random access to an arbitrary block in a particular file. 
* Databases: Store auxiliary index structures for faster retrieval in very large databases.


## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)