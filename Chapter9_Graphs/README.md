# Chapter 9: Graphs

We will focus on the data structures. Algorithms will be covered in the algorithms class.

## Definitions

A **graph** $G = (V, E)$ consists of a set of **vertices** and a 
set of **edges.** An edge pair $(v, w) \in E$ indicates that $v$ and $w$ are 
connected. If the pair is ordered then the graph is **directed**.
$v$ is said to be **adjacent** to $w$. Edges have sometimes associated 
weights (representing distances or costs).

A **path** is a sequence of vertices $w_1, w_1, ..., w_N$ such that
$(w_i,w_{i+1}) \in E, i = 1, 2, ... N$. The length of the path is the 
number of edges $N - 1$. **Loops** may be allowed.

**Acyclic graphs** have no cycles, i.e., several paths between the same nodes.

A graph is **connected** if there exists a path from every vertex to 
every other vertex.

## Data Structures

### Adjacency Matrix

A matrix where for each edge $(u, v)$ in the graph, the corresponding matrix entry $A[u, v] = true$ 
while the rest of the matrix is $false$. Often 0 and 1 or 0 and the edge weight are used.

Storage requirement is $O(|V|^2)$ which is only useful for **dense** graphs. Remember, the graph density is defined
by the number of edges over the total possible number of edges, i.e., for a simple undirected graph this is

$$
D = \frac{|E|}{|V| \choose 2} = \frac{2|E|}{|V|(|V-1|)}.
$$

For directed graphs, the density needs to be divided by two since edges in both directions are distinct.

### Adjacency List

Each vertex has a list with the adjacent vertices. The vertex lists are typically stored in a vector for fast access using the 
vertex ID or in a hash table.

Storage requirement is $O(|E| + |V|)$. This is the standard representation for **sparse** graphs since these have
$|E| + |V| \ll |V|^2$.

### Sparse Representation of the Adjacency Matrix

Space: $O(|E|)$ 

* Tuple representation directly stores the edge pair $(v, w). Time: $O(|E|)$ ($O(1)$ with hashing)
* Compressed sparse row (or column) representation.

Both sparse matrix representations are available in libraries for all major programming languages 
and support sparse linear algebra typically based on the C BLAS and LAPACK libraries.
See [Sparse matrix](https://en.wikipedia.org/wiki/Sparse_matrix). 

## Simple Example Code

See [graph](graph).

## Popular C++ Libraries 

### Boost Graph Library (BGL)

The [C++ Boost Libraries](https://www.boost.org/) are the second place after the STL, you should look for data structures and algorithms. It contains the [BGL](https://www.boost.org/doc/libs/1_79_0/libs/graph/doc/index.html) which implements
templated data structures (like [adjacency lists](https://www.boost.org/doc/libs/1_79_0/libs/graph/doc/adjacency_list.html)) and algorithms in a portable way.

Sparse matrices are available in Boost's [uBLAS](https://www.boost.org/doc/libs/1_79_0/libs/numeric/ublas/doc/index.html).

### Armadillo

The [Armadillo](https://en.wikipedia.org/wiki/Armadillo_(C%2B%2B_library)) library is a very convenient interface for high-performance linear algebra. 