#include <iostream>
#include <set>
#include <map>

int main()
{
    std::cout << "Set example:\n";

    // Sets are containers that store unique elements following a specific order.
    // https://cplusplus.com/reference/set/set/
    // Ordering is done using less<Object> which defaults to operator<

    // sets are implemented as a balanced binary search tree (typically a red-black tree)
    std::set<int> myset;

    // an iterator is a pointer to a node which can be advanced in order.
    std::set<int>::iterator it;

    // insert returns a pair to indicate if it was successful
    std::pair<std::set<int>::iterator, bool> ret;

    // set some initial values:
    for (int i = 1; i <= 5; ++i)
        myset.insert(i * 10); // set: 10 20 30 40 50

    //  pair<iterator,bool> insert (const value_type& val);
    ret = myset.insert(20); // no new element inserted

    if (ret.second == false)
        std::cout << "Can't insert " << *ret.first
             << " it already is in myset!\n";

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

    std::cout << "\n\nMap example:\n";

    // Maps are associative containers that store elements formed by a
    // combination of a key value and a mapped value, following a specific order.
    // https://cplusplus.com/reference/map/map/

    std::map<std::string, double> salaries = {
        {"Michael", 10000.00},
        {"Mary", 2000000.0}};

    // insert using [] and by constructing a pair.
    salaries["Pat"] = 75000.00;
    salaries.insert(std::pair<std::string, double>("Peter", 50000.00));

    std::cout << "Pat: " <<  salaries["Pat"] << "\n";
    std::cout << "Jan: " << salaries["Jan"] << "\n";
    // Note: If k does not match the key of any element in the container, 
    // the function inserts a new element with that key and returns a reference 
    // to its mapped value.

    // search for Chris
    std::map<std::string, double>::iterator itr;
    itr = salaries.find("Chris");
    if (itr == salaries.end())
        std::cout << "Chris not found!" << "\n";

    // print all keys and values note that Jan now exists!
    std::cout << "All entries:\n";
    for (auto const &pair : salaries)
    {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
