#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>
#include <stdexcept>

using namespace std;

/**
 * @brief Simple implementation of an (unbalanced) binary search tree
 *
 * @tparam Comparable
 */
template <typename Comparable>
class BinarySearchTree
{
    // define node structure as a nested class
private:
    class BinaryNode
    {
    public:
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
            : element{theElement}, left{lt}, right{rt} {}
    };

    BinaryNode *root;

public:
    /**
     * @brief Default Constructor creates an empty Binary Search Tree
     *
     */
    BinarySearchTree() : root{nullptr}
    {
    }

    /**
     * @brief Rule-of-3 Part 1: Copy constructor uses internal function clone().
     * 
     */
    BinarySearchTree(const BinarySearchTree &rhs) : root{nullptr}
    {
        root = clone(rhs.root);
    }

    /**
     * @brief Rule-of-3 Part 2: Destroy the Binary Search Tree object using the internal 
     *   function makeEmpty().
     */
    ~BinarySearchTree()
    {
        makeEmpty();
    }

    /**
     * @brief Rule-of-3 Part 3: Copy assignment
     */
    BinarySearchTree &operator=(const BinarySearchTree &rhs)
    {
        makeEmpty();
        root = clone(rhs.root);
        
        return *this;
    }
    
    /**
     * @brief Test if the tree is logically empty.
     */
    bool isEmpty() const
    {
        return root == nullptr;
    }

    /**
     * @brief Returns true if x is found in the tree using an internal function.
     */
    bool contains(const Comparable &x) const
    {
        return contains(x, root);
    }

    
    /**
     * @brief Print the tree contents in sorted order (i.e., inorder traversal). 
     * This is Tree Sort.
     */
    void printTree(ostream &out = cout) const
    {
        if (isEmpty())
            out << "Empty tree" << endl;
        else
            printTree(root, out);
    }

    /**
     * @brief Print the tree structure (for debugging)
     */
    void prettyPrintTree() const
    {
        prettyPrintTree("", root, false);
    }

    /**
     * @brief Make the tree empty.
     */
    void makeEmpty()
    {
        makeEmpty(root);
    }

    /**
     * @brief Insert x into the tree; duplicates are ignored.
     */
    void insert(const Comparable &x)
    {
        insert(x, root);
    }

    /**
     * @brief Remove x from the tree. Nothing is done if x is not found.
     */
    void remove(const Comparable &x)
    {
        remove(x, root);
    }

    /**
     * @brief Find the smallest item in the tree.
     */
    const Comparable &findMin() const
    {
        if (isEmpty())
            throw std::runtime_error("tree is empty!");
        return findMin(root)->element;
    }

    /**
     * @brief find the largest item in the tree.
     */
    const Comparable &findMax() const
    {
        if (isEmpty())
            throw std::runtime_error("tree is empty!");
        return findMax(root)->element;
    }

    int maxDepth()
    {
        return maxDepth(root, 0);
    }

    double avgDepth()
    {
        cout << "Needs to be implemented!\n"
             << endl;
        return 0;
    }

private:
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     */
    void insert(const Comparable &x, BinaryNode *&t)
    {
        // found an empty spot? insert a new node
        if (t == nullptr)
            t = new BinaryNode{x, nullptr, nullptr};

        // recursively find the insert position
        else if (x < t->element)
            insert(x, t->left);
        else if (t->element < x)
            insert(x, t->right);
        else
        {
        }; // Duplicate: element == x; do nothing... we could do other things.
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove(const Comparable &x, BinaryNode *&t)
    {
        if (t == nullptr)
            return; // Item not found; do nothing

        // recursively find the node using binary search
        if (x < t->element)
            return remove(x, t->left);

        if (t->element < x)
            return remove(x, t->right);

        // found element == x -> delete
        if (t->left != nullptr && t->right != nullptr)
        {
            // Two children case: replace element with the smallest element in
            // the right subtree
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            // One child case: replace the node with the only child, if any.
            BinaryNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode *findMin(BinaryNode *t) const
    {
        // recursive implementation
        // special case: no root node
        if (t == nullptr)
            return nullptr;

        // traverse down left to the leaf
        if (t->left == nullptr)
            return t;

        return findMin(t->left);
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode *findMax(BinaryNode *t) const
    {
        // iterative implementation of going down right to the leaf.
        // special case: no root node
        if (t == nullptr)
            return nullptr;

        // traverse down right to the leaf
        while (t->right != nullptr)
            t = t->right;
        return t;
    }

    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains(const Comparable &x, BinaryNode *t) const
    {
        if (t == nullptr)
            return false;

        if (x < t->element)
            return contains(x, t->left);

        if (t->element < x)
            return contains(x, t->right);

        return true; // Match
    }
    /****** NONRECURSIVE VERSION*************************
        bool contains( const Comparable & x, BinaryNode *t ) const
        {
            while( t != nullptr )
                if( x < t->element )
                    t = t->left;
                else if( t->element < x )
                    t = t->right;
                else
                    return true;    // Match

            return false;   // No match
        }
    *****************************************************/

    /**
     * Internal method to make subtree empty uses postorder traversal (LRN)
     */
    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     * This is inorder traversal (LNR)
     */
    void printTree(BinaryNode *t, ostream &out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            out << t->element << endl;
            printTree(t->right, out);
        }
    }

    /**
     *  Pretty print the tree structure
     *  Uses preorder traversal with R and L swapped (NRL)
     *
     *  Modified from: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
     */
    void prettyPrintTree(const string &prefix, const BinaryNode *node, bool isRight) const
    {
        if (node != nullptr)
        {
            cout << prefix;
            cout << (isRight ? "├──" : "└──");
            // print the value of the node
            cout << node->element << "\n";

            // enter the next tree level - left and right branch
            prettyPrintTree(prefix + (isRight ? "│   " : "    "), node->right, true);
            prettyPrintTree(prefix + (isRight ? "│   " : "    "), node->left, false);
        }
    }

    /**
     * Internal method to clone subtree.
     * -> preorder traversal (NLR)
     */
    BinaryNode *clone(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        else
            return new BinaryNode{t->element, clone(t->left), clone(t->right)};
    }

    /**
     * maxDepth = height of the node
     *
     * -> postorder traversal (LRN)
     */
    int maxDepth(BinaryNode *t, int depth)
    {
        if (t == nullptr)
            return depth;

        // traverse down
        return (std::max(maxDepth(t->left, depth + 1),
                         maxDepth(t->right, depth + 1)));
    }
};

#endif
