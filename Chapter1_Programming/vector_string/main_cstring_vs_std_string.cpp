#include <iostream>
#include <vector>
#include <string>
#include <cstring>

int main()
{

    // cstring vs. STL string
    std::cout << "\ncstrings" << "\n";

    /* cstrings are character arrays terminated with `\0`.
     * #include <string.h>
     * provides many useful functions (see: https://cplusplus.com/reference/cstring/)
     */
    char cstr1[10];

    char cstr2[] = "Hello!";

    strcpy(cstr1, cstr2);

    // == does not work! It compares pointers
    if (cstr1 == cstr2)
        std::cout << cstr1 << " == " << cstr2 << "\n";
    else
        std::cout << cstr1 << " != " << cstr2 << "\n";

    if (strcmp(cstr1, cstr2) == 0)
        std::cout << "strcmp: " <<  cstr1 << " == " << cstr2 << "\n";
    else
        std::cout << "strcmp: " << cstr1 << " != " << cstr2 << "\n";

  
    /* Use STL strings and the world is good! */
    std::cout << "\nSTL strings" << "\n";
    std::string a = "Michael", b = "Michae";

    std::cout << "a.size(): " <<  a.size() << "\n";

    if (a == b)
        std::cout << a << " == " << b << "\n";
    else
        std::cout << a << " != " << b << "\n";

    b += "l";
    if (a == b)
        std::cout << a << " == " << b << "\n";
    else
        std::cout << a << " != " << b << "\n";

    /* c_str() returns a const pointer to the cstring inside 
     * the std::string object. To get a new (non-const) cstring, we need 
     * to copy the STL string */
    char *cstr = new char[a.length() + 1];
    strcpy(cstr, a.c_str());
    std::cout << "As cstring: " << cstr << "\n";

    // don't forget to delete the cstring when done
    delete[] cstr;
    cstr = nullptr;

    return 0;
}