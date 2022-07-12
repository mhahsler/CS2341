# Parameter passing: Call-by-value vs call-by-reference

## Call-by-value 

  ```cpp
  double average(double a, double b) {...}
  ```

  arguments are copied.

## Call-by-reference: 

  ```cpp
  swap(int &x, int &y) {...}
  ```

  `x` and `y` become aliases for the variables in the calling function. 
  Changing them changes the values there. The purpose is to use this
  side effect.
 
  C++11 Note: [std::swap()](https://en.cppreference.com/w/cpp/algorithm/swap) is already available in the STL. It can be used together with std::move() to avoid copying large objects. std::move() moves rvalues instead of copying the object. rvalues are temorary objects (e.g., the
 result of an evaluation) and  
 lvalues are permanent storage (e.g., variables). 
 Typical assignment `lval = rval;`. STL containers (vector, string) 
 use move automatically.


## Call-by-constant reference

  ```cpp
  double average(const Object &a, const Object &b) {...}
  ```

  `a` and `b` become aliases for the variables in the calling function.
  They cannot be changed. The purpose is to avoid copying large objects.


## Call-by-pointer (used in C)
    
  ```cpp
  strcpy ( char * destination, const char * source ) {...}
  ```

  copies the string in `source` to `destination`. This is typically not 
  used in C++.
  

# Return passing

## Return-by-value

This is the typical way of returning values. C++11 makes returning STL data structures efficient using move semantics.

## Return-by (constant) reference

We can return a reference to an object that exists after the function has finished.

```cpp
const LargeObject & chooseRandomItem(const vector<LargeObject> & arr) {
   return arr[ randomInt(0, arr.size() - 1)) ];
}
```

Without the `const` keywords, the caller of `chooseRandomItem()` would
have modifyable access to the object.

Note that const references can only be assigned to const references or need to be copied.

# Use of the keyword `const`

The compiler enforces the keyword `const`.

## Constants

```cpp
const int i;
```

## Const pointers

```cpp
char const * text = "test"; // the pointer cannot be modified.
const char * text = "test"; // the value pointed to cannot be modified.
```

## Const references

The referenced value cannot be modified.

## Const member functions

Creates a read-only function that cannot modify the object.

```cpp
class ...
{
public:
    int getSomeValue() const;  
    ...
}
```


