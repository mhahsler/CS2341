#ifndef DSITERATORLIST_H
#define DSiTERATORLIST_H

#include <stdexcept>

/**
 * @brief Singly-linked list using iterators.
 *
 * Partial implementation
 *
 * @tparam Object
 */
template <typename Object>
class DSIteratorList
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

    Node *head;

public:
    /**
     * @brief Public nested iterator class for const objects
     *
     * Iterators need
     * * Constructor
     * * Dereferencing operator* to access the data
     * * ++x and x++ to increment (bidirectional iterators also need --x and x--)
     * * comparison operator== and operator!=
     *
     * A const iterator is used for const objects and does not allow the code to
     * change the data. Getting const right is very tricky!
     *
     * Here we use a pointer to the current node as the iterator.
     */
    class const_iterator
    {
    protected:
        Node *current;

    public:
        /**
         * @brief Construct a new const iterator object
         */
        const_iterator()
            : current{nullptr} {}

        /**
         * @brief Construct a new const iterator object from a Node pointer (used internally)
         */
        const_iterator(Node *p)
            : current{p} {}

        /**
         * @brief Dereferencing operator
         */
        const Object &operator*() const
        {
            return current->data;
        }

        /**
         * @brief Increment (prefix) - Move to the next element and return an iterator for that element.
         */
        const_iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        /**
         * @brief Increment (postfix) - Return an iterator to the current element and move to the next element.
         */
        const_iterator operator++(int)
        {
            const_iterator old = current;
            current = current->next;
            return old;
        }

        /**
         * @brief Equal-to operator - Do the iterators reference the same element?
         */
        bool operator==(const const_iterator &rhs) const
        {
            return current == rhs.current;
        }

        /**
         * @brief Not-equal-to operator - Based on operator==
         */
        bool operator!=(const const_iterator &rhs) const
        {
            // it is common to derive != from operator==
            return !(*this == rhs);
        }
    };

    /**
     * @brief Public nested iterator class for non-const objects
     *
     * This is a const_iterator plus some non-const additions. We use inheritance.
     * So that iterator can access the current pointer, it is declared protected.
     * We still have to fully specify it with const_iterator::current.
     *
     * The non-const additions can only be used for non-const objects and the dereferencing
     * operator allows the code to change the data.
     */
    class iterator : public const_iterator
    {

    public:
        /**
         * @brief Construct a new const iterator object
         */
        iterator() : const_iterator() {}

        /**
         * @brief Construct a new iterator object from a Node
         */
        iterator(Node *p) : const_iterator(p) {}

        /**
         * @brief Non-const dereferencing operator
         */
        Object &operator*()
        {
            return const_iterator::current->data;
        }

        /**
         * @brief Non-const Increment (prefix)
         */
        iterator &operator++()
        {
            const_iterator::current = const_iterator::current->next;
            return *this;
        }

        /**
         * @brief Non-const Increment (postfix)
         */
        iterator operator++(int)
        {
            iterator old = const_iterator::current;
            const_iterator::current = const_iterator::current->next;
            return old;
        }

        // So remove can access the current pointer
        friend void DSIteratorList<Object>::remove(iterator &it);

        // equal and non-equal is inherited.
    };

    /**
     * @brief Default constructor
     */
    DSIteratorList<Object>()
        : head{nullptr} {}

    /**
     * @brief Rule-of-Three 1: Copy constructor
     * 
     * This is easier in a doubly linked list.
     */
    DSIteratorList<Object>(const DSIteratorList<Object> &rhs)
        : head{nullptr}
    {
        Node **prev_next = &head;

        for (const Object &v : rhs)
        {
            *prev_next = new Node{v, nullptr};
            prev_next = &((*prev_next)->next);
        }
    }

    /**
     * @brief Rule-of-Three 2: Destructor
     */
    ~DSIteratorList()
    {
        clear();
    }

    /**
     * @brief Rule-of-Three 3: Copy assignment operator
     * 
     * Copy constructor and swap is the standard implementation.
     */
    DSIteratorList<Object> &operator=(const DSIteratorList<Object> &rhs)
    {
        DSIteratorList<Object> copy{rhs}; // call copy constructor
        std::swap(*this, copy);           // make this the copy
        return *this;                     // copy gets destroyed
    }

    /**
     * @brief Returns an iterator to the first element
     */
    iterator begin() const
    {
        return iterator{head};
    }

    /**
     * @brief Returns an iterator to the past-the-end element
     */
    iterator end() const
    {
        return iterator{nullptr};
    }

    /**
     * @brief Number of elements
     */
    size_t size() const
    {
        size_t size = 0;
        for (const_iterator it = begin(); it != end(); ++it)
            ++size;

        return size;
    }

    /**
     * @brief Is the list empty?
     */
    bool empty() const
    {
        return (begin() == end());
    }

    /**
     * @brief Empty the list
     */
    void clear()
    {
        while (!empty())
            remove_front();
    }

    // missing: find an element with a specific value (and return an iterator)

    /**
     * @brief insert in front
     */
    void insert_front(const Object &x)
    {
        Node *n = new Node{x, head};
        head = n;
    }

    /**
     * @brief remove the element in front
     */
    Object remove_front()
    {
        if (empty())
            throw std::runtime_error("List is empty!");

        // save the data
        Object tmpObject = head->data;

        // delete the node
        Node *tmpNode = head;
        head = head->next;
        delete tmpNode;

        return tmpObject;
    }

    /**
     * @brief find an element. Returns an iterator
     * to the element or end() if not found.
     */
    iterator find(const Object &x)
    {
        iterator it = begin();
        while (it != end() && *it != x)
            ++it;
        return it;
    }

    /**
     * @brief insert after iterator
     * 
     * Does not work on empty list!
     */
    void insert(const Object &x, iterator &it)
    {
        if (it == end())
            throw std::runtime_error("Cannot insert after end()");

        Node *n = new Node{x, it.current->next};
        it.current = n;
    }

    /**
     * @brief remove after iterator
     *
     * Note: removing the element the iterator points to
     * is not possible since we do not have a previous pointer.
     */
    void remove(iterator &it)
    {
        if (it == end())
            throw std::runtime_error("Cannot remove after end()");

        Node *tmpNode = it.current->next;
        if (tmpNode == nullptr)
            throw std::runtime_error("No node after the iterator!");

        it.current->next = tmpNode->next;
        delete tmpNode;
    }
};

#endif