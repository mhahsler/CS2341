#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
    cout << "\n\nSet example:\n"
         << endl;

    // Sets are containers that store unique elements following a specific order.
    // https://cplusplus.com/reference/set/set/
    // Ordering is done using less<Object> which defaults to operator<

    // sets are implemented as a balanced binary search tree (typically a red-black tree)
    std::set<int> myset;

    // an iterater is a pointer to a node which can be advanced in order.
    std::set<int>::iterator it;

    // insert returns a pair to indicate if it was successful
    std::pair<std::set<int>::iterator, bool> ret;

    // set some initial values:
    for (int i = 1; i <= 5; ++i)
        myset.insert(i * 10); // set: 10 20 30 40 50

    //  pair<iterator,bool> insert (const value_type& val);
    ret = myset.insert(20); // no new element inserted

    if (ret.second == false)
        cout << "Can't insert " << *ret.first
             << " it already is in myset!" << endl;

    // use the pointers to the first and last element in the array as
    // iterators for
    // void insert (InputIterator first, InputIterator last);
    int myints[] = {5, 10, 15}; // 10 already in set, not inserted
    myset.insert(myints, myints + 3);

    myset.erase(40);

    std::cout << "myset contains " << myset.size() << " values:";
    for (it = myset.begin(); it != myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    cout << "\n\nMap example:\n"
         << endl;

    // Maps are associative containers that store elements formed by a
    // combination of a key value and a mapped value, following a specific order.
    // https://cplusplus.com/reference/map/map/

    map<string, double> salaries = {
        {"Michael", 10000.00},
        {"Mary", 2000000.0}};

    // insert using [] and by constructing a pair.
    salaries["Pat"] = 75000.00;
    salaries.insert(pair<string, double>("Peter", 50000.00));

    cout << salaries["Pat"] << endl;
    cout << salaries["Jan"] << endl;
    // Note: If k does not match the key of any element in the container, 
    // the function inserts a new element with that key and returns a reference 
    // to its mapped value.

    // search for Chris
    map<string, double>::iterator itr;
    itr = salaries.find("Chris");
    if (itr == salaries.end())
        cout << "Chris not found!" << endl;

    // print all keys and values note that Jan now exists!
    for (auto const &pair : salaries)
    {
        std::cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
