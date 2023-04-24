#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

int main()
{
    std::cout << std::boolalpha;
    std::vector<std::string> strings = {"Michael", "Sam", "Peter", "Lara", "Mike", "Ian", "Lin",
                              "Sue", "Erica"};

    std::cout << "Hash strings using STL's hash class and then calculate mod 7 as an example." << "\n";
    auto str_hasher = std::hash<std::string>{};

    for (const auto &d : strings)
        std::cout << "h(\"" << d << "\") = " << str_hasher(d)
             << " mod 7 = " << str_hasher(d) % 7 << "\n";
    

    std::cout << "\nCreate an empty unordered set. This automatically uses the STL hash function for primitive and STL data types." << "\n";
    std::unordered_set<std::string> employees;

    std::cout << "Bucket count (M): " << employees.bucket_count() << "\n";
    std::cout << "Size (N): " << employees.size() << "\n";
    std::cout << "Load factor (lambda): " << employees.load_factor() << "\n";

    std::cout << "\nAdd the strings to the set. The set rehashes if the load factor gets too high." << "\n";
    for (const auto &d : strings)
        employees.insert(d);

    std::cout << "Bucket count: " << employees.bucket_count() << "\n";
    std::cout << "Size: " << employees.size() << "\n";
    std::cout << "Load factor: " << employees.load_factor() << "\n";
    
    std::cout << "\nDo we have \"Peter\"? " << (employees.find("Peter") != employees.end()) << "\n";


    std::cout << "\n\nUse STL's unordered map which stores <key, value> tuples (std::pair)." << "\n";
    std::unordered_map<std::string, std::string> colors = {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FF"}};

    // add more colors and remove GREEN
    colors["BLACK"] = "#000000";
    colors["WHITE"] = "#FFFFFF";
    colors.erase("GREEN");

    for (const auto &d : colors)
        std::cout << d.first << ": " << d.second << "\n";

    std::cout << "We have " << colors.size() << " colors!" << "\n";

    std::cout << "Do we have a code for color GREEN? " << (colors.find("GREEN") != colors.end()) << "\n";
    std::cout << "Do we have a code for color BLUE? " << (colors.find("BLUE") != colors.end()) << "\n";
    std::cout << "Code for color BLUE is " << colors["BLUE"] << "\n";

    return 0;
}
