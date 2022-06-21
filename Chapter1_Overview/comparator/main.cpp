#include <iostream>
#include <vector>
#include <string>
#include <strings.h>
using namespace std;

// Code from Figure 1.25

// Generic findMax, with a function object, C++ style.
// Precondition: a.size( ) > 0.
template <typename Object, typename Comparator>
const Object &findMax(const vector<Object> &arr, Comparator isLessThan)
{
    int maxIndex = 0;

    for (int i = 1; i < arr.size(); ++i)
        if (isLessThan(arr[maxIndex], arr[i]))
            maxIndex = i;

    return arr[maxIndex];
}

// function object calls automatically operator() (this is called function call operator)
// strcasecmp is a c-string function: https://pubs.opengroup.org/onlinepubs/009696799/functions/strcasecmp.html
class CaseInsensitiveCompare
{
public:
    bool operator()(const string &lhs, const string &rhs) const
    {
        return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

// Generic findMax, using default ordering. 
// std::less provides a templated comparator function also for build-in datatypes which do not have a operator<()
// See: https://en.cppreference.com/w/cpp/utility/functional/less
#include <functional>
template <typename Object>
const Object &findMax(const vector<Object> &arr)
{
    return findMax(arr, less<Object>{});
}



int main()
{
    vector<string> arr = {"ZEBRA", "alligator", "crocodile"};

    cout << findMax(arr, CaseInsensitiveCompare{}) << endl;
    
    // default ordering is case sensitive.
    cout << findMax(arr) << endl;

    return 0;
}
