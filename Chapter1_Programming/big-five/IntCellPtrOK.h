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
    /*
     * Whenever you have dynamic memory allocation, then you also need to define a default constructor that 
     * allocates the memory for a valid object. The default constructor is here defined using a default value.
     */
    explicit IntCellPtrOK(int initialValue = 0);

    /*
     * Correct use the Rule-of-3: Destructor, copy constructor and copy assignment.
     *
     * Note: C++11 adds move constructor and assignment for rvalue references to avoid copying in some cases. We will
     *       not use them in class.
     */
    ~IntCellPtrOK();
    IntCellPtrOK(const IntCellPtrOK & rhs);
    IntCellPtrOK & operator= (const IntCellPtrOK & rhs );

    int read() const;
    void write(int x);
};

#endif
