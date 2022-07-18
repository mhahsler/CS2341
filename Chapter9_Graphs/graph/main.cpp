#include <iostream>
#include <vector>
#include <forward_list>
#include <unordered_set>

// You need boost installed
#include <boost/functional/hash/hash.hpp>

using namespace std;

int main()
{
    typedef int vertex;
    typedef pair<vertex, vertex> edge;

    // tuple representation
    vector<vertex> vertices = {0, 1, 2, 3};
    vector<edge> edges = {edge(0, 1), edge(0, 2), edge(1, 2), edge(2, 3)};

    // Adjacency matrix is just a simple matrix, but takes too much memory

    // Adjacency List
    vector<forward_list<vertex>> adjacencyList = vector<forward_list<vertex>>(vertices.size());
    for (auto &e : edges)
        adjacencyList[e.first].push_front(e.second);

    // Notes: forward_list is singly linked

    cout << "adjacency list:\n";
    for (size_t v = 0; v < adjacencyList.size(); ++v)
    {
        cout << v << ":";
        for (auto &v2 : adjacencyList[v])
            cout << " " << v2;
        cout << "\n";
    }
    cout << "\n";

    // Dictionary of keys
    unordered_set<edge, boost::hash<edge>> dictOfKeys = unordered_set<edge, boost::hash<edge>>(edges.size());
    for (auto &e : edges)
        dictOfKeys.insert(e);

    // Notes: * unordered_set is a hash so we get O(1) access.
    //        * the STL does not provide hash functions for pairs. Boost libraries do.
    //        * Constructor for a load factor of 1 (table size should be N)

    // print all edges. loop can also be used to dump the has into a tuple presentation.
    cout << "edges in dictionary:\n";
    for (auto &e : dictOfKeys)
        cout << e.first << " -> " << e.second << "\n";

    // try an non-existing edge
    cout << std::boolalpha;
    cout << "4 -> 1? " << (dictOfKeys.find(edge(4, 1)) != dictOfKeys.end()) << "\n\n";

    return 0;
}
