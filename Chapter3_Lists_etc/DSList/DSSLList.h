#ifndef DSDLList_H
#define DSDLList_H

template <typename T>
class DSSLListNode
{
private:
    T element;
    DSSLListNode *next;
    friend class DSSLList;
};

template <typename T>
class DSSLList
{
public:

// We need:
// Default construction
// Copy contructor
// Destructor
// size
// empty?
// clear
// insert in a given position
// remove an element with a specific value
// find an element with a specific value

private:
    DSSLListNode *front;
};

#endif