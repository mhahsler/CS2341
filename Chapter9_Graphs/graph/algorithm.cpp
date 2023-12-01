#include <iostream>
#include <vector>

// You need boost installed
// Ubuntu: sudo apt-get install libboost-all-dev
// Windows: http://www.boost.org/users/download/    
// MacOS: brew install boost
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

// Simple example to find paths between vertices of a graph.

int main()
{
    std::cout << std::boolalpha;
    
    // define types for more readable code
    typedef int vertex;
    typedef std::pair<vertex, vertex> edge;

    // Define a graph (a vector of edge tuples)
    std::vector<vertex> vertices = {0, 1, 2, 3};
    std::vector<edge> edges = {edge(0, 1), edge(1, 0), edge(1, 2), edge(2, 2), edge(2, 3), edge(3, 3)};

    // Create a adjacency matrix using matrix in boost::numeric::ublas
    matrix<int> adjacencyMatrix(vertices.size(), vertices.size());
    
    for (auto &e : edges)
        adjacencyMatrix(e.first, e.second) = 1;    
    
    std::cout << "Adjacency matrix: ";
    std::cout << adjacencyMatrix << "\n";

    // Paths of a given length can be found using matrix multiplication of the adjacency matrix.
    matrix<int> m = adjacencyMatrix;

    std::cout << "Adjacency matrix squared: ";
    m = prod(m, adjacencyMatrix);  // prod is the matrix multiplication function defined in boost::numeric::ublas
    std::cout << m << "\n";

    std::cout << "Is there a path length 1 between 0 and 3? ";
    std::cout << (m(0, 3) == 1) << "\n";
   
    std::cout << "Adjacency matrix cubed:";
    m = prod(m, adjacencyMatrix);
    std::cout << m << "\n";

    std::cout << "Is there a path length 2 between 0 and 3? ";
    std::cout << (m(0, 3) == 1) << std::endl;

    /* Notes:
     * * Use a sparse matrix for large sparse graphs.
     * * An alternative algorithm is tree search using the adjacency list.
     */

    return 0;
}
