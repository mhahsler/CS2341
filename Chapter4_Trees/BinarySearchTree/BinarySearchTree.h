#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <queue> // for level-order traversal

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
        Comparable key;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &theKey, BinaryNode *lt, BinaryNode *rt)
            : key{theKey}, left{lt}, right{rt} {}
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
     * @brief Returns true if x is found in the tree using an internal function.
     */
    bool contains(const Comparable &x) const
    {
        return find(x, root) != nullptr;
    }

    /**
     * @brief Print the tree contents in sorted order (i.e., inorder traversal).
     * This is Tree Sort.
     */
    void printTreeSort(ostream &out = cout) const
    {
        if (isEmpty())
            out << "Empty tree" << endl;
        else
            printTreeSort(root, out);
    }

    /**
     * @brief Print the tree structure (for debugging)
     */
    void prettyPrintTree() const
    {
        prettyPrintTree("", root, false);
    }

    /**
     * @brief Print the tree contents in sorted order.
     */

    void printTreeByLevel(ostream &out = cout) const
    {
        printTreeByLevel(root, out);
    }


    /**
     * @brief Make the tree empty.
     */
    void makeEmpty()
    {
        makeEmpty(root);
    }

    /**
     * @brief Find the smallest item in the tree.
     */
    const Comparable &findMin() const
    {
        if (isEmpty())
            throw std::runtime_error("tree is empty!");
        return findMin(root)->key;
    }

    /**
     * @brief find the largest item in the tree.
     */
    const Comparable &findMax() const
    {
        if (isEmpty())
            throw std::runtime_error("tree is empty!");
        return findMax(root)->key;
    }

    int maxDepth()
    {
        return maxDepth(root, 0);
    }

    double avgDepth()
    {
        throw std::runtime_error("Not implemented yet!");
        return 0.0;
    }

private:
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t a non-const reference to the pointer to the node that roots the subtree.
     */
    void insert(const Comparable &x, BinaryNode* &t)
    {
        // Base case: found an empty spot? insert a new node
        //   This can be done because t is a reference to a pointer! We could also use a pointer-pointer
        if (t == nullptr)
            t = new BinaryNode{x, nullptr, nullptr};

        // recursively find the insert position
        else if (x < t->key)
            insert(x, t->left);
        else if (t->key < x)
            insert(x, t->right);
        else
        {
        }; // Duplicate: key == x; do nothing... we could do other things.
    }
    // We could easily implement a iterative version with a while loop....



    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove(const Comparable &x, BinaryNode *&t)
    {
        // Recursively find the node to delete using binary search.

        if (t == nullptr)
            return; // Item not found; do nothing

        // must be in left subtree
        if (x < t->key)
            return remove(x, t->left);

        // must be in right subtree
        if (t->key < x)
            return remove(x, t->right);

        // we get here only for t->key == x!!!
        // Do the deletion

        // Cases:
        // A. No children: Just remove the node.
        if (t->left == nullptr && t->right == nullptr)
        {
            delete t;
            t = nullptr;
            return;
        }

        // C. Two children case: replace key with the smallest key in the right subtree.
        if (t->left != nullptr && t->right != nullptr)
        {
            BinaryNode *replacement = removeMin(t->right);
            replacement->right = t->right;
            replacement->left = t->left;

            delete t;
            t = replacement;
            return;
        }

        // B. One child case: replace the node with the only child.
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }

   /**
     * Internal method to find, remove and return the smallest item in a subtree t (used in remove)
     */
    BinaryNode *removeMin(BinaryNode *&t)
    {
        // recursive implementation
        // special case: no root node
        if (t == nullptr)
            return nullptr;

        // special case: root is the minimum
        if (t->left == nullptr)
        {
            BinaryNode *min = t;
            t = t->right;
            return min;
        }

        // traverse down left to the leaf
        if (t->left->left == nullptr)
        {
            BinaryNode *min = t->left;
            // there could be a right node!
            t->left = min->right; 
            return min;
        }

        return removeMin(t->left);
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
        // this can be done recursively, but I show here an 
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
     * Internal method to find a node.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    BinaryNode *find(const Comparable &x, BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;

        // recursion
        if (x < t->key)
            return find(x, t->left);

        if (t->key < x)
            return find(x, t->right);

        // we have t->key == x
        return t; // Match
    }
    /****** NONRECURSIVE VERSION*************************
    BinaryNode* find( const Comparable & x, BinaryNode *t ) const
        {
            while( t != nullptr )
                if( x < t->key )
                    t = t->left;
                else if( t->key < x )
                    t = t->right;
                else
                    return t;    // Match

            return nullptr;   // No match
        }
    *****************************************************/

    /**
     * Internal method to clone subtree.
     * -> preorder traversal (NLR)
     */
    BinaryNode *clone(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;

        // recursion
        return new BinaryNode{t->key, clone(t->left), clone(t->right)};
    }

    /**
     * Internal method to make subtree empty uses postorder traversal (LRN)
     * Note the pointer reference for t.
     */
    void makeEmpty(BinaryNode *&t)
    {
        if (t == nullptr)
            return;

        // recursion
        makeEmpty(t->left);  // L
        makeEmpty(t->right); // R
        
        delete t;            // N
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     * This is inorder traversal (LNR)
     */
    void printTreeSort(BinaryNode *t, ostream &out) const
    {
        if (t == nullptr)
            return;

        // recursion
        printTreeSort(t->left, out);  // L
        out << t->key << endl;        // N
        printTreeSort(t->right, out); // R
    }

    /**
     *  Pretty print the tree structure
     *  Uses preorder traversal with R and L swapped (NRL)
     *
     *  Modified from: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
     */
    void prettyPrintTree(const string &prefix, const BinaryNode *node, bool isRight) const
    {
        if (node == nullptr)
            return;

        // N: print the value of the node
        cout << prefix;
        cout << (isRight ? "├──" : "└──");
        cout << node->key << "\n";

        // R, L: enter the next tree level - right and left branch
        prettyPrintTree(prefix + (isRight ? "│   " : "    "), node->right, true);
        prettyPrintTree(prefix + (isRight ? "│   " : "    "), node->left, false);
    }

    /**
     * Internal method to print a subtree rooted.
     * This is level-order traversal.
     * We use a loop and a queue an auxiliary data structure to remember what node to process next.
     */
    void printTreeByLevel(BinaryNode *t, ostream &out) const
    {
        if (t == nullptr)
            return;

        BinaryNode *current;
        queue<BinaryNode *> q;

        // start with the root node in the queue
        q.push(t);

        while (!q.empty())
        {
            // take the next node from the front of the queue
            current = q.front();
            q.pop();
            out << current->key << " ";

            // add children to the end of the queue
            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
    }


    /**
     * maxDepth = height of the node
     *
     * -> postorder traversal (LRN)
     */
    int maxDepth(BinaryNode *t, int depth)
    {
        // Leaf node? Report the depth. 
        if (t == nullptr)
            return depth;

        // max depth of left (L) and right (R) subtree. N does not do anything.
        return (std::max(maxDepth(t->left, depth + 1),
                         maxDepth(t->right, depth + 1)));
    }
};

#endif
