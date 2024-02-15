// C++ program using the STL find algorithm
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

// Driver code
int main()
{
    // Use find to find the phone number of a person by name
    std::vector<std::string> name = {"Michael", "Sue", "Peter", "Lin"};
    std::vector<int> phone_number = {1234, 9999, 1800, 1999};

    std::string x = "Peter";

    // sorting a container (see https://cplusplus.com/reference/algorithm/search/)
    auto pos = std::find(name.begin(), name.end(), x);

    if (pos != name.end())
    {
        auto index = std::distance(name.begin(), pos);
        std::cout << "Found " << x << " at index " << index << "\n";
        std::cout << "The phone number is: " << phone_number[index] << "\n";
    }
    else
    {
        std::cout << "Not found"
                  << "\n";
    }

    return 0;
}