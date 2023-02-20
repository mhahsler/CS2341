#include <iostream>
#include <vector>
#include <list>


using namespace std;


int main()
{
    vector<int> squares = {1, 4, 9, 16, 25};

    // Using the index
    int sum = 0;
    for (size_t i = 0; i < squares.size(); ++i)
        sum += squares[i];

    // at() is [] with boundary check
    // cout << squares.at(100) << "\n";

    cout << "The sum (vector + index) is " << sum << "\n";

     // Using iterators
    sum = 0;
    for (vector<int>::iterator pos = squares.begin(); pos != squares.end(); ++pos)
        sum += *pos;   // iterators use * like pointers

    cout << "The sum (vector + iterator) is " << sum << "\n";
    // Note that pos < squares.end() does not work for iterators!


    // Use C++11 range. x is a reference to the element in squares.
    // C++ deduces data type for auto.
    sum = 0;
    for (const auto &x : squares)
        sum += x;

    cout << "The sum (vector + range) is " << sum << "\n";

    // Use a list instead of vector. 
    // Index does not work for list, but iterator and range do with the same code.
    list<int> squaresList = {1, 4, 9, 16, 25};
    
    sum = 0;
    for (auto pos = squaresList.begin(); pos != squaresList.end(); ++pos)
        sum += *pos;

    cout << "The sum (list + iterator) is " << sum << "\n";

    sum = 0;
    for (const auto &x : squaresList)
        sum += x;

    cout << "The sum (list + ranges) is " << sum << "\n";

   return 0;
}