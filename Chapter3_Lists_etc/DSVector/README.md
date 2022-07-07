# DSVector

A DSVector should be:

* A wrapper around an array of objects.
* Know its size and checks bounds.
* Provide access with \[\].
* Be resizeable. For efficiency, the internal array will sometimes be
   larger than the size. We call this the capacity. 
* Implement a member function that lets you append an element to the vector. 
   We typically double the capacity if we run out of capacity. 

__Note on templates:__ templates need to have all the code in the header file so the 
   compiler can create the templated classes/functions at compile time.
