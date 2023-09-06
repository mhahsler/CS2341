#ifndef IntCell_H
#define IntCell_H

/**
 * A class for storing a single Int
 */
class IntCell
{
private:
    int storedValue;

public:
    explicit IntCell(int initialValue = 0);
    int read() const;
    void write(int x);
};

/*
 * Notes: 
 *  * use default values
 *  * explicit prevents automatic conversion of int to IntCell: intCell cell = 10; 
 *  * use const to prevent changes to data members
 */

#endif