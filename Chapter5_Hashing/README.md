# Chapter 5: Hashing

Hash tables are used to store and find items based on a __key__.
The time to find items by data structure is

* list/vector: $O(N)$
* binary search tree: $O(log\ N)$
* hash table: $O(1)$

## Hash Table

A hash table is a table (array) of size $M$. 

We want to insert a (key, value) pairs. The index for the table row is calculated using a hash function $h(key)$. 

Now we can look up values by key.

The hash function should be fast and since its runtime does not depend on the number $N$ of items in the table, we get constant runtime of $O(1)$. 

Issues:

1. Does the hash function distribute the items well over the whole table?
2. What about collisions where $h(key_1) = h(key_2)$

## Hash Function

Has to return the same hash value for the same key and should be
* fast to calculate, and
* distribute the keys well (does not cluster the items in a part of the table).

[List of hash functions](https://en.wikipedia.org/wiki/List_of_hash_functions)

### For Integers

$key mod M$ + we typically choose $M$ to be prime.

### For strings

Convert the string into an integer and then hash the integer using mod. Note that letter frequencies depends on the language 
and encoding plays a role.

A simple choice that works well is to use ASCII encoding for the letters $k_0, k_1, ...$ and the following polynomial:
$$h_k = k_0 + 37 k_1 + 37^2 k_2, ...$$  

Alternatives are cryptographic hash functions like MD5 and SHA-1.

### For objects

Design a hash using hashes of all member variables.


## Collisions

Collisions happen when $h(key_1) = h(key_2)$.

Separate chaining uses a linked list for each cell in the hash table. A good hash function should have few collisions and lead to short lists.

How large should the hash table be? The loading factor is

$$\lambda = \frac{\text{number of items in table}}{\text{table size}}= \frac{N}{M}.$$

$\lambda$ is the average length of the linked list. Search requires on average 
 $1 + (\lambda / 2)$ link traversals. General rule is to choose $M \approx N \rightarrow \lambda \approx 1$.

Rehashing: If the loading factor gets too large, then allocate a table with double the size and
  insert the data in $O(N)$ operations. 

Alternatives are probing, double hashing, perfect hashing, universal hashing and many more.

## Hash Tables in the STL

STL provides [`std::unordered_set`](https://cplusplus.com/reference/unordered_set/unordered_set/) and [`std::unordered_map`](https://cplusplus.com/reference/unordered_map/unordered_map/). The keys need to have `operator==` and a `hash` function (or a provided function object).

STL also provides hash functions as templated function objects as [`std::hash`](https://cplusplus.com/reference/functional/hash/)

Unordered maps are often faster then regular maps, but this depends on the data and needs to be
tested in an experiment.
