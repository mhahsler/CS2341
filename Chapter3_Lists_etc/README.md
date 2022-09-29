# Chapter 3: Lists, Stacks, and Queues 

## Abstract Data Types (ADT)

ADT extend the idea of basic data types. They are not about the 
implementation, but a mathematical abstraction which defines

* a set of objects, and
* operations (e.g., insert, delete).

## Iterators

Iterators are an abstraction to represent a position in a ADT. This is similar to the index in 
an array. STL provides [std::iterator](https://cplusplus.com/reference/iterator/iterator/?kw=iterator) and we use the STL notation below.

Iterators are:
* a generalization of pointers to elements in the ADT.
* implemented as a nested class in the ADT implementation that has a `*` dereferencing operator (like pointers).
* know how to get to the next element with an overloaded `operator++()` and `operator++(int)` 
  (bidirectional iterators also have `operator--()` and `operator--(int)`)
* An ADT can be asked for an iterator pointing to the first element (`begin()`) and 
an iterator pointing to the _past-the-end_ element (`end()`).


Examples: 
* [STL iterator use](Iterator)
* Implement your own iterator: See Vector and Lists below.

## Vectors

### Interface
* `size()` number of elements.
* `clear()` remove all elements.
* `empty()` is the stack empty?
* access via `operator[index]` or `at(index)`.

STL provides: [std::vector](https://cplusplus.com/reference/vector/vector/)

Example: [DSVector](DSVector)

Example: Using DSVector to create a [string class](DSString)

## Matrix

STL: Interestingly there is no support available.

Example: [DSMatrix](DSMatrix)

## Linked Lists

### Interface
* `size()` number of elements.
* `clear()` remove all elements.
* `empty()` is the stack empty?
* `insert(iterator)` add an element.
* `erase(iterator)` delete an element.

STL provides: [std::list](https://cplusplus.com/reference/list/list/)

Example: [DSList](DSList) 


Stacks and queues are implemented using vectors/array or lists. 

## Stacks

For stacks information is added to the top and taken from the top. Stacks are said to operate in a LIFO (Last-In-First-Out) fashion.

### Interface
* `push(value)` add an element on top.
* `pop()`  remove the top element.
* `top()` look at the top element.
* `empty()` is the stack empty?

STL provides: [`std::stack`](https://cplusplus.com/reference/stack/stack/)

### Implementation

Stacks are just an interface to a data structure. Typical implementations are:
* Vector or large array with `topOfStack` to store the index of the element on top. Empty stack often has `topOfStack == -1`.
* List: `push()`/`pop()` add/remove an element from the front of the list.

Lists are more memory efficient and vectors are faster.

### Application Examples
* Check code for **balanced brackets**. Algorithm: Read the program character-by-character. 
  Push `({[` on the stack and take them off when the corresponding `)`, `}`, or
  `)` is seen. Any error or a non-empty stack at the end of the code indicates a problem.

* Calculate the results of **postfix expressions** like `6 5 2 3 + 8 * + 3 + * = 288`. 
  Algorithm: Read the expression left-to-right. Push numbers on the stack. For operations, pop the top two elements, perform the operation and push the result on the stack. The value remaining on the stack at the end is the result.

* Convert **infix to postfix expressions**: `6 * (5 + (2 + 3) * 8 + 3)  => 6 5 2 3 + 8 * + 3 + *`
  Algorithm: Read the expression left-to-right. 
  - Add any numbers directly to the output.
  - Push `(` on the stack.
  - For `)` do: pop from the stack and add the value to the output till an opening 
    parenthesis is reached on the stack (also pop the `(` and ignore).
  - For operators: while the operators on the stack have higher precedence, pop them and add them to the output. 
      Then push the new operator on the stack.

* **Function call stack:** Issue: Prior to a function call, all local variables and the return address need to be saved.
  This information is stored as a _stack frame_ on the _function call stack_ 
  and a function call pushes a new stack frame on the function call stack.
  See example [factorial](../Chapter1_Overview/factorial).


## Queues

Insertion is done on one end and deletion on the other. This is called FIFO (First-In-First-Out).

_Note_: Simple queues are different from **priority queues** which are introduced under the name **heap** later.

### Interface
* `enqueue(value)` insertion
* `dequeue()` deletion

STL provides: [`std::deque`](https://cplusplus.com/reference/deque/deque/) as a double-ended queue.

### Implementation

Implemented as a list (linked list, vector, or array). List implementation is trivial.

The array implementation keeps indices for `front` and `back` and `currentSize = back - front + 1`. A problem is that we run out of space at one end. This can be addressed using a _circular array_implementation.

### Application Examples

* Printer queue: printing on a first-come first-served basis
* IO: buffers, iostream 
* Many algorithms use queues to keep subproblems to be solved later.