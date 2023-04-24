#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "DSHashTableSet.h"

using namespace std;

int main()
{
    /* 
     * Create a set using a hash table with 7 buckets.
     * This hash table can  be used to check if a key is in the set or not.
     */

    DSHashTableSet myTable = DSHashTableSet(7);

    vector<string> strings = {"Michael", "Sam", "Peter", "Lara", "Mike", "Ian", "Lin",
                              "Sue", "Erica"};

    for (const auto &d : strings)
        myTable.insert(d);

    // look at the data structure using the debugger!

    cout << boolalpha;
    cout << "Size? " << myTable.size() << endl;
    cout << "Loading Factor? " << myTable.loading_factor() << endl;

    cout << "Contains \"Peter\"? " << myTable.contains("Peter") << endl;
    cout << "Contains \"Sarah\"? " << myTable.contains("Sam") << endl;
    cout << "Contains \"Sarah\"? " << myTable.contains("Sarah") << endl;

    cout << "Remove \"Peter\"" << myTable.remove("Peter") << endl;
    cout << "Contains \"Peter\"? " << myTable.contains("Peter") << endl;
    
    cout << "Size? " << myTable.size() << endl;
    cout << "Loading Factor? " << myTable.loading_factor() << endl;

    myTable.rehash(21); // 9 * 2 = 18; next prime is 21
    cout << "Size? " << myTable.size() << endl;
    cout << "Loading Factor? " << myTable.loading_factor() << endl;

    cout << "Contains \"Sarah\"? " << myTable.contains("Sam") << endl;

    return 0;
}