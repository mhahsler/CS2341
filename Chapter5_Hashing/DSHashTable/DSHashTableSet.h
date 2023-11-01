#ifndef DSHASHTABLESET_H
#define DSHASHTABLESET_H

#include <string>
#include <vector>
#include <forward_list>
#include <stdexcept>


/**
 * @brief Simple hash table class for a hashed set of strings.
 */
class DSHashTableSet
{
private:
    // a hash table with a singly-linked list for separate chaining
    std::vector<std::forward_list<std::string>> table;
    // Note: for a map, the list would be a list of pairs (key, value)

public:
    /**
     * @brief  default constructor
     * @param size size of the hash table. Should be a prime number for better distribution in the hash table.
     */
    explicit DSHashTableSet(size_t size = 101)
    {
        // call resize for vector to get the table with empty lists
        table.resize(size);
    }

    /**
     * Rule of 3: Not needed! We avoid the use of dynamic memory allocation, so the compiler defaults work.
     */


    /**
     * @brief insert a key into the hash table
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool insert(const std::string &x)
    {
        // 1. find the place in the hash table (often called a bucket) using hash function in O(1)
        // whichEntry is a reference to the list in the hash table
        auto &whichEntry = table[calcHash(x)];
        
        // 2. check the list to see if the item is already there. 
        // This uses linear search but lists are hopefully short -> O(1)
        if (std::find(whichEntry.begin(), whichEntry.end(), x) != whichEntry.end())
            return false;

        // 3. add the item to the front of the list in O(1)
        whichEntry.push_front(x);
        
        return true;
    }

    /**
     * @brief remove a key from the hash table
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool remove(const std::string &x)
    {
        // 1. find bucket using hash function in O(1)
        auto &whichEntry = table[calcHash(x)];
        
        // 1. check the list to see if the item is in the list. Lists are hopefully short -> O(1)
        if (std::find(whichEntry.begin(), whichEntry.end(), x) == whichEntry.end())
            return false;
        
        // 2. remove the item from the list. Lists are hopefully short -> O(1)
        whichEntry.remove(x);
        return true;
    }

    /**
     * @brief find a key in the hash table
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool contains(const std::string &x) const
    {
        // 1. find bucket
        auto &whichEntry = table[calcHash(x)];
        
        // 2. search list
        return std::find(whichEntry.begin(), whichEntry.end(), x) != whichEntry.end();
    }

    /**
     * @brief make the hash table empty
     */
    void make_empty()
    {
        // clear all lists in the hash table
        for (auto& entry : table)
            entry.clear();
    }

    /**
     * @brief number of elements stored in the hash table
     * 
     * @return size_t 
     */
    size_t size() const
    {
        size_t n = 0;

        // Notes: 
        // * forward_list currently has no size() function and I need to use a loop.
        // * k is unused. C++17 supports [[maybe_unused]] to suppress the compiler warning
        // * This is O(N) since we have to iterate over all lists in the hash table!
        for (const auto& entry : table)
            for ([[maybe_unused]] const auto& k : entry)
                ++n;

        return n;
    }

    /**
     * @brief return the current loading factor of the hash table. 
     * 
     * @return double
     */
    double loading_factor() const
    {
        // Note: size is an integer type so we need to cast one to double to get a double division
        return double(size()) / table.size();
    }


    /**
     * @brief Rehash the hash table
     * 
     * @param theSize new size of the hash table. Should be a prime number. 
     * 
     * Usually automatically increases the hash table size by a factor of 2 and finds the next prime number once 
     * the load_factor gets >1 during insert().
     * 
     * Here. I manually call rehash and specify the new hash table size.
     * 
     * Notes:
     * - I avoid manual dynamic memory allocation by creating a new table on the stack and then
     *   swap all its data and pointers with the old table. The old table is then deleted automatically when 
     *   tmp_table goes out of scope.
     * 
     * - I avoid copying the stored string using move semantics. std::move() marks an object as a rhs references 
     *   (an object that can be moved during the next assignment if it has a move assignment 
     *   operator). It is the programmers job to make sure that the original object is 
     *   not used after the move.
     */

    void rehash(size_t theSize)
    {
     
        // 1. create a new empty table of the new size
        std::vector<std::forward_list<std::string>> tmp_table;
        tmp_table.resize(theSize);

        // 2. swap the old with the new empty table
        std::swap(table, tmp_table);
        
        // 3. insert (move) the entries from the old table (now tmp_table) into the new table (now table)
        for (const auto& entry : tmp_table)
            for (const auto& k : entry)
                insert(std::move(k));

        // 4. The old table gets deleted since tmp_table is on the function call stack
    }

    // more useful functions would be nice: get keys, iterators, etc.

private:
    /**
     * @brief calculate the hash value for a string using the standard polynomial hash function.
     *
     * Note that 37^i is broken down to repeated multiplications with 37 which is 
     * a lot faster then calling `pow()` from cmath (math.h)
     * 
     * The STL already provides a hash function for strings (std::hash), but this is a good example 
     * for a hash function.
     * 
     * @param x 
     * @return size_t 
     */
    size_t calcHash(const std::string &x) const
    {
        size_t hashVal = 0;
        
        // 1. convert string to integer
        for (const auto &c : x)
            hashVal = 37 * hashVal + c;
            
        // 2. reduce to table size using modulo
        return hashVal % table.size();
    }
};

#endif