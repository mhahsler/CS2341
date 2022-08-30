# Pointers
 
 * `new`: dynamic memory allocation on the heap
 * `delete`: C++ does not use garbage collection! 
   - Memory leaks!!! Every `new` needs a `delete`.
   - Use `new` only when you have to. Data structures in the STL often do dynamic memory allocation for us.
 * `datatype *` declares a pointer variable.
 * `->` (arrow operator) accesses members with a pointer to an object. Same as the `.` operator but instead of the object name, we have a pointer to the object.
 * `==` pointer addresses are compared not the objects!
 * `&` (address-of-operator) returns the address of a variable (can be stored in a pointer to the variable).
 * `*` (dereference operator) returns the object at the address the pointer points to.
 

**Important Notes:** 
* References (`int& i_ref = i;`) and 
  the address-of-operator (`&i`) are not related. A reference is unrelated to pointers. It is just a second name for an object in memory. The address-of-operator returns a pointer 
  (the memory address). 
* The `*` has two meanings: `int*` creates a pointer to an int value and the `*` operator in front of a pointer dereferences the pointer (i.e., follows the arrow to). 

**Questions:**
* Pointers store memory addresses. Why do we need to specify the datatype it points to? Example:
`int*` vs. `double*`
* How are array names related to pointers?
* What happens if we increment a pointer with `ptr++`? We can also do this `ptr = ptr + 5`.

