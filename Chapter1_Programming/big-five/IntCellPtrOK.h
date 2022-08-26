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
     * Correct use of Big 3: Destructor, copy constructor and copy assignment.
     *
     * Note: C++11 added move constructor and assignment for lvalues to avoud copying in some cases. We will
     *       not use them in class.
     */
    ~IntCellPtrOK();
    IntCellPtrOK(const IntCellPtrOK & rhs);
    IntCellPtrOK & operator= (const IntCellPtrOK & rhs );

    int read() const;
    void write(int x);
};

#endif
