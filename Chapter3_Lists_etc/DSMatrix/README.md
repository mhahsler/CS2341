# Matrix

Matrices and their higher-dimensional extensions called tensors are an important
data structure for liner algebra and its use in machine learning (sepecially deep learning).

Textbooks often implement a matrix as a array-of-arrays and access elements with 
`[row][column]`.

```cpp
int rows = 3;
int cols = 4;

int **m = new int *[rows];
for (int r = 0; r < rows; ++r)
    m[r] = new int[cols];


m[1][1] = 1;
```

**Don't do this!**

For matrices and efficient matrix operations, you should think 
[_BLAS (Basic Linear Algebra Subprograms)_](https://en.wikipedia.org/wiki/Basic_Linear_Algebra_Subprograms). BLAS is the standard used in most programming languages (NumPy, R, MATLAB). For C++ you should look at [uBLAS in the C++ Boost Libraries](https://www.boost.org/doc/libs/1_63_0/libs/numeric/ublas/doc/index.html).

The standard representation is
 ```cpp
typedef struct {
   size_t rows;
   size_t cols;
   double* data;
   } matrix;
```   

For a $(m \times n)$-dimensional matrix and $0 <= i < m$, $0 <= j < n$ every element
$m_i, j$ is mapped to the $(i \times n + j)$-th element of the container for row major
orientation or the $(i + j \times m)$-th element of the container for column major
orientation.

Iterators would just iterate through all elements in the order in which they are stored in `data`.
