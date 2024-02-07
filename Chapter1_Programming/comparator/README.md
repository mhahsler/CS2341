# Comparators

Comparing if two objects are the same or one is "larger" or before the other in a given order (e.g., alphabetical order) are often needed and ADTs base their algorithms (e.g., sorting) on these comparisons. Comparators help us with implementing this. 

## Typename Convention used for Templates

* typename `Object` in templates suggests that it has the big three/big five:
  * a default constructor
  * a copy constructor, and
  * `operator=`

* typename `Comparable` in templates suggests that it also has an
  * `operator<` for a total order which can also be used to infer:
      - equality (`==`): `a == b` only if `!(a < b) && !(b < a)`  
      - greater than (`>`): `a > b` only if `!(a < b) && !(a == b)`
      - less or equal: (`<=`): `a <= b` only if `!(a > b)`  
      - `!=` and `>=` are defined in the same way.



  **Important:** Once a class has `operator<` overloaded, it can be used in ADTs by any algorithm that requires sorting.

## Function Objects

Many algorithm implementations also allow the use of a [_function object_](https://en.wikipedia.org/wiki/Function_object) (related to functors in functional programming)
to define several different ways to order object (e.g, people can be ordered by last name, height, age, income, etc.)

A function object is just a class with only an overloaded `operator()` function which is called when the function object is used. Here is an example:

```cpp
class CaseInsensitiveCompare
{
public:
    bool operator()(const string &lhs, const string &rhs) const
    {
        return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};
```

Function object are commonly used in STL algorithms. 
The STL provides the templated function object [`std::less<Comparable>`](https://cplusplus.com/reference/functional/less/) which uses the object's `operator<` to create a function object that can then be used with STL algorithms.

The typename `Comparator` is typically used in templates used as a placeholder for a comparator
function object. To make this clear we typically use the parameter 
name `isLessThan`. See [main.cpp](main.cpp).

