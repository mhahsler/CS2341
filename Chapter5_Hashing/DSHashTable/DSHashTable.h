
#ifndef DSHASHTABLE_H
#define DSHASHTABLE_H

#include <vector>
#include <list>

#include<iostream>

using namespace std;

template <typename Object>
class DSHashTable
{
private:
    vector<list<Object>> table;
    hash<Object> hasher;

public:
    // default constructor
    explicit DSHashTable(int size = 101)
    {
        table.resize(size);
    }

    // needs a copy constructor, assignment etc.

    bool insert(const Object &x)
    {
        auto &whichEntry = table[calcHash(x)];
        if (find(begin(whichEntry), end(whichEntry), x) != end(whichEntry))
            return false;

        whichEntry.push_back(x);
        return true;
    }

    bool remove()
    {
        cout << "Needs to be implemented!" << endl;
        return false;
    }

    bool contains(const Object &x) const
    {
        auto &whichEntry = table[calcHash(x)];
        return find(begin(whichEntry), end(whichEntry), x) != end(whichEntry);
    }

    bool makeEmpty()
    {
        cout << "Needs to be implemented!" << endl;
        return false;
    }

    // size, get keys, iterator, etc. are missing

private:
    size_t calcHash(const Object &x) const
    {
        return hasher(x) % table.size();
    }
};

#endif