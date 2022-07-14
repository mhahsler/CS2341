# Comparators

## Typename Convention

`typename Object` in templates suggests that it has the big three/big five:
* a default constructor
* a copy contractor, and
* `operator=`

`typename Comparable` in templates suggests that it also has an
* `operator<` for a total order.

## Function Objects

Many functions also allow the use of a _function object_
to define potentially several ways to order object (e.g, people can be ordered by last name, height, age, etc.)

A function object is a class with only an overloaded `operator()`.

The STL provides the templated function object [`std::less<Comparable>`](https://cplusplus.com/reference/functional/less/) which uses the object's `operator<`.

`typename Comparator`  in templates is used as a placeholder for a comparator
function object. To make this clear we typically use the parameter 
name `isLessThan`.

