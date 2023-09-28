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
    
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <filename> [<more arguments>]\n";
        return 1;
    }
    
    cout << "You have entered " << argc
         << " command line arguments:" << "\n";
  
    for (int i = 0; i < argc; ++i)
        cout << "argv[" << i << "]: " << argv[i] << "\n";

    return 0;
}

/* open the terminal, go to the build directory and try:
 cd build
 ./CLInterface
 ./CLInterface test.txt b c=d e = f "g = h"
 ./CLInterface *
 ./CLInterface *.cmake
 */