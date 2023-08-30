# Templates

Templates let us define generic algorithms that are data type independent (i.e., work with ADTs). This
is beneficial because we do not have to write multiple versions of the same code, just to work with different 
data types.

Example: The following overloaded functions

```C++
int increment(int x) { return x + 1; }
double increment(double x) { return x + 1; }
float increment(float x) { return x + 1; }
```

can be defined as a single template 

```C++
template <typename T>
T increment(const T& x) { return x + 1; }
```
`T` is used as a placeholder for a datatype (could be user-defined class). The code assumes that `T` has an
implementation of `operator+` to perform the addition. Since `T` can be an object which we do not want to copy, a constant reference (`const T&`) is typically used as the parameter. 

Templates can be used for functions and classes.

## Syntax
Define the template type before the function or class with `template <typename T>`

Templates define a pattern. The typename `<T>` is just a placeholder for the 
actual data type and the compiler will create and compile all needed versions
of the class or function. This can have two consequences. (a) if the function is never called, then 
the template code is never compiled, and (b) if there are many calls with different types then this can lead to 
large executables (aka code bloat). 

For example the STL data structure `std::vector` can is a templated class and can create

`vector<int>`, `vector<double>`, `vector<string>`, ...

The templated datatype becomes part of the function signature/class name.

 Notes: 
 * Class templates need to be currently implemented as a header only class which means that it has only a `.h``, all the code is in the 
    header file, and this file needs to be added to the `CMakeLists.txt`` file for compilation.
 * Template matching and code generation happens at compile time.
 * Template matching can be ambiguous which will lead to a compilation error.
 * Always assume that someone will use your templated code with a non-primitive template data type so be careful with 
   copying and comparing.
 * Always assume that someone will use your class in a templated ADT like `std::vector`, so it needs to provide at least the Rule-of-three!
 * Some template type names suggest properties of the object:
   - **Object**: Has a default constructor, a copy constructor, an assigned operator (`operator=`), and comparison 
     (`operator==`) implemented.
   - **Comparable**: Can in addition be compared with `operator<`.


Examples:
* [Function Template](function_templates)
* [Class Template](class_templates)
