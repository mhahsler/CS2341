#include <iostream>
#include <vector>
#include <string>
#include <strings.h>
using namespace std;

// Code from Figure 1.25

// Generic findMax, with a function object, C++ style.
// Precondition: a.size( ) > 0.
//
// typename Comparable suggests that it also has
// * operator< for a total order
//
// typename Comparator is used as a placeholder for a comparator 
//   function object. To make this clear we use the name isLessThan
	    

template <typename Comparable, typename Comparator>
const Comparable &findMax(const vector<Comparable> &arr, Comparator isLessThan)
{
    int maxIndex = 0;

    for (int i = 1; i < arr.size(); ++i)
        if (isLessThan(arr[maxIndex], arr[i]))
            maxIndex = i;

    return arr[maxIndex];
}

// function object calls automatically operator() (this is called function call operator)
// strcasecmp is a c-string function: 
// https://pubs.opengroup.org/onlinepubs/009696799/functions/strcasecmp.html
class CaseInsensitiveCompare
{
public:
    bool operator()(const string &lhs, const string &rhs) const
    {
        return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};


int main()
{
    vector<string> arr = {"ZEBRA", "alligator", "crocodile"};

    cout << "case insensitive: " << findMax(arr, CaseInsensitiveCompare{}) << endl;
    
    // default ordering for string is case sensitive.
    // std::less provides a templated comparator function that invokes operator<.
    // Also works for primitive datatypes.
    // See: https://en.cppreference.com/w/cpp/utility/functional/less
    cout << "default string comparator: " <<  findMax(arr, less<string>{}) << endl;

    return 0;
}
