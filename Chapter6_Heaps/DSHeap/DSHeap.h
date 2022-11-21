#ifndef DSHEAP
#define DSHEAP

#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename Comparable>
class DSHeap
{
private:
    vector<Comparable> array;

public:
    explicit DSHeap()
    {
        // an empty heap is represented by vector of size 1 (the first element is not used)
        array = vector<Comparable>(1);
    }

    bool empty() const
    {
        return array.size() == 1;
    }

    void insert(const Comparable &x)
    {
        // add hole (capacity is handled by vector)
        array.push_back(x);

        size_t hole = array.size() - 1;
        size_t holeParent = hole / 2; // this is an integer division so it includes floor

        // percolate up till x fits
        while (x < array[holeParent] && hole > 1)
        {
            swap(array[hole], array[holeParent]);
            hole = holeParent;
            holeParent = hole / 2;
        }

        // Note x is already in the hole
    }

    Comparable deleteMin()
    {
        if (empty())
            throw runtime_error("heap is empty!");

        // create hole at root
        Comparable min;
        swap(min, array[1]);
        size_t hole = 1;

        size_t lastElement = array.size() - 1;
        size_t child, childLeft, childRight;

        // percolate hole down till last element fits or hole is a leaf (has no left child)
        while (true)
        {
            childLeft = hole * 2;
            childRight = childLeft + 1;

            // break if hole is a leaf
            if (childLeft >= lastElement)
                break;

            // find smaller child (if right child exists)
            if (childRight < lastElement && array[childRight] < array[childLeft])
                child = childRight;
            else
                child = childLeft;

            // break if last element fits
            if (array[lastElement] < array[child])
                break;

            // otherwise, move child up
            swap(array[hole], array[child]);
            hole = child;
        }

        // move last element to hole and remove the last element
        swap(array[hole], array[lastElement]);
        array.pop_back();

        return min;
    }

    void makeEmpty()
    {
        array.resize(1);
    }

    void prettyPrintTree() const
    {
        prettyPrintTree(1, "", false);
    }

private:
    // Modified from: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c

    void prettyPrintTree(size_t nodeID, const string &prefix, bool isRight) const
    {
        // base case
        if (nodeID >= array.size())
            return;

        // recursion
        cout << prefix;
        cout << (isRight ? "├──" : "└──");
        // print the value of the node
        cout << array[nodeID] << " [" << nodeID << "]"
             << "\n";

        // enter the next tree level - left and right branch
        prettyPrintTree(2 * nodeID + 1, prefix + (isRight ? "│   " : "    "), true);
        prettyPrintTree(2 * nodeID, prefix + (isRight ? "│   " : "    "), false);
    }
};

#endif