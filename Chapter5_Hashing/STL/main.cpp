#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    cout << "Hash strings using STL's hash class" << endl;
    vector<string> strings = {"Michael", "Sam", "Peter", "Lara", "Mike", "Ian", "Lin",
                              "Sue", "Erica"};

    hash<string> str_hasher = hash<string>{};

    for (const auto &d : strings)
        cout << "h(\"" << d << "\") = " << str_hasher(d)
             << " mod 11 = " << str_hasher(d) % 11 << endl;
    
    cout << "\nCreate an empty unordered set." << endl;

    std::unordered_set<std::string> employees;

    cout << "Bucket count: " << employees.bucket_count() << endl;
    cout << "Size: " << employees.size() << endl;
    cout << "Load factor: " << employees.load_factor() << endl;

    cout << "\nAdd the strings to the set. The set rehashes if the load factor gets too high." << endl;
    for (const auto &d : strings)
        employees.insert(d);

    cout << "Bucket count: " << employees.bucket_count() << endl;
    cout << "Size: " << employees.size() << endl;
    cout << "Load factor: " << employees.load_factor() << endl;
    
    cout << boolalpha;
    cout << "\nDo we have \"Peter\"? " << (employees.find("Peter") != employees.end()) << endl;


    cout << "\n\nUse STL's unordered map which stores <key, value> tuples (std::pair)." << endl;
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
