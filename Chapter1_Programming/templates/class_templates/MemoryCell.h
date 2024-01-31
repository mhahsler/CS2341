#ifndef MemoryCell_H
#define MemoryCell_H

/**
 * A templated class for simulating a memory cell.
 *
 * How to create a templated class:
 *  1. Write your class without templates but write all code in the headerfile (compilers currently 
 *          cannot use .cpp files for templates).
 *  2. Add the line `template <typename Object> in front of the class in the headerfile.
 *  3. Change the original variable datatype used in your code to `Object`.
 * Now you can create templated objects using `YourClassName<datatype> x;` 
 * 
 * You don't need to use `Object` as the type names. Popular are also `T` and `Comparable`. 
 * Assumptions about the template type when you use Object:
 *  1. It has a zero-parameter constructor (used in line 19)
 *  2. It has a copy constructor (used in constructor in line 20)
 *  3. It has a copy assignment operator (used in line 37)
 *
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