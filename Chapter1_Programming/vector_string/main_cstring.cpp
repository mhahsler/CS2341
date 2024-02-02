#include <iostream>
#include <cstring>

// Note: <string> it the C++ header for the string class and
//       <cstring> is the header for functions to manipulate c-style strings. Same as <string.h> in C.


int main()
{
    // Array vs STL vector
    std::cout <<"arrays" << "\n";

    int arr1[] = {0, 1, 2, 3, 4};

    for (int i = 0; i < 5; ++i)
        std::cout << arr1[i];
    std::cout << "\n";

    // needs dynamic allocation if the length needs to be decided at run time.
    // In C you will see calls to malloc() and free() instead of new and delete.
    int n = 20; // assume n was a user input not known at compile time.
    int *arr2 = new int[n];

    // copy arr1 to arr2 defined in <cstring>
    memcpy(arr2, arr1, 5 * sizeof(*arr1));

    for (int i = 0; i < n; ++i)
        std::cout << arr2[i];
    std::cout << "\n";

    delete[] arr2;
    arr2 = nullptr; // make sure we do not use the pointer anymore!

    return 0;
}