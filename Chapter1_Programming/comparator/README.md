# Comparators

Comparing if two objects are the same or one is "larger" or before the other in a given order (e.g., alphabetical order) are often needed and ADTs base their algorithms (e.g., sorting) on these comparisons. Comparators help us with implementing this. 

## Typename Convention used for Templates

* typename `Object` in templates suggests that it has the big three/big five:
  * a default constructor
  * a copy constructor, and
  * `operator=`

* typename `Comparable` in templates suggests that it also has an
  * `operator<` for a total order which can also be used to infer equality `operator==` by if
`a !> b` and `b !> a` then `a == b`.

Once a class has `operator<` overloaded, it can be used by algorithms on ADTs.

## Function Objects

Many algorithm implementations also allow the use of a _function object_
to define potentially several ways to order object (e.g, people can be ordered by last name, height, age, income, etc.)

A function object is a class with only an overloaded `operator()` function.

The STL provides the templated function object [`std::less<Comparable>`](https://cplusplus.com/reference/functional/less/) which uses the object's `operator<`.

typename `Comparator` in templates is used as a placeholder for a comparator
function object. To make this clear we typically use the parameter 
name `isLessThan`.

