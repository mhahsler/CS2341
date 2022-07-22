#include <iostream>

using namespace std;

/**
 * @brief 
 * 
 * @param argc (ARGument Count) is int and stores number of command-line arguments passed by the 
 *   user including the name of the program.
 * @param argv (ARGument Vector) is array of character pointers listing all the arguments (as cstrings). 
 *   Remember: An array is a pointer to the first element.
 * @return int status of the program. 0 means success.
 */
int main(int argc, char** argv) {
    cout << "You have entered " << argc
         << " arguments:" << "\n";
  
    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    return 0;
}

// open the terminal, go to the build directory and try:
// ./CLInterface a b c=d e = f "g = h"
// ./CLInterface *
// ./CLInterface *.cmake
