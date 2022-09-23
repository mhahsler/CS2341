#ifndef DSList_ITER_H
#define DSList_ITER_H

#include <stdexcept>

/**
 * @brief Singly-linked list using iterators.
 * 
 * Partial implementation
 * 
 * @tparam Object 
 */
template <typename Object>
class DSList_iter
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
    /**
     * @brief Nested iterator class for Const Objects
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
     * @brief Nested iterator class for Non-Const Objects
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

        // equal and non-equal is inherited.
    };

    /**
     * @brief Construct a new DSlist iter<object> object
     */
    DSList_iter<Object>()
        : head{nullptr} {}

    // missing: Copy constructor
    
    /**
     * @brief Destroy the DSlist iter object
     */
    ~DSList_iter()
    {
        clear();
    }

    /**
     * @brief Returns an iterator to the first element
     */
    iterator begin() const
    {
        return head;
    }

    /**
     * @brief Returns an iterator to the past-the-end element
     */
    iterator end() const
    {
        return nullptr;
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
            pop_front();
    }

    // missing: find an element with a specific value (and return an iterator)
    
    /**
     * @brief insert in front
     */
    void push_front(const Object &x)
    {
        Node *n = new Node{x, head};
        head = n;
    }

    // insert using an iterator

    /**
     * @brief remove the element in front (pop_front)
     */
    Object pop_front()
    {
        if (empty())
            throw std::runtime_error("List is empty!");

        Node *tmpNode = head;
        Object tmpObject = head->data;
        head = head->next;
        delete tmpNode;

        return tmpObject;
    }

    // missing: remove using an iterator
    // missing: remove an element with a specific value (find and then remove)

private:
    Node *head;
};

#endif