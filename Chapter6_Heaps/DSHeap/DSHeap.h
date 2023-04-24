#ifndef DSHEAP
#define DSHEAP

#include <vector>
#include <stdexcept>
#include <iostream>

template <typename Comparable>
class DSHeap
{
private:
    std::vector<Comparable> array;

public:
    explicit DSHeap()
    {
        // an empty heap is represented by vector of size 1 (the first element is not used)
        array = std::vector<Comparable>(1);
    }

    bool empty() const
    {
        return array.size() <= 1;
    }

    void insert(const Comparable &x)
    {
        // 1. place the new value in the hole (capacity is handled by vector)
        array.push_back(x);

        // 2. percolate up till x fits or we have reached the root
        for (size_t hole = array.size() - 1; x < array[parent(hole)] && hole > 1; hole = parent(hole))
            std::swap(array[hole], array[parent(hole)]);
    }

    Comparable deleteMin()
    {
        // special case: empty heap
        if (empty())
            throw std::runtime_error("heap is empty!");

        // save minimum. Root is now the new hole
        Comparable min = std::move(array[1]);
        
        // find last element
        Comparable& last = array[array.size() - 1];
        
        // percolate hole down (= move child up) till it is a leaf (has no left child)
        // or last element fits or hole
        size_t hole = 1;
        while (leftChild(hole) < array.size())
        {
            size_t child = leftChild(hole);
            if (child != array.size() - 1 && array[child] > array[child + 1])
                ++child;

            // break if last element in the hole fits
            if (last < array[child])
                break;

            // move child up
            array[hole] = std::move(array[child]);  
            hole = child;    
        }

        // move last element in hole and make heap smaller 
        array[hole] = std::move(last);
        array.pop_back();

        return min;
    }

    void makeEmpty()
    {
        array.resize(1); // remember: The 1 element is not used!
    }

    void prettyPrintTree() const
    {
        prettyPrintTree(1, std::string(""), false);
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
    void prettyPrintTree(size_t nodeID, const std::string &prefix, bool isRight) const
    {
        // base case
        if (nodeID >= array.size())
            return;

        // recursion
        std::cout << prefix;
        std::cout << (isRight ? "├──" : "└──");
        // print the value of the node
        std::cout << array[nodeID] << " [" << nodeID << "]"
             << "\n";

        // enter the next tree level - left and right branch
        prettyPrintTree(leftChild(nodeID) + 1, prefix + (isRight ? "│   " : "    "), true);
        prettyPrintTree(leftChild(nodeID), prefix + (isRight ? "│   " : "    "), false);
    }
};

#endif