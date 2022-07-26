#include <iostream>
#include <fstream>

// requires C++17
#include <filesystem>

using namespace std;

int main()
{
    // read a single file using fstream
    string line;

    ifstream file_input("./test.txt");

    // https://cplusplus.com/doc/tutorial/files/
    // It gets very confusing with functions for cstrings and C++ STL strings

    if (file_input.is_open())
    {

        while (getline(file_input, line))
        {
            cout << line << "\n";
        }

        file_input.close();
    }
    else
        cout << "Unable not open file!" << endl;


    // list all files 

    cout << "\n\nThe current directory contains:" << "\n";
    string path = ".";
    for (const auto & entry : std::filesystem::directory_iterator(path))
        cout << entry.path() << "\n";

    return 0;
}

// Notes:
// endl flushes the stream (writes it) which is slow.
// ostream should convert '\n' to the OS specific standard line break.
