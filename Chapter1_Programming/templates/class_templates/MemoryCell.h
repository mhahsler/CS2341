#ifndef MemoryCell_H
#define MemoryCell_H

/**
 * A templated class for simulating a memory cell.
 *
 * It is assumed that the template Object has:
 *  1. a zero-parameter constructor (used in line 19)
 *  2. a copy constructor (used in constructor in line 20)
 *  3. a copy assignment operator (used in line 37)
 *
 * for many compilers, the entire template class with the implementation has
 * to be put into a single .h file.
 */
template <typename Object>
class MemoryCell
{
public:
    explicit MemoryCell(const Object &initialValue = Object{})
        : storedValue{initialValue} {}

    /**
     * @brief Read content of the cell
     *
     * @return const Object&
     */
    const Object &read() const
    {
        return storedValue;
    }

    /**
     * @brief Replace the content of the cell
     *
     * @param x
     */
    void write(const Object &x)
    {
        storedValue = x;
    }

private:
    Object storedValue;
};

#endif