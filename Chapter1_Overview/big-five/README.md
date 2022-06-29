The big-five are:

 * 1. Destructor
 * 2/3. Constructor (copy and move)
 * 4/5. operator= (copy and move)
 
Typically the default provided by C++ works.

**Exception:** If a member variable contains a pointer (i.e., we use dynamic memory allocation with new/delete)

General info on operator overloading: https://en.cppreference.com/w/cpp/language/operators
