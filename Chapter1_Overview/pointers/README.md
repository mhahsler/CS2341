# Pointers
 
 * `new`: dynamic memory allocation on the heap
 * `delete`: C++ does not use garbage collection! Memory leaks!!!
     use new only when it is needed (it is not needed in the following program!)
 * `->` (arrow operator) accesses members with a pointer to an object
 * `==` pointer addresses are compared not the objects
 * `&` (address-of-operator) returns the address of a variable (i.e., a pointer to the variable)
 * `*` (dereference operator) returns the object at the address the pointer points to.
 

**Important Note:** References (`int& i_ref = i;`) and 
  the address-of-operator (`&i`) are not related. A reference is just a second
  name for an object, while the address-of-operator returns a pointer 
  (the memory address). 

