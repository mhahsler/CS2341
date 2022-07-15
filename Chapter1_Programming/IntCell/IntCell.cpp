#include "IntCell.h"

/**
 * @brief Construct a new Int Cell:: Int Cell object
 * 
 * @param initialValue initial int value
 */
IntCell::IntCell(int initialValue)
    : storedValue{initialValue} {}

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
 *  * no default values
 *  * constructor uses an initialization list here. Regular assignment
 *    can also be used.
 *  * {} instead of () in the initialization list is new in C++11
 */
