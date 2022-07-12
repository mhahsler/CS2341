#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief returns the average of and b
 *
 * This is call-by-value. a and b are copied!
 *
 * @param a
 * @param b
 * @return double
 */
double average(double a, double b)
{
    a = a + b / 2;
    return a;
}

/**
 * @brief exchanges a and b
 *
 * This is call-by-reference: Changes to a and b in the function change the data in the calling function.
 *
 * Notes: 
 *   * There is std::swap() already available (https://en.cppreference.com/w/cpp/algorithm/swap)!
 *   * in C++11 std::move() can be used to move rvalues instead of copying the objects.
 *     Note: lvalues are permanent storage (e.g., variables) and rvalues are temorary objects (e.g., the 
 *           result of an evaluation). Typical assignment: lval = rval;
 *  * STL containers (vector, string) use move automatically.
 * 
 * @param a
 * @param b
 */
void swap(double &a, double &b)
{
    double tmp = a;
    a = b;
    b = tmp;
}

/**
 * @brief return a random element
 * 
 * Pass-by-constant reference (lvalue): reference is used to avoid copying and cont makes sure the funciton does 
 *   not mess up the data in the calling function. An assignment to arr would lead to a compilation error.
 * 
 * @param arr 
 * @return string 
 */
const string & randomItem(const vector<string> &arr)
{
    return arr[rand() % arr.size()];
}

int main()
{

    double a = 1, b = 2;
    cout << "a = " << a << "; b = " << b << endl;

    cout << "average(a, b) - pass-by-value: " << average(a, b) << endl;

    cout << "swap(a, b) - pass-by-reference: " << endl;
    swap(a, b);
    cout << "Back in main: a = " << a << "; b = " << b << endl;

    cout << "Pick a random string: ";
    srand(time(NULL)); // we need to initialize the random number generator
    vector<string> words = {"Hello", "World", "how", "are", "you"};
    
    const string & s = randomItem(words);
    //const string s = randomItem(words); // would make a copy
    cout << s << endl;

    return 0;
}