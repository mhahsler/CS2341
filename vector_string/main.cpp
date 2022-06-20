#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**
 * @brief Use STD library vectors and string! 
 * 
 * @return int 
 */
int main()
{

    /* C+11 lets us initialize vectors like this */
    vector<int> squares = {1, 4, 9, 16, 25};

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
    {
        sum += x;
    }

    cout << "The sum is " << sum << endl;

    /* strings */
    string a = "Michael", b = "Michae";

    if (a == b)
        cout << a << " == " << b << endl;

    b += "l";
    if (a == b)
        cout << a << " == " << b << endl;
}