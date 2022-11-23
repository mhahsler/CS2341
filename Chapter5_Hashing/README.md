# Chapter 5: Hashing

Hash tables are used to store and find items based on a __key__ very quickly.
For __sets,__ we only have a $key$ representing the 
values in the set and we can check if the key is in the set.
For __maps,__ we use $(key, value)$ pair to quickly
map a key to its value.

The time complexity to find or insert items by data structure is

* Vector: $O(N)$
* List: $O(N)$ (insertion at the front can be done in $O(1)$)
* Binary search tree: $O(log\ N)$
* **Hash table: $O(1)$**

## Hash Table

A hash table is an auxiliary data structure with a table (array) of size $M$ to store keys that help us with finding the stored elements again.

### Insert
Insert Operation for a $(key, value)$ pair.

1. Calculate the index for the table row using a hash function $h(key)$ that maps each possible key to a 
valid row in the table. 
2. Place the $(key, value)$ pair in that row.

### Lookup
Lookup Operation for a key
1. Calculate the index for the table row using a hash function $h(key)$.
2. Retrieve the value the table row.

The runtime of the hash function only depends on how the key is represented and not on the number elements $N$ in the table. Therefore, we get constant runtime of $O(1)$. 

**Note:** Hash tables do not store entries in any particular order! 

**Example:** Hash (SMUID, name) pairs to allow for fast SMUID to name lookup. We can use the first digit of the ID as a simple hash function (this may not be a great hash function!).


### Issues

1. We need to choose the hash table size $M$. 
2. We want a hash function that distributes the items well over the whole table. We do not want to allocate a very large table that is mostly empty!
3. What about collisions where $h(key_1) = h(key_2)$?

## Hash Function

Has to return the **same hash value for the same key** and should be
* fast to calculate, and
* distribute the keys well (does not cluster the items in a part of the table).


### For Integers
$$h(key) = key\ mod\ M$$ 

We typically choose $M$ to be prime since this greatly reduces the occurrence of collisions (see below).

### For Strings

Convert the string into an integer and then hash the integer using $mod$. This is technically a composition of two hash functions $h_{mod}(h_{int}(string))$.

A simple choice that works well is to use ASCII encoding for the letters to get the numbers $k_0, k_1, ..., k_{n-1}$ and then the following polynomial (remember [numeral systems](https://en.wikipedia.org/wiki/Numeral_system)):
$$h(k) = (k_0 + 37 k_1 + 37^2 k_2, ...)\ mod\ M = \sum_{i=0}^{n-1} 37^i k_i\ mod\ M$$  

Alternatives are cryptographic hash functions like MD5 and SHA-1. See [List of hash functions](https://en.wikipedia.org/wiki/List_of_hash_functions). These hash functions convert a sequence of byte into an integer key and we use then the modulo to 
calculate the index for the hash table. 

### For Objects

Design a hash using hashes of all member variables and combine them into a single hash.


## Collisions

Collisions happen when $h(key_1) == h(key_2)$. Collisions cannot be prevented.

The standard method is to use **separate chaining.** It uses a linked list for each cell in the hash table to store all
the items that hash to the same value. 
We can insert at the beginning of the list in $O(1)$. A good hash function should 
have few collisions and lead to short lists.

See Example [DSHashTable](DSHashTable) which implements a hashed set.

Alternatives to separate chaining are probing, double hashing, perfect hashing, universal hashing and many more.

## Hash Table Size

How large should the hash table be? The loading factor of a hash table is defined as

$$\lambda = \frac{\text{number of items in table}}{\text{table size}}= \frac{N}{M}.$$

$\lambda$ gives the average number of collisions which is also the average length of the linked list. 
Search therefore requires on average $1 + (\lambda / 2)$ link traversals. A general rule is to choose 

$$M \approx N \rightarrow \lambda \approx 1$$

**Rehashing:** If the loading factor gets too large, then allocate a table with double the size and insert the data from the old table in $O(N)$ operations. 



## STL Hash Tables

STL provides [`std::unordered_set`](https://cplusplus.com/reference/unordered_set/unordered_set/) and [`std::unordered_map`](https://cplusplus.com/reference/unordered_map/unordered_map/). The keys need to have `operator==` and a `hash` function (or a provided function object).

The STL structures automatically [rehash](https://cplusplus.com/reference/unordered_set/unordered_set/rehash/) when the load factor gets to high.

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