#ifndef DSHASHTABLE_H
#define DSHASHTABLE_H

#include <string>
#include <vector>
#include <forward_list>
#include <iostream>

using namespace std;

/**
 * @brief Simple hash table class for a hashed set of strings. Only uses keys (no values).
 */
class DSHashTable
{
private:
    // a hash table with a singly-linked list for separate chaining
    vector<forward_list<string>> table;

public:
    /**
     * @brief  default constructor
     * @param size 
     */
    explicit DSHashTable(size_t size = 101)
    {
        // call resize for vector to get the empty lists
        table.resize(size);
    }

    /**
     * @brief insert a key into the hash table
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool insert(const string &x)
    {
        // find bucket using hash function
        auto &whichEntry = table[calcHash(x)];
        
        // check the list to see if the item is already there
        if (find(begin(whichEntry), end(whichEntry), x) != end(whichEntry))
            return false;

        // add the item to the front of the list in O(1)
        whichEntry.push_front(x);
        
        return true;
    }

    /**
     * @brief remove a key from the hash table (not implemented)
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool remove()
    {
        cout << "Needs to be implemented!" << endl;
        return false;
    }

    /**
     * @brief find a key in the hash table
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool contains(const string &x) const
    {
        // find bucket
        auto &whichEntry = table[calcHash(x)];
        
        // search list
        return find(begin(whichEntry), end(whichEntry), x) != end(whichEntry);
    }

    /**
     * @brief make the hash table empty (needs to be implemented)
     */
    void makeEmpty()
    {
        cout << "Needs to be implemented!" << endl;
    }

    /**
     * @brief number of elements stored in the hash table (needs to be implemented)
     * 
     * @return size_t 
     */
    size_t size() const
    {
        cout << "Needs to be implemented!" << endl;
        return 0;
    }

    /**
     * @brief Rehash the hash table (needs to be implemented)
     * 
     * Increases the hash table size by a factor of 2.
     * This would be called by insert() if the loading factor gets too high.
     */
    void rehash()
    {
        cout << "Needs to be implemented!" << endl;
    }

    // more useful functions get keys, iterators, etc.

private:
    /**
     * @brief calculate the hash value for a string using the standard polynomial hash function.
     *
     * Note that 37^i is broken down to repeated multiplications with 37 which is 
     * a lot faster then calling `pow()` from cmath (math.h)
     * 
     * @param x 
     * @return size_t 
     */
    size_t calcHash(const string &x) const
    {
        size_t hashVal = 0;
        
        for (const auto &c : x)
            hashVal = 37 * hashVal + c;
            
        return hashVal % table.size();
    }
};

#endif