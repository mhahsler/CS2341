#include <iostream>
#include <vector>
#include "DSMatrix.h"

using namespace std;

int main()
{
    int rows = 3;
    int cols = 4;

    cout << "Array of arrays: m1\n";
    // allocate the array for the rows and then allocate each row
    int **m1 = new int *[rows];
    for (int r = 0; r < rows; ++r)
        m1[r] = new int[cols];

    m1[0][0] = 1;
    m1[1][1] = 1;
    m1[2][2] = 1;

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
            cout << m1[r][c] << " ";
        cout << "\n";
    }

    // clean up memory
    for (int r = 0; r < rows; ++r)
        delete[] m1[r];

    delete[] m1;

    cout << "\nVector of vectors (STL): m2\n";
    // This makes memory management a lot easier
    
    // make the vector of rows and then create each row vector
    vector<vector<int>> m2 = vector<vector<int>>(rows);
    for (auto &r : m2)
        r = vector<int>(cols);

    m2[0][0] = 1;
    m2[1][1] = 1;
    m2[2][2] = 1;

    for (auto &r : m2)
    {
        for (auto &c : r)
            cout << c << " ";
        cout << "\n";
    }

    // ********************* IMPORTANT **************************
    // Don't use array of arrays or vector of vectors unless you have a very good reason!
    // Even if textbooks describe it!
    // For matrices you should think BLAS (Basic Linear Algebra Subprograms)
    // see https://en.wikipedia.org/wiki/Basic_Linear_Algebra_Subprograms
    // Especially you should look at uBLAS in the C++ Boost Libraries
    // https://www.boost.org/doc/libs/1_63_0/libs/numeric/ublas/doc/index.html
    // For a (m x n)-dimensional matrix and 0 <= i < m, 0 <= j < n every element
    // mi, j is mapped to the (i x n + j)-th element of the container for row major
    // orientation or the (i + j x m)-th element of the container for column major
    // orientation.
    //
    // The standard representation is
    // typedef struct {
    //   int rows;
    //   int cols;
    //   double * data;
    // } matrix;
    //
    // Written as a templated class definition in DSMatrix.h

    // I use a typedef so I don't need to write DSMatrix<int> several times 
    typedef DSMatrix<int> intmat;

    cout << "\nDSMatrix (a single array): m3\n";
    intmat m3 = intmat(3, 4);

    m3(0, 0) = 1;
    m3(1, 1) = 1;
    m3(2, 2) = 1;

    for (int r = 0; r < m3.nrows(); ++r)
    {
        for (int c = 0; c < m3.ncols(); ++c)
            cout << m3(c, r) << " ";
        cout << "\n";
    }

    return 0;
}