# Chapter 3: Lists, Stacks, and Queues 

Basic data structures are defined as **ADT**s (Abstract Data Types). ADTs are not about the 
implementation, but a mathematical abstraction which define

* s set of objects, and
* operations (e.g., insert, delete).


## Vectors

* Vectors: [DSVector](DSVector)

## Linked Lists

* Linked lists: [DSVector](DSVector) 



Stacks and queues are implemented using vectors/array or lists. 

## Stacks

### Interface
* `push()` add an element on top.
* `pop()`  remove the top element.
* `top()` look at the top element.
* `empty()` is the stack empty?

STL provides: [`std::stack`](https://cplusplus.com/reference/stack/stack/)

### Implementation
* Vector or large array with `topOfStack` to store the index of the element on top. Empty stack has `topOfStack == -1`.
* List: `push()`/`pop()` add/remove an element from the front of the list.

### Application Examples
* Check code for **balanced brackets**: push `({[` on the stack and take them off when the corresponding `)`, `}`, or
  `)` is seen. Any error or a non-empty stack at the end of the code indicates a problem.
* Calculate the results of **postfix expressions** like: `6 5 2 3 + 8 * + 3 + * = 288`
  Rule: push numbers on the stack and apply the operation to the last two numbers on the stack. Then push the
  result on the stack.
* Convert **infix to postfix expressions**: `((2 + 3) * 8 + 5 + 3) * 6  => 6 5 2 3 + 8 * + 3 + *`
  Rule: Push operators on the stack. Before pushing an operator, check if the last operator on the stack has higher priority.
  If so, pop and perform the operation. Opening parentheses have the highest priority and can only be 
  popped by closing parentheses.
* **Function call stack:** Issue: Prior to a function call, all local variables and the return address need to be saved.
  This information is stored as a _stack frame_ on the _function call stack_ 
  and a function call pushes a new stack frame on the function call stack.
  See example [factorial](../Chapter1_Overview/factorial).


## Queues

Insertion is done on one end and deletion on the other.

_Note_: Simple queues are different from priority queues which are introduced under the name _heap_ later).

### Interface
* `enqueue()` insertion
* `dequeue()` deletion

STL provides: [`std::deque`](https://cplusplus.com/reference/deque/deque/) as a double-ended queue.

### Implementation

Implemented as a list (linked list, vector, or array). List implementation is trivial.

The array implementation keeps indices for `front` and `back` and `currentSize = back - front + 1`. A problem is that we run out of space at one end. This can be addressed using a _circular array_implementation.

### Application Examples

* Printer queue: printing on a first-come first-served basis
* IO: buffers, iostream 
* Many algorithms use queues to keep subproblems to be solved later.







