#ifndef IntCellPtrOK_H
#define IntCellPtrOK_H

/**
 * A class for storing a single Int as a pointer
 */
class IntCellPtrOK
{
private:
    int *storedValue;

public:
    explicit IntCellPtrOK(int initialValue = 0);

    /*
     * Destructor, copy constructor and copy assignment.
     */
    ~IntCellPtrOK();
    IntCellPtrOK(const IntCellPtrOK & rhs);
    IntCellPtrOK & operator= (const IntCellPtrOK & rhs );

    int read() const;
    void write(int x);
};

#endif
