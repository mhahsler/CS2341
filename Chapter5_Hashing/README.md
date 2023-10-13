# Chapter 5: Hashing

## Recap: Sets and Maps

A [set](https://en.wikipedia.org/wiki/Set_(mathematics)) is a collection of elements defined in math. For example,
the set 
$$\{3, 6, 7\}$$ 
contains three elements. Sets cannot contain duplicate entries and the order of elements is irrelevant. Typical operations for sets are to determine if a set contains a specific element (which requires finding it) and set operations between sets (union, intersection, etc.).

A [map](https://en.wikipedia.org/wiki/Associative_array) in computer science is a collection of $(key, value)$ pairs. Maps are often also called associative arrays, dictionaries,
or just look-up tables. In math, a map represents a function with finite domain represented by a table. 
The map 

`grades = {"Michael": 80, "Hannah": 99, "Lin": 95}` 

would mean that the key Michael maps to the value 80 
(i.e., has an 80 in the class). We typically want to find values fast given that we know the key. 

We can look at sets as maps that have only a key and no value. 

The worst-case time complexity to find or insert items by data structure are:

* Vector of key-value pairs: $O(N)$
* List of key-value pairs: $O(N)$. Insertion at the front can be done in $O(1)$
* Binary search tree using the key for sorting and storing the value in each node: $O(log\ N)$
* **Hash table: $O(1)$** (under some assumptions)

## Hash Table

A hash table is a data structure with a table of size $M$ to store keys that help us with finding the stored elements again. We use a hash function

$$h(key)$$

that maps each possible key to a valid row in the table. 


### Insert
Insert Operation for a $(key, value)$ pair.

1. Calculate the index for the table row using the hash function $h(key)$.
2. Place the $(key, value)$ pair in that row.

The runtime of the hash function only depends on how the key is represented and not on the number elements $N$ in the table. 
Finding the place in a table given the index is $O(1)$, therefore, we get constant runtime of $O(1)$.


### Lookup
Lookup Operation for a key
1. Calculate the index for the table row using a hash function $h(key)$.
2. Retrieve the value the table row.

Also a worst-case time complexity of $O(1)$.


**Note:** Hash tables do not store keys in any particular order! 

### Example
Hash (SMUID, name) pairs to allow for fast SMUID to name lookup. We can use the first digit of the ID as a simple hash function (this may not be a great hash function!).


### Issues

1. We need to choose a hash function. We want a hash function that distributes the keys well over the whole table because we do not want to allocate a very large table that is mostly empty!
2. What about collisions where $h(key_1) = h(key_2)$?
3. We need to choose the hash table size $M$.

## Hash Functions

Has to return the **same hash value for the same key** and should be
* fast to calculate, and
* distribute the keys well (does not cluster the keys in a part of the table).


### For Integers
$$h(key) = key\ mod\ M$$ 

We typically choose $M$ to be prime since this is known to greatly reduces the occurrence of collisions.

### For Strings

Convert the string into an integer and then hash the integer using $mod$. This is technically a composition of two hash functions $h_{mod}(h_{int}(string))$.

A simple choice that works well is to use ASCII encoding for the letters to get the numbers $k_0, k_1, ..., k_{n-1}$ and then the following polynomial (remember [numeral systems](https://en.wikipedia.org/wiki/Numeral_system)):
$$h(k) = (k_0 + 37 k_1 + 37^2 k_2, ...)\ mod\ M = \left( \sum_{i=0}^{n-1} 37^i k_i \right) \ mod\ M$$  

Alternatives are cryptographic hash functions like MD5 and SHA-1. See [List of hash functions](https://en.wikipedia.org/wiki/List_of_hash_functions). These hash functions convert a sequence of byte into an integer key, and we use then the modulo to 
calculate the index for the hash table. 

### For Objects

Design a hash using hashes of all member variables and combine them into a single hash.


## Collisions

Collisions happen when $h(key_1) == h(key_2)$. Collisions cannot be prevented.

The standard method is to use **separate chaining.** It uses a singly-linked list for each cell in the hash table to store all
the items that hash to the same value. Inserting at the beginning of the list is $O(1)$. A good hash function should 
have few collisions and lead to short lists.

See Example [DSHashTable](DSHashTable) which implements a hashed set.

Alternatives to separate chaining are probing, double hashing, perfect hashing, universal hashing and many more.

## Hash Table Size

How large should the hash table be? The **loading factor** of a hash table is defined as

$$\lambda = \frac{\text{number of items in table}}{\text{table size}}= \frac{N}{M}.$$

$\lambda$ gives the average length of the linked lists in the hash table. A general rule to get short lists is to choose 

$$M \approx N \rightarrow \lambda \approx 1$$

If we can make sure that $\lambda$ stays constant (e.g., close to 1), then all operations are independent of $N$ and we get $O(1)$. This can be done using 
**rehashing.** If the loading factor gets too large, then reorganize the data structure by allocating a new table with double the size and then insert the data 
from the old table in $O(N)$ operations. Note that rehashing is very expensive!


## STL Hash Tables

STL provides [`std::unordered_set`](https://cplusplus.com/reference/unordered_set/unordered_set/) and [`std::unordered_map`](https://cplusplus.com/reference/unordered_map/unordered_map/). The keys need to have `operator==` and a `hash` function (or a provided function object).

The STL structures automatically [rehash](https://cplusplus.com/reference/unordered_set/unordered_set/rehash/) when the load factor gets too high.

STL also provides hash functions as templated function objects as [`std::hash`](https://en.cppreference.com/w/cpp/utility/hash)

Unordered maps (hash maps) are often faster than regular maps which use binary search trees, 
but this depends on the data and needs to be tested in an experiment.

See: [STL example code](STL)

## Some Applications

1. Lookup table with constant time. E.g., the compiler looks up variable names or a router looks up IP addresses.
2. Convert a name (a string) into a numeric ID used in an algorithm (e.g., filename to an object identifier).
3. Spell checker looks up words.


## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)