# DSList


## Vector recap:

- Some problems with array implementation of a vector
    - inserting elements requires $O(N)$ to copy the whole array. Even if we have space 
      at the end, then we need to move all elements.
    - resizing operation is expensive.
    - requires contiguous memory allocation.
- Some benefits of array implementation of vector
    - $O(1)$ access to an item in the vector given some index.

## Linked Lists

Linked lists allocate each element separately and link them with pointers. Linked lists can be 
- singly linked or 
- doubly linked.

### Singly Linked List

* we can only move in the forward direction.
* managing the pointers is easier.
* STL provides [`std::forward_list<T>`](https://cplusplus.com/reference/forward_list/forward_list/)

Nodes are defined as:

```cpp
 struct Node
    {
        Object data;
        Node *next;
    };
```

Example: A [singly-linked list using iterators](DSList_iter.h) and [main.cpp](main.cpp).

A sentinel node is an "empty" node that is used to avoid special code for empty lists.

Exercise: Implement a [singly-linked list using position and a sentinel node](DSList.h).

### Doubly Linked List

* we can only move forward and backward.
* managing the pointers is more difficult for insertion/deletion.
* STL provides [`std::list<T>`](https://cplusplus.com/reference/list/list/)

Nodes are defined as:

```cpp
 struct Node
    {
        Object data;
        Node *prev;
        Node *next;
    };
```

### Time Complexity

Each element is allocated individually so we do not need contiguous memory and all the copying.
What is the time complexity for 

* inserting a new element?
* finding an element?
* removing an element?
* deleting the list?
