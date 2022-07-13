#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    const int hashSize = 11;
    srand(time(0));

    // Hash ints

    // Generate a vector with random numbers
    vector<int> ints(10, 0);
    generate(ints.begin(), ints.end(), rand);

    // Calculate mod hash
    for (const auto &d : ints)
        cout << "h(" << d << ") = " << d % hashSize << endl;

    // Hash strings

    vector<string> strings = {"Michael", "Sam", "Peter", "Lara", "Mike"};

    hash<string> str_hasher = hash<string>{};

    for (const auto &d : strings)
        cout << "h(\"" << d << "\") = " << str_hasher(d)
             << " mod 11 = " << str_hasher(d) % 11 << endl;

    // Use an unordered map

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

    cout << "Do we have a code for color GREEN? " << (colors.find("GREEN") != colors.end()) << endl;
    cout << "Do we have a code for color BLUE? " << (colors.find("BLUE") != colors.end()) << endl;
    cout << "Code for color BLUE is " << colors["BLUE"] << endl;

    return 0;
}