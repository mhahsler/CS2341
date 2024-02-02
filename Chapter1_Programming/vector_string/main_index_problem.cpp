#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // we can allocate 2200000000 chars which takes about 2200000000/(2^30) = 2.05 GB of memory 
    vector<char> v( 2200000000 );
    v[2200000000 - 1] = 'z';

    cout << "size of v: " << v.size() << endl;

    // try to access the last element using a size_t variable
    size_t i1 = 2200000000 - 1;
    cout << "index: "  << i1 << endl;
    cout << "value: " <<  v[i1] << endl;

    // size_t is unsigned and guaranteed to be able to hold an index
    // for the larges allocatable data structure. On 64-bit machines it is
    // a unsigned long long, which is 64 bits wand goes to 2^64 = 1.8e19.   

    // THE FOLLOWING CODE IS WRONG!!!
    
    // try to access the last element using an int variable (the compiler hopefully produces a warning)
    int i2 = 2200000000 - 1;
    cout << "index: " << i2 << endl;
    
    // the following line will produce an invalid read (check valgrind) and
    // end the program with a segmentation fault
    cout << "value: " << v[i2] << endl;

    // Reason: The typical int is 4 bytes (32 bit). One bit is used for the sign 
    // so it can store values in the range from -2,147,483,648 to 2,147,483,647.

    return 0;
}