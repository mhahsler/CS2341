#include "DSString.h"
#include <string.h>
#include <stdexcept>

DSString::DSString(const char *x)
{
    // handling of x == nullptr is missing
    size_t size = strlen(x);
    resize(size);

    for (size_t i = 0; i < size; ++i)
    {
        (*this)[i] = x[i];
    }
}

DSString &DSString::operator=(const char *rhs)
{
    // handling of x == nullptr is missing
    size_t size = strlen(rhs);
    resize(size);

    for (size_t i = 0; i < size; ++i)
    {
        (*this)[i] = rhs[i];
    }

    return *this;
}

DSString DSString::operator+(const DSString &rhs) const
{
    DSString tmp( size() + rhs.size() );

    for (size_t i = 0; i < size(); ++i)
        tmp[i] = (*this)[i];

    for (size_t i = 0; i < rhs.size(); ++i)
        tmp[size() + i] = rhs[i];
    

    return tmp;
}

/**
 * Standard relational operators.
 **/
bool DSString::operator==(const DSString &rhs) const
{
#ifdef DEBUG    
    cerr << "(calling: " << *this << " == " << rhs << ") ";
#endif

    if (size() != rhs.size())
        return false;

    for (size_t i = 0; i < size(); ++i)
        if ((*this)[i] != rhs[i])
            return false;

    return true;
}

bool DSString::operator<(const DSString &rhs) const
{
#ifdef DEBUG    
    cerr << "(calling: " << *this << " < " << rhs << ") " << endl;
#endif

    size_t compSize = min(size(), rhs.size());
    for (size_t i = 0; i < compSize; ++i)
    {
        if ((*this)[i] < rhs[i])
            return true;
        if ((*this)[i] > rhs[i])
            return false;
    }

    // all were the same so far. We define the shorter string as <
    if (size() < rhs.size())
        return true;

    return false;
}

/**
 * The substring method returns a string object that contains a
 * sequence of characters from this string object.
 *
 * param start - the index of where to start
 * param numChars - the number (count) of characters to copy into
 *    the substring
 * @return a DSString object containing the requested substring
 **/
DSString DSString::substring(size_t start, size_t numChars) const
{
    if (start + numChars > size())
        throw std::runtime_error("out of bounds!");

    DSString tmp;
    tmp.resize(numChars);

    for (size_t i = 0; i < numChars; ++i)
    {
        tmp[i] = (*this)[start + i];
    }
    return tmp;
}

/**
 * This function adds `\0` and then returns a const pointer to the array
 */
const char *DSString::c_str()
{
    resize( size() + 1 );
    (*this)[ size() - 1 ] = '\0';
    
    return objects;
}

/**
 * Unfortunately, this does not work for a const DSString!!!
 */
const char *DSString::c_str() const
{
    cerr << "Cannot return a cstring from a const DSString!" << endl; 
    return nullptr;
}

/**
 * Overloaded stream insertion operator to print the contents of this
 * string to the output stream in the first argument. Note: this is 
 * not a member function, but a friend outside the class namespace.
 **/
std::ostream &operator<<(std::ostream &out, const DSString &x)
{
    for (const auto &c : x)
        out << c;

    return out;
}
