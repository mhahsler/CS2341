#ifndef IntCell_H
#define IntCell_H

/*
 * Remember: use define to guard for multiple inclusions during compilation
 */

/**
 * A class for storing a single Int
 */
class IntCell
{
private:
    int storedValue;

public:
    explicit IntCell(int initialValue = 0); // default value can only be specified once!
    int read() const;
    void write(int x);
}; // mind the ;

/*
 * Notes: 
 *  * use default values and specify them in the header file only.
 *  * explicit prevents automatic conversion of int to IntCell.
         intCell cell; cell = 10; // conversion prevented by explicit
         intCell cell = intCell{10}; // should work
      see: https://en.cppreference.com/w/cpp/language/explicit 
 *  * use const to prevent changes to data members
 */

#endif
