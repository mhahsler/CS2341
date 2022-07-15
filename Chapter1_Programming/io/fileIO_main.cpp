#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line;

    ifstream file_input("../test.txt");

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

    return 0;
}

// Notes:
// endl flushes the stream (writes it) which is slow.
// ostream should convert '\n' to the OS specific standard line break.
