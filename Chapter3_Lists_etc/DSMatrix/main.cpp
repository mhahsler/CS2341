#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Use a vector of vectors
    int rows = 3;
    int cols = 4;

    int **m = new int *[rows];
    for (int r = 0; r < rows; ++r)
        m[r] = new int[cols];

    m[0][0] = 1;
    m[1][1] = 1;
    m[2][2] = 1;

    cout << "m:\n";
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
            cout << m[r][c] << " ";
        cout << "\n";
    }

    // clean up memory
    for (int r = 0; r < rows; ++r)
        delete[] m[r];

    delete[] m;

    // we could also use STL vectors
    // vector<vector<int>> m = vector<vector<int>>(rows);
    // for (auto &r : m)
    //     r = vector<int>(cols);
    // for (auto &r : m)
    // {
    //     for (auto &c : r)
    //         cout << c << " ";
    //     cout << "\n";
    // }

    // ********************* Don't do this! ***********************
    // *************** Even if textbooks describe it! *************
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
    // Written as a class definition

    class DSMatrix
    {
    private:
        int rows;
        int cols;
        double *data;

    public:
        DSMatrix(int _rows, int _cols) : rows{_rows}, cols(_cols)
        {
            data = new double[_cols * _rows];
        }

        ~DSMatrix()
        {
            delete[] data;
        }

        // we would overload [], but C++ currently does not
        // allow more then one parameters for []
        double &operator()(int col, int row)
        {
            return data[col * rows + row];
        }

        void print()
        {
            for (int r = 0; r < rows; ++r)
            {
                for (int c = 0; c < cols; ++c)
                    cout << (*this)(c, r) << " ";
                cout << "\n";
            }
        }
    };

    DSMatrix m2 = DSMatrix(3, 4);

    m2(0, 0) = 1;
    m2(1, 1) = 1;
    m2(2, 2) = 1;

    cout << "m2:\n";
    m2.print();

    return 0;
}