#include <iostream>
#include <vector>
#include <forward_list>
#include <unordered_set>

// You need boost installed
#include <boost/functional/hash/hash.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace std;


// Simple example where vertices are represented as integers (i.e., vertex ID).

int main()
{
    // define types for more readable code
    typedef int vertex;
    typedef pair<vertex, vertex> edge;

    // Representation 1: Tuple representation (a vector of edge tuples)
    vector<vertex> vertices = {0, 1, 2, 3};
    vector<edge> edges = {edge(0, 1), edge(0, 2), edge(1, 2), edge(2, 3)};
    
    cout << "Tuple representation (vector):\n";
    for (const auto &e : edges)
        cout << "(" << e.first << ", " << e.second << ")" << "\n";
    cout << endl;

    //Note: searching the vector for an edge is O(|E|).
    
    // Representation 2: Tuple representation (a hash of edge tuples)
    
    // Notes: * unordered_set is a hash so we get O(1) access.
    //        * the STL does not provide hash functions for pairs. Boost libraries provide boost::hash.
    //        * Constructor for a load factor of 1 (table size should be N)
    unordered_set<edge, boost::hash<edge>> edges_hashed = unordered_set<edge, boost::hash<edge>>(edges.size());
    for (auto &e : edges)
        edges_hashed.insert(e);

    cout << "Tuple representation (hash):\n";
    for (auto &e : edges_hashed)
        cout << "(" << e.first << ", " << e.second << ")\n";

    // find edges fast
    cout << std::boolalpha;
    cout << "1 -> 2? " << (edges_hashed.find(edge(1, 2)) != edges_hashed.end()) << "\n";
    cout << "1 -> 3? " << (edges_hashed.find(edge(1, 3)) != edges_hashed.end()) << "\n";
    cout << endl;

    
    // Representation 3: Adjacency List (vector of singly-linked lists)
    vector<forward_list<vertex>> adjacencyList = vector<forward_list<vertex>>(vertices.size());
    for (auto &e : edges)
        adjacencyList[e.first].push_front(e.second);


    cout << "Adjacency list:\n";
    for (size_t v = 0; v < adjacencyList.size(); ++v)
    {
        cout << v << ":";
        for (const auto &v2 : adjacencyList[v])
            cout << " " << v2;
        cout << "\n";
    }
    
    cout << endl;



    // Note: fast lookup by vertex ID (O(1))!


    // Representation 4: Adjacency matrix
    boost::numeric::ublas::matrix<int> adjacencyMatrix(vertices.size(), vertices.size());
    for (auto &e : edges)
        adjacencyMatrix(e.first, e.second) = 1;    
    
    cout << "Adjacency matrix:\n";
    cout << adjacencyMatrix << endl;

    // Note: dense adjacency representation are easy to work with using row/col indices, but they
    // only works for small graphs with few vertices since it is O(|V|^2) in space. 
    // Use one of the other representations or a sparse matrix representation.

    return 0;
}
