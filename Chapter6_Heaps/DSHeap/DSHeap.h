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

        // percolate up till x fits or we reach the root
        for (size_t hole = array.size() - 1; x < array[parent(hole)] && hole > 1; hole = parent(hole))
            swap(array[hole], array[parent(hole)]);

        // Note x is already in the hole
    }

    Comparable deleteMin()
    {
        if (empty())
            throw runtime_error("heap is empty!");

        // get minimum and create hole
        Comparable min = std::move(array[1]);
        Comparable tmp = std::move(array[array.size() - 1]);
        array.pop_back();

        size_t hole, child;

        // percolate hole down till it is a leaf (has no left child)
        // or last element fits or hole
        for (hole = 1; leftChild(hole) < array.size(); hole = child)
        {
            child = leftChild(hole);
            if (child != array.size() - 1 && array[child] > array[child + 1])
                ++child;

            // break if last element in the hole fits
            if (tmp < array[child])
                break;

            array[hole] = std::move(array[child]);      
        }

        // move last element in hole
         array[hole] = std::move(tmp);

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
    inline std::size_t leftChild(std::size_t i) const
    {
        return 2 * i;
    }

    inline std::size_t parent(std::size_t i) const
    {
        return i / 2;
    }

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
        prettyPrintTree(leftChild(nodeID) + 1, prefix + (isRight ? "│   " : "    "), true);
        prettyPrintTree(leftChild(nodeID), prefix + (isRight ? "│   " : "    "), false);
    }
};

#endif