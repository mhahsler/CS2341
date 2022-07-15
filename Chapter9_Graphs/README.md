# Chapter 9: Graphs

We will focus on the data structures.

## Definitions

A **graph** $G = (V, E)$ consists of a set of **vertices** and a 
set of **edges.** An edge pair $(v, w) \in E$ indicates that $v$ and $w$ are 
connected. If the pair is ordered then the graph is **directed**.
$v$ is said to be **adjacent** to $w$. Edges have sometimes associated 
weigths/costs.

A **path** is a sequence of vertices $w_1, w_1, ..., w_N$ such that
$(w_i,w_{i+1} \in E), i = 1, 2, ... N$. The length of the path is the 
number of edges $N - 1$. **Loops** may be allowed.

**Acyclical graphs** have no cycles, i.e., several paths between the same nodes.

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

Tuple representation.

Compressed sparse row (or column) representation.

See [Sparse matrix](https://en.wikipedia.org/wiki/Sparse_matrix).
