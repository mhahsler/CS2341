#include <iostream>
#include <vector>
#include <string>
#include <cstring>

int main()
{
  
    /* STL vectors fix these issues and should be used instead
     * C++11 lets us initialize vectors like this
     */
    std::cout << "\nSTL vectors" << "\n";
    std::vector<int> squares = {1, 4, 9, 16, 25};
    std::cout << "size: " << squares.size() << "\n"
         << "capacity:" << squares.capacity() << "\n\n";

    /* Vectors know how long they are */
    int sum = 0;
    for (size_t i = 0; i < squares.size(); ++i)
    {
        sum += squares[i];
    }

    std::cout << "The sum is (for loop): " << sum << "\n";

    /* Use C++11 ranges */
    sum = 0;
    for (const auto& x : squares)
        sum += x;
    std::cout << "The sum is (ranges): " << sum << "\n";

    /* .at() is [] with boundary check */
    
    std::cout << "\n.at() checks boundaries" << "\n";
    try {
        std::cout << squares.at(100) << "\n";
    } catch (std::out_of_range &e) {
        std::cerr << "Out of range: " << e.what() << "\n";
    }

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

    if (strcmp(cstr1,cstr2))
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

    /* get a cstring copy from a STL string */
    char *cstr = new char[a.length() + 1];
    strcpy(cstr, a.c_str());
    std::cout << "As cstring: " << cstr << "\n";

    // don't forget to delete the cstring when done
    delete[] cstr;

    return 0;
}