
#ifndef DSHASHTABLE_H
#define DSHASHTABLE_H

#include <string>
#include <vector>
#include <forward_list>

#include<iostream>

using namespace std;

// Hash example for a set of strings. Only uses keys (no values).

class DSHashTable
{
private:
    // a hash table with a singly-linked list for separate chaining
    vector<forward_list<string>> table;

public:
    // default constructor
    explicit DSHashTable(size_t size = 101)
    {
        // call resize for vector to get the empty lists
        table.resize(size);
    }

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

    bool remove()
    {
        cout << "Needs to be implemented!" << endl;
        return false;
    }

    bool contains(const string &x) const
    {
        // find bucket
        auto &whichEntry = table[calcHash(x)];
        
        // search list
        return find(begin(whichEntry), end(whichEntry), x) != end(whichEntry);
    }

    void makeEmpty()
    {
        cout << "Needs to be implemented!" << endl;
    }

    // size, get keys, iterator, etc. are missing

private:
    size_t calcHash(const string &x) const
    {
        // calculate hash value for a string using a polynomial hash function
        size_t hashVal = 0;
        
        for (const auto &c : x)
            hashVal = 37 * hashVal + c;
            
        return hashVal % table.size();
    }
};

#endif