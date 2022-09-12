#include <iostream>
#include <vector>
#include <list>


using namespace std;


int main()
{
    vector<int> squares = {1, 4, 9, 16, 25};

    // Using the index
    int sum = 0;
    for (int i = 0; i < squares.size(); ++i)
        sum += squares[i];

    // at() is [] with boundary check
    // cout << squares.at(100) << endl;

    cout << "The sum (index) is " << sum << endl;

     // Using iterators
    sum = 0;
    for (vector<int>::iterator pos = squares.begin(); pos != squares.end(); ++pos)
        sum += *pos;

    cout << "The sum (iterator) is " << sum << endl;
    // Note that pos < squares.end() does not work!


    // Use C++11 ranges. x is a reference to the element in squares.
    sum = 0;
    for (const auto &x : squares)
        sum += x;

    cout << "The sum (ranges) is " << sum << endl;

    // list instead of vector
    list<int> squaresList = {1, 4, 9, 16, 25};
    
    sum = 0;
    for (auto pos = squaresList.begin(); pos != squaresList.end(); ++pos)
        sum += *pos;

    cout << "The sum (list + iterator) is " << sum << endl;
    // C++ deduces data type for auto.


    // C++11 ranges also work, but index does not!
     sum = 0;
    for (const auto &x : squaresList)
        sum += x;

    cout << "The sum (list + ranges) is " << sum << endl;

   return 0;
}