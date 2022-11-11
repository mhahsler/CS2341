#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "DSHashTable.h"

using namespace std;

int main()
{
    // Create a hash table with 7 buckets
    // Note: this implementation only uses a key, but no separate value. This hash table can 
    //   check if a key is in the table or not.
    DSHashTable myTable = DSHashTable(7);

    vector<string> strings = {"Michael", "Sam", "Peter", "Lara", "Mike", "Ian", "Lin",
                              "Sue", "Erica"};

    for (const auto &d : strings)
        myTable.insert(d);

    // look at the data structure using the debugger!

    cout << boolalpha;
    cout << "Contains \"Peter\"? " << myTable.contains("Peter") << endl;
    cout << "Contains \"Sarah\"? " << myTable.contains("Sarah") << endl;

    return 0;
}