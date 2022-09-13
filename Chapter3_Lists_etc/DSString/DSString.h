#ifndef DSSTRING_H
#define DSSTRING_H

#include "DSVector.h"

#include <iostream>


class DSString : public DSVector<char>
{

    // private:

public:
    /**
     * Constructors and big 3 call the base class
     *
     * Make sure you use proper memory management.
     **/

    // we get those from DSVector by using default in C++11
    DSString() = default;
    DSString(const DSString &) = default;
    DSString(DSString &&rhs) = default;
    ~DSString() = default;

    // we need to implement this.
    DSString(const char *);

    /**
     * Overloaded Assignment Operators
     * See: https://en.cppreference.com/w/cpp/language/operators
     */
    // these are already provided by DSVector (default in C++11)
    DSString &operator=(const DSString &) = default;
    DSString &operator=(DSString &&) = default;

    // we need to add this convert from char*
    DSString &operator=(const char *);

    /**
     * Overloaded non-modifying string concat
     */
    DSString operator+(const DSString &) const;

    /**
     * Standard relational operators.
     **/
    bool operator<(const DSString &) const;
    bool operator==(const DSString &) const;

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(size_t start, size_t numChars) const;

    /**
     * the c_str function returns a pointer a null-terminated c-string holding the
     * contents of this object. It would be smart to always have an extra `\0`
     * at the end of the string in DSString so you can just return a pointer to the
     * objects. You can make objects protected in DSVector, so
     * DSString can see it or you can realize that an iterator is actually also a
     * pointer.
     **/
    const char *c_str() const;

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument. `DSString&`
     * could be const, but then we would have to implement a const interator in
     * DSVector.
     **/
    friend std::ostream &operator<<(std::ostream &, const DSString &);

    // You are free to add more functionality to the class.  For example,
    // you may want to add a find(...) function that will search for a
    // string within a string.  (just an example)
};

#endif