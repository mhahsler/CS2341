#include <iostream>
#include <vector>
#include <string>
#include <cstring>

// Note: <string> it the C++ header for the string class and
//       <cstring> is the header for functions to manipulate c-style strings. Same as <string.h> in C.

using namespace std;

int main()
{
    // Array vs STL vector
    cout <<"arrays" << "\n";

    int arr1[] = {0, 1, 2, 3, 4};

    for (int i = 0; i < 5; ++i)
        cout << arr1[i];
    cout << "\n";

    // needs dynamic allocation if the length needs to be decided at run time.
    // In C you will see calls to malloc() and free() instead of new and delete.
    int n = 20; // assume n was a user input not known at compile time.
    int *arr2 = new int[n];

    // copy arr1 to arr2 defined in <cstring>
    memcpy(arr2, arr1, 5 * sizeof(*arr1));

    for (int i = 0; i < n; ++i)
        cout << arr2[i];
    cout << "\n";

    delete[] arr2;
    arr2 = NULL; // make sure we do not use the pointer anymore!

    /* STL vectors fix these issues and should be used instead
     * C++11 lets us initialize vectors like this
     */
    cout << "\nSTL vectors" << "\n";
    vector<int> squares = {1, 4, 9, 16, 25};
    cout << "size: " << squares.size() << "\n"
         << "capacity:" << squares.capacity() << "\n\n";

    /* Vectors know how long they are */
    int sum = 0;
    for (size_t i = 0; i < squares.size(); ++i)
    {
        sum += squares[i];
    }

    cout << "The sum is (for loop): " << sum << "\n";

    /* Use C++11 ranges */
    sum = 0;
    for (auto x : squares)
        sum += x;
    cout << "The sum is (ranges): " << sum << "\n";

    /* .at() is [] with boundary check */
    
    cout << "\n.at() checks boundaries" << "\n";
    try {
        cout << squares.at(100) << "\n";
    } catch (out_of_range &e) {
        cout << "Out of range: " << e.what() << endl;
    }

    // cstring vs. STL string
    cout << "\ncstrings" << "\n";

    /* cstrings are character arrays terminated with `\0`.
     * #include <string.h>
     * provides many useful functions (see: https://cplusplus.com/reference/cstring/)
     */
    char cstr1[10];

    char cstr2[] = "Hello!";

    strcpy(cstr1, cstr2);

    // == does not work! It compares pointers
    if (cstr1 == cstr2)
        cout << cstr1 << " == " << cstr2 << "\n";
    else
        cout << cstr1 << " != " << cstr2 << "\n";

    if (strcmp(cstr1,cstr2))
        cout << "strcmp: " <<  cstr1 << " == " << cstr2 << "\n";
    else
        cout << "strcmp: " << cstr1 << " != " << cstr2 << "\n";

  
    /* Use STL strings and the world is good! */
    cout << "\nSTL strings" << "\n";
    string a = "Michael", b = "Michae";

    cout << "a.size(): " <<  a.size() << "\n";

    if (a == b)
        cout << a << " == " << b << "\n";
    else
        cout << a << " != " << b << "\n";

    b += "l";
    if (a == b)
        cout << a << " == " << b << "\n";
    else
        cout << a << " != " << b << "\n";

    /* get a cstring copy from a STL string */
    char *cstr = new char[a.length() + 1];
    strcpy(cstr, a.c_str());
    cout << "As cstring: " << cstr << endl;

    return 0;
}