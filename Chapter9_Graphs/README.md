# Chapter 9: Graphs

We will focus on the data structures.

## Definitions

A **graph** $G = (V, E)$ consists of a set of **vertices** and a 
set of **edges.** An edge pair $(v, w) \in E$ indicates that $v$ and $w$ are 
connected. If the pair is ordered then the graph is **directed**.
$v$ is said to be **adjacent** to $w$. Edges have sometimes associated 
weigths/costs.

A **path** is a sequence of vertices $w_1, w_1, ..., w_N$ such that
$(w_i,w_{i+1}) \in E, i = 1, 2, ... N$. The length of the path is the 
number of edges $N - 1$. **Loops** may be allowed.

**Acyclic graphs** have no cycles, i.e., several paths between the same nodes.

A graph is **connected** if there exists a path from every vertex to 
every other vertex.

## Data Structures

### Adjacency Matrix

For each edge $(u, v)$, $A[u, v] = true$ while the rest of the matrix is $false$.

Storage requirement is $O(|V|^2)$ which is only useful for **dense** graphs.

### Adjacency List

Each vertex has a list with the adjacent vertices.

Storage requirement is $O(|E| + |V|)$. This is the standard representation for **sparse** graphs.

### Sparse Representation for the Adjacency Matrix

Space: $O(|E|)$ 

* Tuple representation. Time: $O(|E|)$ ($O(1)$ with hashing)
* Compressed sparse row (or column) representation.

See [Sparse matrix](https://en.wikipedia.org/wiki/Sparse_matrix). 

## Implementation in the Boost Graph Library (BGL)

The [C++ Boost Libraries](https://www.boost.org/) are the second place after the STL, you should look for data structures and algorithms. It contains the [BGL](https://www.boost.org/doc/libs/1_79_0/libs/graph/doc/index.html) which implements
templated data structures (like [adjacency lists](https://www.boost.org/doc/libs/1_79_0/libs/graph/doc/adjacency_list.html)) and algorithms in a portable way.

Sparse matrices are available in Boost's [uBLAS](https://www.boost.org/doc/libs/1_79_0/libs/numeric/ublas/doc/index.html).
