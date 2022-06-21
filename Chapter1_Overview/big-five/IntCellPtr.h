#ifndef IntCellPtr_H
#define IntCellPtr_H

/**
 * A class for storing a single Int as a pointer
 */
class IntCellPtr
{
private:
    int *storedValue;

public:
    explicit IntCellPtr(int initialValue = 0);
    int read() const;
    void write(int x);
};

#endif
