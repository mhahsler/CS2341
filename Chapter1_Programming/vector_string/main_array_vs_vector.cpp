#include <iostream>
#include <cstring>
#include <vector>

// Note: <string> it the C++ header for the string class and
//       <cstring> is the header for functions to manipulate c-style strings and arrays. 
//       Same as <string.h> in C.


int main()
{
    std::cout << "\nC arrays" << "\n";
    int arr1[] = {0, 1, 2, 3, 4};

    for (int i = 0; i < 5; ++i)
        std::cout << arr1[i];
    std::cout << "\n";

    // needs dynamic allocation if the length needs to be decided at run time.
    // In C you will see calls to malloc() and free() instead of new and delete.
    int n = 20; // assume n was a user input not known at compile time.
    int *arr2 = new int[n];

    // copy 5x4 bytes from arr1 to arr2 defined in <cstring>
    memcpy(arr2, arr1, 5 * sizeof(*arr1));

    // now arr2 is a copy of arr1
    for (int i = 0; i < n; ++i)
        std::cout << arr2[i];
    std::cout << "\n";

    delete[] arr2;
    arr2 = nullptr; // make sure we do not use the pointer anymore!


   /* STL vectors fix these issues and should be used instead
     * C++11 lets us initialize vectors like this
     */
    std::cout << "\nSTL vectors" << "\n";
    std::vector<int> squares = {1, 4, 9, 16, 25};
    std::cout << "size: " << squares.size() << "\n\n";

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
    
    return 0;
}