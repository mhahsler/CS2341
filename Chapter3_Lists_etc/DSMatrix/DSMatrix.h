#ifndef DSMATRIX_H
#define DSMATRIX_H

// This is an incomplete implementation of a matrix class using a single array.

#include <iostream>
#include <stdexcept>

template <typename Object>
class DSMatrix
{
private:
    size_t rows;
    size_t cols;
    Object *data;

public:
    DSMatrix(size_t _rows, size_t _cols) : rows{_rows}, cols(_cols)
    {
        data = new Object[_cols * _rows];
    }
    // Note: this class does not have a default constructor!

    // The Rule three
    ~DSMatrix()
    {
        delete[] data;
    }

    DSMatrix(const DSMatrix &rhs) : rows{rhs.rows}, cols{rhs.cols}
    {
        data = new Object[rows * cols];
        for (size_t i = 0; i < rows * cols; ++i)
            data[i] = rhs.data[i];
    }

    DSMatrix &operator=(const DSMatrix &rhs)
    {
        DSMatrix copy(rhs);
        std::swap(*this, copy); // make the copy the object
        return *this;
    }

    // Move Constructor
    // Much more effcient than copy constructor
    // Steals the interals and reassigns them
    // Marking these move operations as noexcept to ensure exception safety and better performance.
    DSMatrix(DSMatrix &&rhs) noexcept : rows{0}, cols{0}, data{nullptr}
    {
        rows = rhs.rows;
        cols = rhs.cols;
        data = rhs.data;
    
        rhs.rows = 0;
        rhs.cols = 0;
        rhs.data = nullptr;
    }
    
    // Move Assignment Operator
    DSMatrix &operator=(DSMatrix &&rhs) noexcept
    {
        if (this != &rhs)
        {
            delete[] data;
    
            rows = rhs.rows;
            cols = rhs.cols;
            data = rhs.data;
    
            rhs.rows = 0;
            rhs.cols = 0;
            rhs.data = nullptr;
        }
        return *this;
    }

    // We would overload operator[] for row and column index but C++ does not
    // support multiple parameters. Support for this is added in C++23 and example code is below:
    
    // We use **column major** order, which is the standard.
    // Since size_t is unsigned, we don't have to do checks for less than 0
    Object &operator()(size_t row, size_t col)
    {
        if (row >= rows || col >= cols) {
            throw std::invalid_argument("Out of bounds!");
        }
        return data[col * rows + row];
    }
    
    // We return a const reference for const objects
    const Object &operator()(size_t row, size_t col) const
    {
        return data[col * rows + row];
    }
    
    // Example of how to use brackets with C++23. We should wait with using this feature till C++23 is 
    // supported by all major compilers for a while or we will run into trouble with machines running older
    // systems.
    #if __cplusplus >= 202302L
    Object &operator[](size_t row, size_t col)
    {
        return operator()(row, col);
    }
    
    // We return a const reference for const objects
    const Object &operator[](size_t row, size_t col) const
    {
        return operator()(row, col);
    }
    #endif

    size_t nrows() const
    {
        return rows;
    }

    size_t ncols() const
    {
        return cols;
    }

    // this assumes that Object has operator<< defined
    friend std::ostream &operator<<(std::ostream &os, const DSMatrix<Object> &m)
    {
        for (size_t r = 0; r < m.nrows(); ++r)
        {
            for (size_t c = 0; c < m.ncols(); ++c)
                os << m(r, c) << " ";
            os << "\n";
        }

        return os;
    }
};

#endif
