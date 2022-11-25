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

        // get minimum and create hole
        Comparable min = std::move(array[1]);
        size_t hole = 1;
   
        // move last element to hole and reduce array size
        size_t lastElement = array.size() - 1;
        array[1] = std::move(array[lastElement]);
        array.pop_back();
        
        size_t child, childLeft = hole * 2, childRight = childLeft + 1;

        // percolate hole down till it is a leaf (has no left child)
        // or last element fits or hole
        while (childLeft < lastElement)
        {
            // if right child exists, find smaller child
            if (childRight < lastElement && array[childRight] < array[childLeft])
                child = childRight;
            else
                child = childLeft;

            // break if last element in the hole fits
            if (array[hole] < array[child])
                break;

            // otherwise, move hole down
            std::swap(array[hole], array[child]);
            hole = child;
            childLeft = hole * 2;
            childRight = childLeft + 1;
        }

        // last element is already in the hole.
        
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