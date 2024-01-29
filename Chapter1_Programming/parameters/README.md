# Parameter passing: Call-by-value vs call-by-reference

## Call-by-value 

  ```cpp
  double average(double a, double b) {...}
  ```

  The arguments are copied. This is typically used for primitive data types (`int`, `double`, etc.).

## Call-by-reference: 

  ```cpp
  void swap(int &x, int &y) {...}
  ```

  `x` and `y` in the function `swap()` become aliases for the variables in the calling function. 
  Changing them changes the values in the calling function! 
  
  **Important:** The purpose is to use this _side effect_ and programmers who see the function prototype will assume that
  the function will do that. 
  If you do not want to or need to change the variables in 
  the calling function and use references to avoid copying, then you want to use constant references (see below).
 
  **C++11 Note:** [std::swap()](https://en.cppreference.com/w/cpp/algorithm/swap) is already available in the STL. It can be used together with [std::move()](https://en.cppreference.com/w/cpp/algorithm/move) to avoid copying large objects. STL containers (vector, string) use move semantics automatically.


## Call-by-constant reference

  ```cpp
  Object average(const Object &a, const Object &b) {...}
  ```

  `a` and `b` become aliases for the variables in the calling function.
  The compiler makes sure that they are not changed. The purpose is to avoid copying large objects when passing them to a 
  function. This is the standard way to pass objects read-only in C++.


## Call-by-pointer (used in C)
    
  ```cpp
  strcpy(char *destination, const char *source) {...}
  ```

  The function gets pointers which can be used to access the data they point to. This is very dangerous not 
  used in C++ unless we deal with C-style arrays which we want to avoid, or functions that come from a C library.
  
  `strcpy` is defined in the library  [cstring/string.h](https://en.cppreference.com/w/c/string/byte/strcpy)
  and copies the C-string in `source` to `destination`. 

# Return passing

## Return-by-value

This is the standard way of returning values. C++11 makes returning STL data structures more efficient using automatically move semantics.

## Return-by-(constant)-reference

We can return a reference to an object/variable. This object has to exist after the function has finished so it cannot be 
a local object/variable on the function call stack!

```cpp
const LargeObject & chooseRandomItem(const vector<LargeObject> & arr) {
   return arr[ randomInt(0, arr.size() - 1)) ];
}
```

Without the `const` keywords, the caller of `chooseRandomItem()` would
have modifying access to the returned object.

Be careful, you can only return references to objects that persist after the function finishes!
In this case `arr` is still in memory after `chooseRandomItem()` finishes because it is owned by the 
calling function and was passed to `chooseRandomItem()` by reference.

# Use of the keyword `const`


## Constant Values

```cpp
const int n = 20;
```

## Const pointers

```cpp
const char *text = "test"; // the value pointed to cannot be modified.
char* const text = "test"; // the location pointed to cannot be modified.
```

## Const references

```cpp
int a = 10;
const int &b = a;
```

The referenced value cannot be modified.

## Const member functions

Creates a read-only function that cannot modify the calling object. It is technically an 
overloaded function and `const` becomes part of the signature 
(see [name mangling](https://en.wikipedia.org/wiki/Name_mangling) for details on signatures).

non-`const` objects can also be used to call `const` member functions, but not the other 
way round.

```cpp
class ...
{
private:
  int x;
public:
    int getSomeValue() const
    {
      // this results in a compilation error: 
      // x++; 
      return x;
    }  
    ...
}
```

## Some Rules for `const`

* `const` objects cannot be modified. The compiler enforces this at compile time.
* `const` is a safeguard. The implementer of the function does not make a mistake and changes an object by accident. 
  The user of the function knows that passed variables are save from manipulation by the function.  
* With a `const` object, you can only call `const` member functions. Therefore, we often need to provide also a `const` version of some member functions. The STL uses `const` objects a lot, so your classes should also provide `const` versions. 
