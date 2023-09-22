#ifndef DSMATRIX_H
#define DSMATRIX_H

// This is an incomplete implementation of a matrix class using a single array.

#include <iostream>

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

    // TODO: C++11 move versions would be nice (Big five)

    // We would overload operator[] for row and column index but C++ currently does not
    // allow more then one parameters for []
    //
    // We use **column major** order, which is the standard.
    //
    // TODO: checking bounds for col and row would be a good idea
    Object &operator()(size_t row, size_t col)
    {
        return data[col * rows + row];
    }
    
    // We return a const reference for const objects
    const Object &operator()(size_t row, size_t col) const
    {
        return data[col * rows + row];
    }

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