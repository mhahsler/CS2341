#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <algorithm>
#include <iostream>
#include <stdexcept>

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

  // Iterators are just pointers. STL algorithms and ranges use begin() and end().
  // Bounds not checked
  Object *begin()
  {
    return &objects[0];
  }

  Object *end()
  {
    return &objects[size()];
  }

private:
  int theSize;
  int theCapacity;
  Object *objects;
};

#endif
