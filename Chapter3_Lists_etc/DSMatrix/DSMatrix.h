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

    ~DSMatrix()
    {
        delete[] data;
    }

    // TODO: We need the rest of the big 5 (copy constructor, copy assignment operator and maybe move versions)

    // we would overload [], but C++ currently does not
    // allow more then one parameters for []
    // checking bounds for col and row would be a good idea
    Object &operator()(size_t col, size_t row)
    {
        return data[col * rows + row];
    }
    
    // const version for const objects
    const Object &operator()(size_t col, size_t row) const
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
                os << m(c, r) << " ";
            os << "\n";
        }

        return os;
    }
};

#endif