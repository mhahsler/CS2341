#include <iostream>
#include <vector>
#include <string>
#include <string.h>

// Note: <string> it the C++ header for the string class and
//       <string.h> is the header for functions to manipulate c-style strings

using namespace std;

int main()
{
    // Array vs STL vector

    /* C-style arrays are just pointers to memory (first element of the array).
     * C-style arrays have several drawbacks:
     * 1. Arrays cannot be assigned with = (they are pointers)
     * 2. Arrays do not know its length.
     * 3. Arrays cannot be dynamically enlarged.
     */

    int arr1[] = {0, 1, 2, 3, 4};

    for (int i = 0; i < 5; ++i)
        cout << arr1[i];
    cout << endl;

    // needs dynamic allocation if the length needs to be decided at run time.
    // In C you will see calls to malloc() and free() instead of new and delete.
    int n = 20;
    int *arr2 = new int[n];

    memcpy(arr2, arr1, 5 * sizeof(*arr1));

    for (int i = 0; i < n; ++i)
        cout << arr2[i];
    cout << endl;

    delete[] arr2;
    arr2 = NULL; // make sure we do not use the pointer anymore!

    /* STL vectors fix the issues and should be used instead
     * C++11 lets us initialize vectors like this
     */
    vector<int> squares = {1, 4, 9, 16, 25};
    cout << "size: " << squares.size() << "\n"
         << "capacity:" << squares.capacity() << "\n\n";

    /* Vectors know how long they are and check boundaries */
    int sum = 0;
    for (int i = 0; i < squares.size(); ++i)
    {
        sum += squares[i];
    }

    /* at() is [] with boundary check */
    // cout << squares.at(100) << endl;

    cout << "The sum is " << sum << endl;

    /* Use C++11 ranges */
    sum = 0;
    for (auto x : squares)
        sum += x;
    cout << "The sum is " << sum << endl;

    // cstring vs. STL string

    /* cstrings are character arrays terminated with `\0`.
     * #include <string.h>
     * provides many useful functions (see: https://cplusplus.com/reference/cstring/)
     */
    char cstr1[10];

    char cstr2[] = "Hello!";

    strcpy(cstr1, cstr2);

    if (cstr1 == cstr2)
        cout << cstr1 << " == " << cstr2 << endl;
    else
        cout << cstr1 << " != " << cstr2 << endl;

    /* STL strings */
    string a = "Michael", b = "Michae";

    if (a == b)
        cout << a << " == " << b << endl;
    else
        cout << a << " != " << b << endl;

    b += "l";
    if (a == b)
        cout << a << " == " << b << endl;
    else
        cout << a << " != " << b << endl;

    /* get a cstring copy from a STL string */
    char *cstr = new char[a.length() + 1];
    strcpy(cstr, a.c_str());
    cout << "As cstring: " << cstr << endl;

    return 0;
}