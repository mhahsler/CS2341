#ifndef DSMATRIX_H
#define DSMATRIX_H

#include <iostream>

template <typename Object> class DSMatrix
{
private:
    int rows;
    int cols;
    Object *data;

public:
    DSMatrix(int _rows, int _cols) : rows{_rows}, cols(_cols)
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
    Object &operator()(int col, int row)
    {
        return data[col * rows + row];
    }

    int nrows() const 
    {
        return rows;
    }

    int ncols() const 
    {
        return cols;
    }
    
};

#endif