#include "IntCellPtrOK.h"

/**
 * @brief Default Constructor
 * @param initialValue initial int value
 */
IntCellPtrOK::IntCellPtrOK(int initialValue)
{
    storedValue = new int{initialValue};
    // Note [] and {} are different!
    // same as: storedValue = new int; *storedValue = initialValue;
}

/**
 * @brief Rule-of-three: 1. Copy Constructor
 *
 * @param rhs
 */
IntCellPtrOK::IntCellPtrOK(const IntCellPtrOK &rhs)
{
    
    storedValue = new int{*(rhs.storedValue)};
    // same as: storedValue = new int; *storedValue = *(rhs.storedValue);
    // or: storedValue = new int; write(rhs.read());
}

/**
 * @brief Rule-of-three: 2. Copy assignment operator
 *
 * Remember:
 * 1. Operators are called for the lhs of the assignment which is the *this object.
 * 2. For chained assignments operator= always returns *this as a reference.
 *
 * @param rhs
 * @return IntCellPtrOK&
 */
IntCellPtrOK &IntCellPtrOK::operator=(const IntCellPtrOK &rhs)
{
    // check for self-assignment first
    if (this == &rhs)
        return *this;

    // make a deep copy of the rhs
    *storedValue = *(rhs.storedValue);

    return *this;
}

/**
 * @brief Rule-of-three: 3. Destructor
 */
IntCellPtrOK::~IntCellPtrOK()
{
    delete storedValue;
}

/**
 * @brief read the int value
 *
 * @return int
 */
int IntCellPtrOK::read() const
{
    return *storedValue;
}

/**
 * @brief store the int value.
 *
 * @param x the int value
 */
void IntCellPtrOK::write(int x)
{
    *storedValue = x;
}
