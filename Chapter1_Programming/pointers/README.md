# Pointers

# Dynamic Memory Allocation 

Regular memory allocation (e.g., the declaration of a variable) happens on the **function call stack**. 
How much memory is needed is determined at compile time. This type of memory allocation is often also called **static memory allocation** 
or [**stack-based memory allocation**](https://en.wikipedia.org/wiki/Stack-based_memory_allocation). 

**Dynamic memory allocation** is used when the amount of memory needed is not know at compile time (e.g., create a list to store user input, but we do not know how many elements we will need). I is called dynamic 
because it happens dynamically during the runtime of the program and not at compile time.
This type of allocation is also called **manual memory allocation** (it is explicitly done by the programmer), or **heap-based memory allocation.**

The programmer uses the following keywords for dynamic memory allocation:

 * `new`: dynamic memory allocation on the heap. It returns a pointer to the allocated memory.
 * `delete` and `delete[]`: return allocated memory when it is no longer used.
 
**Caution:** Dynamic memory allocation is prone to leading to memory leaks!!! \
A simple rule is that every `new` needs a `delete`.

**Advice:** Use `new` only when you have to. Data structures in the STL often do dynamic memory management for us.
 
Managed languages (like Java and Python) provide automatic memory management. A popular strategy is  
  [garbage collection](https://en.wikipedia.org/wiki/Garbage_collection_(computer_science)) with reference counts.  

# Pointers

Pointers store the memory address of an object.
 
 * `datatype *` declares a pointer variable.
 * `->` (arrow operator) accesses members with a pointer to an object. Same as the `.` operator but instead 
   of the object name (i.e., reference), we have a pointer to the object.
 * `==` pointer addresses are compared not the objects!
 * `&` (address-of-operator) returns the address of a variable (can be stored in a pointer to the variable).
 * `*` (dereference operator) returns the object at the address the pointer points to.

**Important Notes:** 
* References (`int& i_ref = i;`) and 
  the address-of-operator (`&i`) are not related. A reference is unrelated to pointers. It is just a second name for an object in memory. The address-of-operator returns a pointer 
  (the memory address). 
* The `*` has two meanings: `int* p;` creates a pointer to an int value and the dereference operator in front of a 
  pointer (`*p`) follows the pointer and returns the value pointed to. 
* While some programmers prefer to write `int* p;` to stress that the `*` modifies the declaration to declare an int pointer,
  it is often also written as `int *p;`. The same is true for defining references.

 
```cpp
int main() {

  int a = 10;
  int* ptr = &a; // create a pointer to a using the address-of-operator
  int& b = a;   // create a reference for a

  std::cout << "a = " << a << "; *ptr = " << *ptr << "; b = " << b << "\n";

  b++;
  std::cout << "a = " << a << "; *ptr = " << *ptr << "; b = " << b << "\n";

  return 0;
}
```


# Arrays and Pointers

Arrays are a relict from C. They can be allocated on the stack or on the heap. The name of the array can be assigned to a
pointer to the first element of the array. We can add or subtract numbers from a pointer to move in the array 
forward or backward. This is called pointer arithmetic.

```cpp
int main() {

  // create an array on the stack (you can also use int a[4];)
  int a[] = {0,1,2,3};
  int* a_ptr = a;

  // this is the same as a[2] or *(a+2)
  a_ptr += 2;
  std::cout << "a_ptr point to value:" << *a_ptr << "\n";

  --a_ptr;
  std::cout << "a_ptr point to value:" << *a_ptr << "\n";

  // allocate an array on the heap
  int* b = new int[4];
  *b = 1;

  delete [] b;

  return 0;
}
```

**Advice:** C arrays are horrible! The size is fixed, they don't know how big they are, and the boundaries are not checked!
Only use them if you have to. A better solution is `std::vector`.

# Exercises

* Draw a memory diagram for the main function in the example in [IntCell_ptr](IntCell_ptr).
* Use the debugger to run the program and verify that your memory diagram is correct.

# Question
* Pointers store memory addresses. Why do we need to specify the datatype it points to? Example:
`int*` vs. `double*`

