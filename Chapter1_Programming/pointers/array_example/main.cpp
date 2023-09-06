#include <iostream>

int main() {

  // create an array on the stack (you can also use int a[4];)
  int a[] = {0,1,2,3};
  int* a_ptr = a;

  for (int i = 0; i < 4; ++i) {
    std::cout << "a[" << i << "] = " << a[i] << "\n";
  }

  // this is the same as a[2] or *(a+2)
  a_ptr += 2;
  std::cout << "a_ptr point to value:" << *a_ptr << "\n";

  --a_ptr;
  std::cout << "a_ptr point to value:" << *a_ptr << "\n";

  // allocate an array on the heap
  int* b = new int[4];
  *b = 1;

  for (int i = 0; i < 4; ++i) {
    std::cout << "b[" << i << "] = " << b[i] << "\n";
  }

  delete [] b;

  return 0;
}