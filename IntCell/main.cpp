#include <iostream>
#include "IntCell.h"

using namespace std;

int main(int, char **)
{
    IntCell test = IntCell();
    cout << test.read() << endl;

    test.write(12);
    cout << test.read() << endl;

    return 0;
}
