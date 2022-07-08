#ifndef DSDLList_H
#define DSDLList_H

template <typename T>
class DSDLListNode
{
private:
    T element;
    DSDLListNode *next;
    DSDLListNode *prev;
    friend class DSDLList;
};

template <typename T>
class DSDLList
{
private:
    DSDLListNode *front;
    DSDLListNode *back;
};

#endif