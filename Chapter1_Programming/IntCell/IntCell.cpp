#include "IntCell.h"

/**
 * @brief Construct a new Int Cell:: Int Cell object
 * 
 * @param initialValue initial int value
 */
IntCell::IntCell(int initialValue)
    : storedValue{initialValue} {}

// same as: IntCell::IntCell(int initialValue) { storedValue = initialValue; }


/**
 * @brief read the int value
 * 
 * @return int 
 */
int IntCell::read() const
{
    return storedValue;
}
/**
 * @brief store the int value.
 * 
 * @param x the int value
 */
void IntCell::write(int x)
{
    storedValue = x;
}


/*
 * Notes:
 *  * the member functions need to be placed in the class's namespace (here IntCell::)
 *  * no default values since they are already defined in the header file
 *  * constructor uses an initialization list here. Regular assignment
 *    can also be used.
 *  * {} instead of () in the initialization list is new in C++11
 */
