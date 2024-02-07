# DSVector

We want to implement a vector which

* Provides automatic memory management.
* Knows its size and checks bounds.
* Is resizeable. For efficiency, the internal array will sometimes be
   larger than the size. We call this the capacity. 
* Is templated.
* Provide access with \[\] and does boundary checking. Note: `std::vector` only checks boundaries
    with function `.at()`.
* Implements a member function that lets you efficiently append an element 
  to the vector. We will distinguish between length and capacity of the vector. The capacity may be larger then the length and contain empty positions that can be used for future append operations.
  We typically double the capacity if we run out of capacity. 
* Implements move semantics (advanced topic).
* Implements iterators (advanced topic).

__Note on templates:__ templates need to have all the code in the header
  file so the compiler can create the templated classes/functions at compile time.


Here is some pseudocode (the full implementation is in [DSVector.h](DSVector.h)):

```cpp
template <typename Object>
class DSVector

protected:                      // so subclasses have access
  size_t theSize;               // logical size
  size_t theCapacity;           // size + space to grow
  Object *objects;              // array of length capacity

public:
  // Default Constructor: Create an new DSVector
  explicit DSVector(size_t initSize = 0)
  {
    // create a vector with initSize objects and use the default constructor to fill it
    // with objects.
    ...
  }

  // Rule-of-Three 1: Copy constructor needed because we use new!
  DSVector(const DSVector &rhs)
  {
    ... // allocate space and copy rhs
  }

   // Rule-of-Three 2: Destructor needed because we use new!
  ~DSVector()
  {
    ... // release memory
  }

  // Rule-of-Three 3: Copy assignment operator needed because we use new!
  DSVector &operator=(const DSVector &rhs)
  {
    ... // allocate space and copy rhs
    return *this;
  }

  // helper functions
  // is the vector empty?
  bool empty() const {...}  // const means that the function will not modify the object
 

  // how many elements are in the vector?
  size_t size() const {...}

  // what is the capacity?
  size_t capacity() const {...}

  // subscript operator
  Object &operator[](size_t index)
  {
    // Checking bounds is important. For errors, you can use 
    //     throw std::runtime_error("out of bounds!");
    ...
  }

  const Object &operator[](size_t index) const
  {
    ... // In case we use [] on a const object.
  }


  // reserve more space
  void reserve(size_t newCapacity)
  {
    // Allocate new space, copy the data and deallocate the old space.
    // This function can be used by other functions.
    ...
  }

  // resize the vector to make it shorter and keep the rest as capacity
  void resize(size_t newSize) {...}

  // add an element at the end. STL calls this push_back().
  void push_back(const Object &x)
  {
    ...  // make sure you have the capacity. If not, then add capacity.
  }

  // look at the last element.
  const Object &back() const {
    ... // this is const and cannot be used to modify the last element!
  }

  // remove the last element.
  void pop_back()
  {
    ... // make sure the vector is not empty!
  }

  // Iterators for arrays are just regular pointers. operator++ and operator--
  // are already available, so we don't need to implement a nested class iterator.
  // We can reuse Object* using a nested type definition. 
  // const iterators are needed to work with const objects.
  typedef Object* iterator;
  typedef const Object* const_iterator;
  
   // STL algorithms and ranges use .begin() and .end() to obtain iterators.
  iterator begin() {...}
  const_iterator begin() const {...}
  iterator end() {...}
  const_iterator end() const {...}
};
```
