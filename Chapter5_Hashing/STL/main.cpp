#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    const int hashSize = 11;
    srand(time(0));

    // Example: Hash ints using % (mod)

    // Generate a vector with random numbers
    vector<int> ints(10, 0);
    generate(ints.begin(), ints.end(), rand);

    // Calculate mod hash
    for (const auto &d : ints)
        cout << "h(" << d << ") = " << d % hashSize << endl;

    // Example: Hash strings using STL's hash class
    vector<string> strings = {"Michael", "Sam", "Peter", "Lara", "Mike", "Ian", "Lin",
                              "Sue", "Erica"};

    hash<string> str_hasher = hash<string>{};

    for (const auto &d : strings)
        cout << "h(\"" << d << "\") = " << str_hasher(d)
             << " mod 11 = " << str_hasher(d) % 11 << endl;

    // Example: Store strings in a Hash using STL's unordered set
    std::unordered_set<std::string> employees;

    cout << "Bucket count: " << employees.bucket_count() << endl;
    cout << "Size: " << employees.size() << endl;
    cout << "Load factor: " << employees.load_factor() << endl;

    for (const auto &d : strings)
        employees.insert(d);

    // The data structure automatically changes the bucket count and rehashes
    // when the load factor gets too high.
    // (see https://cplusplus.com/reference/unordered_set/unordered_set/rehash/)
    
    cout << "Bucket count: " << employees.bucket_count() << endl;
    cout << "Size: " << employees.size() << endl;
    cout << "Load factor: " << employees.load_factor() << endl;

    cout << boolalpha;
    cout << "Do we have \"Peter\"? " << (employees.find("Peter") != employees.end()) << endl;


    // Example: Use STL's unordered map which stores <key, value> tuples (std::pair)
    std::unordered_map<std::string, std::string> colors = {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FF"}};

    // add more colors and remove GREEN
    colors["BLACK"] = "#000000";
    colors["WHITE"] = "#FFFFFF";
    colors.erase("GREEN");

    for (const auto &d : colors)
        cout << d.first << ": " << d.second << endl;

    cout << "We have " << colors.size() << " colors!" << endl;

    cout << boolalpha;
    cout << "Do we have a code for color GREEN? " << (colors.find("GREEN") != colors.end()) << endl;
    cout << "Do we have a code for color BLUE? " << (colors.find("BLUE") != colors.end()) << endl;
    cout << "Code for color BLUE is " << colors["BLUE"] << endl;

    return 0;
}
