#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <algorithm>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename Object>
class DSVector
{
private:
  size_t theSize;
  size_t theCapacity;
  Object *objects;

public:
  // Create an empty DSVector
  explicit DSVector(size_t initSize = 0)
      : theSize{initSize}, theCapacity{initSize}
  {
    objects = new Object[theCapacity];
  }

  // C++11 initializer list with {}
  DSVector(const initializer_list<Object> &v)
  {
    theSize = 0;
    theCapacity = v.size();
    objects = new Object[theCapacity];
    for (auto itm : v)
      this->push_back(itm);
  }

  // Copy constructor
  DSVector(const DSVector &rhs)
      : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr}
  {
    objects = new Object[theCapacity];
    for (size_t k = 0; k < theSize; ++k)
      objects[k] = rhs.objects[k];
  }

  // C++11 Move constructor ... steal the pointer to objects
  DSVector(DSVector &&rhs)
      : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects}
  {
    rhs.theSize = 0;
    rhs.theCapacity = 0;
    rhs.objects = nullptr; // so the destructor does not destroy the objects
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
    for (size_t k = 0; k < theSize; ++k)
      objects[k] = rhs.objects[k];

    return *this;
  }

  // C++11 move assignment operator: move elements from rhs using std::swap()
  DSVector &operator=(DSVector &&rhs)
  {
    swap(theSize, rhs.theSize);
    swap(theCapacity, rhs.Capacity);
    swap(objects, rhs.objects);

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
  Object &operator[](size_t index)
  {
    if (index < 0 || index >= size())
      throw std::runtime_error("out of bounds!");
    return objects[index];
  }

  const Object &operator[](size_t index) const
  {
    if (index < 0 || index >= size())
      throw std::runtime_error("out of bounds!");
    return objects[index];
  }

  // reserve more space
  void reserve(size_t newCapacity)
  {
    if (newCapacity < theSize)
      return;

    Object *newArray = new Object[newCapacity];
    for (size_t k = 0; k < theSize; ++k)
      newArray[k] = objects[k];

    delete[] objects;
    objects = newArray;
    theCapacity = newCapacity;
  }

  // resize the vector
  void resize(size_t newSize)
  {
    if (newSize > theCapacity)
      reserve(newSize);
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
  typedef const Object *const_iterator;

  iterator begin()
  {
    return &objects[0];
  }

  const_iterator begin() const
  {
    return &objects[0];
  }

  iterator end()
  {
    return &objects[size()];
  }

  const_iterator end() const
  {
    return &objects[size()];
  }
};

#endif
