# Chapter 3: Lists, Stacks, and Queues 

# Abstract Data Types (ADT)

ADT extend the idea of basic data types. They are not about the 
implementation, but a mathematical abstraction which defines

* a set of objects, and
* operations (e.g., insert, delete).

Data structures are different implementations of abstract data types.
Often the name [**container**](https://en.wikipedia.org/wiki/Container_(abstract_data_type))) is used for ATDs.
The STL's main purpose it to provide [containers](https://cplusplus.com/reference/stl/) implementing all commonly used
data structures.

## Iterators

[Iterators](https://en.wikipedia.org/wiki/Iterator) are an abstraction to represent a position in an ADT. This is similar to the index in an array. STL provides [std::iterator](https://cplusplus.com/reference/iterator/iterator/?kw=iterator) and we use the STL notation below.

Iterators are
* a generalization of pointers to elements in the ADT.
* implemented as a nested class in the ADT implementation that has a `*` dereferencing operator (like pointers).
* know how to get to the next element with an overloaded `operator++()` and `operator++(int)` 
  (bidirectional iterators also have `operator--()` and `operator--(int)`)
* can be compared with `operator==` and `operator!=` but **do not support** `operator<`! 

An ADT can be asked for an iterator pointing to the first element (`begin()`) and 
an iterator pointing to the _past-the-end_ element (`end()`).


Examples: 
* [STL iterator use](Iterator)
* Implement your own iterator: See Vector and Lists below.

# Some ADTs

## Vectors

**Objects:** Values are stored typically consecutively in memory (like an array).

**Operations**
* `size()` number of elements.
* `clear()` remove all elements.
* `empty()` is the vector empty?
* access via `operator[index]` or `at(index)`.

STL provides [std::vector](https://cplusplus.com/reference/vector/vector/)

Example implementation: [DSVector](DSVector)

## Matrix

**Objects:** rows, columns, and cells.

**Operations:** get the dimension and access an element given by row and column.


STL: Interestingly there is no support available.

Example implementation: [DSMatrix](DSMatrix)

## Linked Lists

**Objects:** List nodes

**Operations**
* `size()` number of elements.
* `clear()` remove all elements.
* `empty()` is the stack empty?
* `insert()` add an element.
* `erase()` delete an element.

STL provides: [std::list](https://cplusplus.com/reference/list/list/)

Implementation details: [DSList](DSList)  

## Stacks

For stacks information is added to the top and taken from the top. Stacks are said to operate in a LIFO (Last-In, First-Out) fashion.

**Objects:** Values

### Operations
* `push(value)` add an element on top.
* `pop()`  remove the top element.
* `top()` or `peek()` look at the top element.
* `empty()` is the stack empty?

STL provides: [`std::stack`](https://cplusplus.com/reference/stack/stack/)

### Implementation

Stacks are just an interface to a different data structure. Typical implementations are:
* Vector or large array with a variable `top` to store the index of the element on top. Since indices start with 0, the size of the stack is 
  `size = top + 1`. An empty stack has `top == -1`.
* List: use `push_front()`/`pop_front()` add/remove an element from the front of a singly-linked list.

Lists are more memory efficient and vectors are faster.

### Application Examples: 
* Check code for **balanced brackets**.
  Algorithm: Read the program character-by-character. Push `({[` on the stack and take them off when the corresponding `)`, `}`, or `)` is seen. Any error or a non-empty stack at the end of the code indicates a problem.

* Calculate the results of **postfix expressions** like `6 5 2 3 + 8 * + 3 + * = 288`. 
  Algorithm: Read the expression left-to-right. Push numbers on the stack. For operations, pop the top two elements, perform the operation and push the result on the stack. The value remaining on the stack at the end is the result.

* Convert **infix to postfix expressions**: `6 * (5 + (2 + 3) * 8 + 3)  => 6 5 2 3 + 8 * + 3 + *`
  Algorithm: Read the expression left-to-right. 
  - Add any numbers directly to the output.
  - Push `(` on the stack.
  - For `)` do: pop from the stack and add the value to the output till an opening 
    parenthesis is reached on the stack (also pop the `(` and ignore it).
  - For operators: while the operators on the stack have higher precedence (note that `(` has the highest precedence), 
    pop them and add them to the output. 
    Then push the new operator on the stack.
  - Once the expression is done, pop any remaining operator and add it to the output.

* **Function call stack:** Issue: Prior to a function call, all local variables and the return address need to be saved.
  This information is stored as a _stack frame_ on the _function call stack_ 
  and a function call pushes a new stack frame on the function call stack.
  See example [factorial](../Chapter1_Programming/factorial).


## Queues

Insertion is done on one end and deletion on the other. This is called FIFO (First-In, First-Out).

_Note_: Simple queues are different from **priority queues** which are introduced under the name **heap** later.

**Objects:** Values

### Operations
* `enqueue(value)` insert an element.
* `dequeue()` remove an element.
* `empty()` is the queue empty?

STL provides: [`std::deque`](https://cplusplus.com/reference/deque/deque/) as a double-ended queue.

### Implementation

Implemented as a list (linked list, vector, or array). 

Doubly-linked list implementation is trivial and uses `push_back()` and `pop_front()`. A doubly-linked list is used to make `push_back()` efficient (`O(1)`).

The array implementation keeps indices for `front` and `back` and `size = back - front + 1`. A problem is that we run out of space at one end. This can be addressed using a _circular array_ implementation.

### Application Examples

* Printer queue: printing on a first-come first-served basis
* I/O: buffers, iostream 
* Many algorithms use queues to store subproblems to be solved later.

## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)
