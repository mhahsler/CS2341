# Templates

Templates let us define algorithms that are data type independent.
Templates can be used for functions and classes.
 
Templates define a pattern. The typename `<T>` is just a placeholder for the 
actual data type and the compiler will compile all needed versions
of the class or function. This can lead to code bloat. 

For example the templated data structure std::vector can create

`vector<int>`, `vector<double>`, `vector<string>`, ...

The templated datatype becomes part of the function signature/class name.

 Notes: 
 * Always assume that the template data type may not be a primitive data type so be careful with 
   copying and comparing.
 * Template matching happens at compile time.
 * Template matching can be ambiguous which will lead to a compilation error.
 