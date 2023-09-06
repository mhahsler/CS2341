#include <iostream>

int main() {

  int a = 10;
  int* ptr = &a; // create a pointer to a using the address-of-operator
  int& b = a;   // create a reference for a

  std::cout << "a = " << a << "; *ptr = " << *ptr << "; b = " << b << "\n";

  b++;
  std::cout << "a = " << a << "; *ptr = " << *ptr << "; b = " << b << "\n";

  return 0;
}