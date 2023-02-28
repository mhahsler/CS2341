# DSList

Lists are an ADT implementation. The typical interface includes:

- insert a new element at the beginning (also at the end for a doubly linked list). 
- delete the first (also last for doubly linked list).
- traversing the whole list.
- find an element by value.
- delete an element by value (or using an index or iterator).


## Vector recap:

- Some problems with array implementation of a vector
    - inserting elements requires $O(N)$ to copy the whole array. Even if we have space 
      at the end, we still need to move all elements.
    - resizing operation is expensive.
    - requires contiguous memory allocation.
- Some benefits of array implementation of vector
    - $O(1)$ random access to an item in the vector given an index
      (remember pointer arithmetic).

## Linked Lists

Linked lists allocate each element separately and link them with pointers. Linked lists can be 
- singly linked (only forward links) or 
- doubly linked (bi-directional links).

### Singly Linked List

* We can only move from one node to the next in the forward direction.
* Managing the single pointer in each node is easy.
* STL provides [`std::forward_list<T>`](https://cplusplus.com/reference/forward_list/forward_list/)

Nodes are defined as:

```cpp
 struct Node
    {
        Object data;
        Node *next;
    };
```

Note: In C++, `structs` are just classes with all public members.

Exercise: Implement a singly liked list with the following functions:
- `insert_front()`
- `delete_front()`
- `size()`
- `empty()` ... is the list empty
- `clear()` ... make the list empty

Example: A [singly-linked list using iterators](DSList_iter.h) and [main.cpp](main.cpp).

Some implementations use sentinel nodes.
A sentinel node is an "empty" node that is used to avoid special code for empty lists.

### Doubly Linked List

* We can only move forward and backward.
* Managing the pointers is more difficult for insertion/deletion.
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

Each element is allocated in a linked list individually, so we do not need contiguous memory and we do not need to copy/move data for insertion and deletion.
What is the time complexity for the following operations using lists or arrays (Big-Oh notation)?


| Operation                         | Array | STL vector | Singly Linked List | Doubly Linked List |
| --------------------------------- | ----- | -----------| ------------------ | ------------------ |
| insert a new element at a random location |            |                    |                    |
| insert a new element (front)      |       |            |                    |                    |
| insert a new element (back)       |       |            |                    |                    |
| access an element (with index)    |       |            |                    |                    |
| access an element (with iterator) |       |            |                    |                    |
| find an element by value          |       |            |                    |                    |
| delete an element                 |       |            |                    |                    |
| delete the whole data structure   |       |            |                    |                    |
