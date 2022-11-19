# Templates

Templates let us define generic algorithms that are data type independent (i.e., work with ADTs). This
is beneficial because we do not have to write multiple versions of the same code, just to work with different 
data types.

Example: The following overloaded functions

```C++
int increment(int x) { x++; }
double increment(double x) { x++; }
float increment(float x) { x++; }
```

can be defined as a single template 

```C++
template <typename T>
T increment(const T& x) { x++; }
```
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
 * Always assume that the template data type may not be a primitive data type so be careful with 
   copying and comparing.
 * Always assume that someone will use your class in an ADT like `std::vector`, so it needs to provide the Rule-of-three!
 * Template matching and code generation happens at compile time.
 * Template matching can be ambiguous which will lead to a compilation error.
 * Some template type names suggest properties of the object:
   - **Object**: Has a default constructor, a copy constructor, an assigned operator (`operator=`), and comparison 
     (`operator==`) implemented.
   - **Comparable**: Can in addition be compared with `operator<`.


Examples:
* [Function Template](function_templates)
* [Class Template](class_templates)
