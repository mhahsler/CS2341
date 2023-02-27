#include <iostream>
#include <vector>
#include "DSMatrix.h"


int main()
{
    // Standard textbook way of creating an array of arrays
    size_t rows = 3;
    size_t cols = 4;

    std::cout << "Array of arrays: m1\n";
    // allocate the array for the rows and then allocate each row
    int **m1 = new int *[rows];
    for (size_t r = 0; r < rows; ++r)
        m1[r] = new int[cols];

    m1[0][0] = 1;
    m1[1][1] = 1;
    m1[2][2] = 1;

    // print the matrix
    for (size_t r = 0; r < rows; ++r)
    {
        for (size_t c = 0; c < cols; ++c)
            std::cout << m1[r][c] << " ";
        std::cout << "\n";
    }

    // clean up memory
    for (size_t r = 0; r < rows; ++r)
        delete[] m1[r];
    delete[] m1;

    std::cout << "\nstd::vector of std::vectors (STL): m2\n";
    // This takes care of memory management

    // make the std::vector of rows and then create each row std::vector
    std::vector<std::vector<int>> m2 = std::vector<std::vector<int>>(rows);
    for (auto &r : m2)
        r = std::vector<int>(cols);

    m2[0][0] = 1;
    m2[1][1] = 1;
    m2[2][2] = 1;

    for (auto &r : m2)
    {
        for (auto &c : r)
            std::cout << c << " ";
        std::cout << "\n";
    }

    // ********************* IMPORTANT **************************
    // Don't use array of arrays or std::vector of std::vectors unless you have a very good reason!
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
    //   size_t rows;
    //   size_t cols;
    //   double * data;
    // } matrix;
    //
    // Written as a templated class definition in DSMatrix.h

    // I use a typedef so I don't need to write DSMatrix<int> all the time
    typedef DSMatrix<int> IntMatrix;

    std::cout << "\nDSMatrix (a single array): m3\n";
    IntMatrix m3 = IntMatrix(3, 4);

    m3(0, 0) = 1;
    m3(1, 1) = 1;
    m3(2, 2) = 1;

    std::cout << m3;

    return 0;
}