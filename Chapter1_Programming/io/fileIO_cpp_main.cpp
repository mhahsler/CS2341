#include <iostream>
#include <fstream>

// requires C++17
#include <filesystem>

using namespace std;

int main()
{

    // Example 1: read a single file using fstream
    ifstream file_input("./test.txt");

    // line buffer
    string line;

    // It gets very confusing with functions if you mix cstrings and C++ STL strings!!!
    // I suggest that you stick with C++ std::getline to read line-by-line
    // here is a tutorial: https://cplusplus.com/doc/tutorial/files/
    // see https://en.cppreference.com/w/cpp/string/basic_string/getline

    if (!file_input.is_open())
    {
        cout << "Unable not open file!" << endl;
        return (-1);
    }

    while (getline(file_input, line))
        cout << "I read: " << line << "\n";

    cout << endl;

    file_input.close();

    // Notes:
    // endl flushes the stream (writes it) which is slow.
    // ostream should convert '\n' to the OS specific standard line break.


    // Example 2: list all files using a directory_iterator

    cout << "\n\nThe current directory contains:"
         << "\n";
    string path = ".";
    for (const auto &entry : std::filesystem::directory_iterator(path))
        cout << entry.path() << "\n";

    cout << endl;

    return 0;
}
