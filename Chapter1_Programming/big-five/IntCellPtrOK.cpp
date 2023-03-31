#include "IntCellPtrOK.h"

/**
 * @brief Construct a new IntCellPtrOk object
 *
 * @param initialValue initial int value
 */
IntCellPtrOK::IntCellPtrOK(int initialValue)
{
    storedValue = new int{initialValue};
    // Note [] and {} are different!
    // same as: storedValue = new int; *storedValue = initialValue;
}

/**
 * @brief Destroy the IntCellPtrOK object
 */
IntCellPtrOK::~IntCellPtrOK()
{
    delete storedValue;
}

/**
 * @brief Copy Constructor
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
     * @brief Copy assignment
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
        if (this != &rhs)
            *storedValue = *(rhs.storedValue);
        return *this;
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
