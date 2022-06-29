#include <iostream>
#include <string>
using namespace std;

/**
 * A class for simulating a memory cell.
 * 
 * It is assumed that Object has:
 *  1. a zero-parameter constructor (used in line 18)
 *  2. a copy constructor (if read is used in object contruction)
 *  3. a copy assignment operator (used in line 26)
 * 
 * for many complilers, the entire template class with the implementation has to be put into a single .h file.
 */
template <typename Object>
class MemoryCell
{
public:
    explicit MemoryCell(const Object &initialValue = Object{})
        : storedValue{initialValue} {}
    const Object &read() const
    {
        return storedValue;
    }
    void write(const Object &x)
    {
        storedValue = x;
    }

private:
    Object storedValue;
};

int main()
{
    MemoryCell<int> m1;
    MemoryCell<string> m2{"hello"};

    m1.write(37);
    m2.write(m2.read() + " world");
    cout << m1.read() << endl
         << m2.read() << endl;

    return 0;
}