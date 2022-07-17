#include <iostream>
#include <vector>

using namespace std;


// run this with the debugger!
// You can put `&variable` into WATCH to see where in memory it is

int* create_array(int size) 
{
    // allocated on the stack; size of arrays needs to be known at compile time
    int a = 5;
    int b[] = {9, 8, 7};
    
    // dynamic allocation happens on the heap
    int* c = new int[size];
    for (size_t i = 0; i < size; ++i)
        c[i] = i + 1;

    //return b; // why does this not work? 
    return c;
}

int& change(int* a, size_t pos) 
{
    return a[pos];
}

vector<int> create_vector(size_t size)
{
    vector<int> tmp = vector<int>(size);

    for (size_t i = 0; i < size; ++i)
        tmp[i] = i + 1;

    return tmp;
}


int main() 
{
    size_t s = 3;

    // Example: Creating and returning an array
    int* d = create_array(s); 
    for (size_t i = 0; i < s; ++i)
        cout << d[i] << " ";
    cout << endl;

    // why does this work?
    change(d, 0) = 99;

    for (size_t i = 0; i < s; ++i)
        cout << d[i] << " ";
    cout << endl;

    // dynamically allocated memory needs to be released.
    delete [] d;

    // Example using STL vector. dynamic memory allocation is handled by
    // the container and in C++11 the temporay container in the function is 
    // returned using move semantics (move constructor).
    vector<int> e = create_vector(s);
    for (const auto &v : e)
        cout << v << " ";
    cout << endl;

    // this calls the copy constructor
    vector<int> copyOfe = e;

    return 0;
}
