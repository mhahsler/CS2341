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
  // Create an empty DSVector
  explicit DSVector(int initSize = 0)
      : theSize{initSize}, theCapacity{initSize * 2}
  {
    objects = new Object[theCapacity];
  }

  // Copy constructor
  DSVector(const DSVector &rhs)
      : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr}
  {
    objects = new Object[theCapacity];
    for (int k = 0; k < theSize; ++k)
      objects[k] = rhs.objects[k];
  }

  // Destructor
  ~DSVector()
  {
    delete[] objects;
  }

  // Assignment operator
  DSVector &operator=(const DSVector &rhs)
  {
    delete[] objects;
    theSize = rhs.theSize;
    theCapacity = rhs.theCapacity;
    objects = new Object[theCapacity];
    for (int k = 0; k < theSize; ++k)
      objects[k] = rhs.objects[k];

    return *this;
  }

  // is the vector empty?
  bool empty() const
  {
    return size() == 0;
  }

  // how many elements?
  int size() const
  {
    return theSize;
  }

  // what is the capacity?
  int capacity() const
  {
    return theCapacity;
  }

  // subscript operator
  Object &operator[](int index)
  {
    if (index < 0 || index >= size())
      throw std::runtime_error("out of bounds!");
    return objects[index];
  }

  // reserve more space
  void reserve(int newCapacity)
  {
    if (newCapacity < theSize)
      return;

    Object *newArray = new Object[newCapacity];
    for (int k = 0; k < theSize; ++k)
      newArray[k] = objects[k];

    delete[] objects;
    objects = newArray;
    theCapacity = newCapacity;
  }

  // resize the vector
  void resize(int newSize)
  {
    if (newSize > theCapacity)
      reserve(newSize * 2);
    theSize = newSize;
  }

  const Object &back() const
  {
    if (empty())
      throw std::runtime_error("stack is empty!");
    return objects[theSize - 1];
  }

  // add an element at the end. STL calls this push_back().
  void push_back(const Object &x)
  {
    if (theSize == theCapacity)
      reserve((theCapacity > 0) ? 2 * theCapacity : 2);
    objects[theSize++] = x;
  }

  // STL algorithms and ranges use begin() and end() to obtain iterators.
  // Iterators for arrays are just regular pointers. operator++ and operator--
  // are already available, so we don't need to implement a nested class iterator,
  // but just reuse Object * using a nested type definition. 
  typedef Object *iterator;

  iterator begin()
  {
    return &objects[0];
  }

  iterator end()
  {
    return &objects[size()];
  }

private:
  int theSize;
  int theCapacity;
  Object *objects;
};

#endif
