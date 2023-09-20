#include <iostream>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

/* Notes: 
 * * You need to install the boost library. 
 * * it currently uses unsigned int for rows and column indices
 * * it uses size1 and size2 for row and column sizes
 */

typedef boost::numeric::ublas::matrix<double> matrix_double;

int main()
{
    matrix_double m(3, 3);
    for (unsigned i = 0; i < m.size1(); ++i)
        for (unsigned j = 0; j < m.size2(); ++j)
            m(i, j) = 3 * i + j;

    // use the builtin print function        
    std::cout << m << "\n\n";

    // print the matrix element by element
    for (size_t r = 0; r < m.size1(); ++r) {
        for (size_t c = 0; c < m.size2(); ++c)
            std::cout << m(r,c) << " ";
        std::cout << "\n";
    }

    return 0;
}