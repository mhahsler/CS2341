// C++ program using the STL find algorithm
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>

// Driver code
int main()
{
    // 1. Use find to find the phone number of a person by name using two vectors
    std::vector<std::string> name = {"Michael", "Sue", "Peter", "Lin"};
    std::vector<int> phone_number = {1234, 9999, 1800, 1999};

    std::string x = "Peter";
    std::string y = "Nobody";

    // searching a container (see https://cplusplus.com/reference/algorithm/search/)
    // This uses linear search with a time complexity of O(n)
    auto pos = std::find(name.begin(), name.end(), x);

    if (pos != name.end())
    {
        // we can calculate the index by getting the number of "hops" from the beginning of the container
        auto index = std::distance(name.begin(), pos);
        
        std::cout << "Found " << x << " at index " << index << "\n";
        std::cout << "The phone number is: " << phone_number[index] << "\n";
    }
    else
    {
        std::cout << x << " not found"
                  << "\n";
    }


    pos = std::find(name.begin(), name.end(), y);

    if (pos != name.end())
    {
        // we can calculate the index by getting the number of "hops" from the beginning of the container
        auto index = std::distance(name.begin(), pos);
        
        std::cout << "Found " << y << " at index " << index << "\n";
        std::cout << "The phone number is: " << phone_number[index] << "\n";
    }
    else
    {
        std::cout << y << " not found"
                  << "\n";
    }

    // 2. Using a map to store key/value pairs
    //    Here are some map examples: 
    //         https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
    std::map<std::string, int> phonebook = {
        {"Michael", 1234}, 
        {"Sue", 9999}, 
        {"Peter", 1800}, 
        {"Lin", 1999}};

    // we could use the [] operator to look up the value for a key, but if the key does not exist, 
    // then it would create an entry with the default value for the value type... So it is bette to
    // use the find method.
    // Note: maps store std::pair objects, which have a first and second member.

    // searching for keys in the map
    // This uses binary search with a time complexity of O(log n).
    auto it = phonebook.find(x);
    if (it != phonebook.end())
    {
        std::cout << "The phone number of " << it->first << " is: " << it->second << "\n";
    }
    else
    {
        std::cout << x << " not found"
                  << "\n";
    }

    it = phonebook.find(y);
    if (it != phonebook.end())
    {
        std::cout << "The phone number of " << it->first << " is: " << it->second << "\n";
    }
    else
    {
        std::cout << y << " not found"
                  << "\n";
    }

    return 0;
}