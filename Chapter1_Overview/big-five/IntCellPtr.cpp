#include "IntCellPtr.h"

/**
 * @brief Construct a new IntCell::IntCell object
 * 
 * @param initialValue initial int value
 */
IntCellPtr::IntCellPtr(int initialValue) {
    storedValue = new int{ initialValue };
}
/**
 * @brief read the int value
 * 
 * @return int 
 */
int IntCellPtr::read() const
{
    return *storedValue;
}
/**
 * @brief store the int value.
 * 
 * @param x the int value
 */
void IntCellPtr::write(int x)
{
    *storedValue = x;
}
