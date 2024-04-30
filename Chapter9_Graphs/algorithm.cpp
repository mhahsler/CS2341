#include <iostream>
#include <vector>

// You need boost installed
// Ubuntu: sudo apt-get install libboost-all-dev
// Windows: http://www.boost.org/users/download/    
// MacOS: brew install boost
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>


// Simple example to find paths between vertices of a graph.

int main()
{
    
    // define types for more readable code
    typedef int vertex;
    typedef std::pair<vertex, vertex> edge;

    // Define a graph (a vector of edge tuples)
    std::vector<vertex> vertices = {0, 1, 2, 3};
    std::vector<edge> edges = {edge(0, 1), edge(1, 0), edge(1, 2), edge(2, 2), edge(2, 3), edge(3, 3)};

    // Create a adjacency matrix using matrix in boost::numeric::ublas
    boost::numeric::ublas::matrix<int> adjacencyMatrix(vertices.size(), vertices.size());
    
    for (auto &e : edges)
        adjacencyMatrix(e.first, e.second) = 1;    
    
    std::cout << "Adjacency matrix  (rows): ";
    std::cout << adjacencyMatrix << "\n";

    std::cout << "How many paths of length 1 exist between 0 and 3? ";
    std::cout << adjacencyMatrix(0, 3) << "\n";


    // Paths of a given length in an unweighted graph can be found 
    // using simple matrix multiplication of the adjacency matrix.
    boost::numeric::ublas::matrix<int> m = adjacencyMatrix;

    std::cout << "Adjacency matrix squared (rows): ";
    m = boost::numeric::ublas::prod(m, adjacencyMatrix);  // prod is the matrix multiplication function defined in boost::numeric::ublas
    std::cout << m << "\n";

    std::cout << "How many paths of length 2 exist between 0 and 3? ";
    std::cout << m(0, 3) << "\n";
   
    std::cout << "Adjacency matrix cubed (rows):";
    m = boost::numeric::ublas::prod(m, adjacencyMatrix);
    std::cout << m << "\n";

    std::cout << "How many paths of length 3 exist between 0 and 3? ";
    std::cout << (m(0, 3) == 1) << std::endl;

    /* Matrix multiplications are expensive O(n^3)! Alternative algorithms (all are available in boost):
     * * Use a sparse matrix for large sparse graphs.
     * * Use tree search (depth-first, breadth-first) with breaking loops directly on the adjacency list.
     * * Dijkstra's algorithm for shortest paths (i.e., uniform cost search).
     * 
     *  see https://en.wikipedia.org/wiki/Shortest_path_problem for more information.
     */

    return 0;
}
