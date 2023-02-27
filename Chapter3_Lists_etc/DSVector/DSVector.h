#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <algorithm> // for std::swap
#include <stdexcept> // for operator[]


template <typename Object>
class DSVector
{
protected:
  size_t theSize;
  size_t theCapacity;
  Object *objects;

public:
  // Default Constructor: Create an empty DSVector. Call this as DSVector<int> v(4);
  explicit DSVector(size_t initSize = 0)
      : theSize{initSize}, theCapacity{initSize}
  {
    // allocate memory
    objects = new Object[theCapacity];
  }

  // C++11 initializer list with {}: Call this as DSVector<int> v{5};
  DSVector(const std::initializer_list<Object> &v)
  {
    // allocate memory
    theSize = v.size();
    theCapacity = v.size();
    objects = new Object[theCapacity];
    
    // copy
    size_t k = 0;
    for (const auto &x : v)
      objects[k++] = x;
  }

  // Rule-of-Three 1: Copy constructor needed because we use new!
  DSVector(const DSVector &rhs)
      : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr}
  {
    // allocate memory
    objects = new Object[theCapacity];
    
    // copy
    for (size_t k = 0; k < theSize; ++k)
      objects[k] = rhs.objects[k];
  }

  // Rule-of-Three 2: Destructor needed because we use new!
  ~DSVector()
  {
    delete[] objects;
    //delete objects; // this would be a mistake check with valgrind --leak-check=full --track-origins=yes ./DSVector
    // also check without any delete to see what valgrind says
    // Note: You can also compile with the asan library (see CMakeLists.txt) as an alternative to valgrind
  }

  // Rule-of-Three 3: Copy assignment operator needed because we use new!
  DSVector &operator=(const DSVector &rhs)
  {
    // assignments are of the form `lhs = rhs;` where the lhs is the calling object
    // release memory for the lhs (the calling object)
    delete[] objects;
    
    // allocate new memory
    theSize = rhs.theSize;
    theCapacity = rhs.theCapacity;
    objects = new Object[theCapacity];
    
    // copy rhs to lhs
    for (size_t k = 0; k < theSize; ++k)
      objects[k] = rhs.objects[k];

    // this line is standard for copy assignment operators
    return *this;
  }

  // The remaining Big-Five are optional but recommended for C++11 since they prevent
  // copying objects unnecessarily. The compiler knows when dynamically allocated memory
  // can be moved from one object to another.
  // Big-Five: C++11 Move constructor ... "steals" the pointer from the rhs 
  DSVector(DSVector &&rhs)
      : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects}
  {
    // so the destructor does not destroy the objects when it destroys rhs
    rhs.theSize = 0;
    rhs.theCapacity = 0;
    rhs.objects = nullptr; 
  }

  // Big-Five: C++11 move assignment operator: swaps all elements with rhs using std::swap()
  // std::move() is also useful. It marks an object as moveable (casts them  to &&).
  DSVector &operator=(DSVector &&rhs)
  {
    std::swap(theSize, rhs.theSize);
    std::swap(theCapacity, rhs.theCapacity);
    std::swap(objects, rhs.objects);

    return *this;
  }

  // how many elements?
  size_t size() const
  {
    return theSize;
  }

  // is the vector empty?
  bool empty() const 
  {
    return theSize == 0;
  }

  // capacity of the vector (capacity >= size)
  size_t capacity() const
  {
    return theCapacity;
  }

  // subscript operator
  Object &operator[](size_t index)
  {
    // size_t is always >=0!
    if (index >= theSize)
      throw std::runtime_error("out of bounds!");
    
    return objects[index];
  }

  // The subscript operator for const objects needs to prevent the returned reference to
  // be changed. This is done by returning a const reference.
  const Object &operator[](size_t index) const
  {
    // size_t is always >=0!
    if (index >= theSize)
      throw std::runtime_error("out of bounds!");
    
    return objects[index];
  }

  // reserve more space
  void reserve(size_t newCapacity)
  {
    if (newCapacity < theSize)
      return;

    // allocate new memory
    Object *newArray = new Object[newCapacity];
    
    // copy
    for (size_t k = 0; k < theSize; ++k)
      newArray[k] = objects[k];

    // release old memory
    delete[] objects;
    objects = newArray;
    theCapacity = newCapacity;
  }

  // resize the vector (only make it larger)
  void resize(size_t newSize)
  {
    if (newSize > theCapacity)
      reserve(newSize);
    
    theSize = newSize;
  }

  
  // look at the last element
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

  // delete the last element (we just manipulate theSize)
  void pop_back()
  {
    if (empty())
      throw std::runtime_error("stack is empty!");
    
    --theSize;
  }

  // STL algorithms and ranges use begin() and end() to obtain iterators.
  // Iterators for arrays are just regular pointers so we can reuse pointers where 
  // operator++ and operator-- are already available, so we don't need to implement a 
  // nested class iterator but just reuse Object * using a nested type definition.
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

  // end() is one past the last element!
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
