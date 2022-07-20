#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <algorithm>
#include <iostream>
#include <stdexcept>

// A DSVector should be:
// * A wrapper around an array of objects.
// * Know its size and checks bounds.
// * Provide access with [].
// * Be resizable. For efficiency, the internal array will sometimes be
//   larger than the size. We call this the capacity. 
// * Implement a member function that lets you append an element to the vector. 
//   We typically double the capacity if we run out of capacity. 

// Note on templates: templates need to have all the code in the header file so the 
//   compiler can create the templated classes/functions at compile time.

template <typename Object>
class DSVector
{
public:
  // Create an new DSVector
  explicit DSVector(int initSize = 0)
  {
    // create a vector with initSize objects and use the default constructor to fill it
    // with objects.
  }

  // Copy constructor
  DSVector(const DSVector &rhs)
  {
    // allocate space and copy rhs
  }

  // Destructor
  ~DSVector()
  {
  }

  // Assignment operator
  DSVector &operator=(const DSVector &rhs)
  {
    // allocate space and copy rhs

    return *this;
  }

  // is the vector empty?
  // const means that the function will not modify the object
  bool empty() const
  {
  }

  // how many elements are in the vector?
  int size() const
  {
  }

  // what is the capacity?
  int capacity() const
  {
  }

  // subscript operator
  Object &operator[](int index)
  {
    // Checking bounds is important. For errors, you can use 
    //     throw std::runtime_error("out of bounds!");
  }

  // reserve more space
  void reserve(int newCapacity)
  {
    // Allocate new space, copy the data and deallocate the old space.
    // This function can be used by other functions.
  }

  // resize the vector
  void resize(int newSize)
  {
  }

  // add an element at the end. STL calls this push_back().
  void push_back(const Object &x)
  {
    // make sure you have the capacity.
  }

  // STL algorithms and ranges use begin() and end() to obtain iterators.
  // Iterators for arrays are just regular pointers. operator++ and operator--
  // are already available, so we don't need to implement a nested class iterator,
  // but just reuse Object * using a nested type definition. 
  // const iterators are used whenever the compiler wants to make sure that the
  // object does not get modified.
  typedef Object * iterator;
  
  iterator begin()
  {
  }
  
  const iterator begin() const
  {
  }

  iterator end()
  {
  }

  const iterator end() const
  {
  }

private:
  // add members including an array of the template type
};

#endif
