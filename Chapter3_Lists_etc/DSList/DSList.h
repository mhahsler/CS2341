#ifndef DSList_H
#define DSList_H

/**
 * @brief Singly-linked list that uses position 
 *
 * 1. Use a position index to refer to an element. This is simpler to 
 *    implement compared to iterators (see iterator version), but does not
 *    play as nicely with the STL.
 * 2. You can use a sentinel node (a node without data that represents the 
 *    beginning of the list) to avoid special cases for inserting and deleting 
 *    the first element.
 * 
 * @tparam Object 
 */
template <typename Object>
class DSList
{
private:
   /**
     * @brief The Node data structure
     * 
     * struct is a class with all public members
     */
    struct Node
    {
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {};
    };

public:

// You need to implement:
// Default construction
// Copy constructor
// Destructor
// size
// empty?
// clear
// insert in front (push_front).
// insert at a specified position.
// get the value at a specified position.
// remove the element in front (pop_front)
// remove using position.
// find an element with a specific value (and return the position. First element in list is pos 0).
// remove an element with a specific value (find and remove)

private:
    Node *head;
};

#endif
