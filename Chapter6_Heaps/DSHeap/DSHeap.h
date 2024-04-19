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

    // constructor that heapifies a vector (i.e., performs heap sort)
    explicit DSHeap(const std::vector<Comparable> &items) : DSHeap()
    {
        // 1. reserve enough space for all items
        array.reserve(items.size() + 1);

        // 2. insert all items
        for (const Comparable &item : items)
            insert(item);
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

  
    Comparable delete_min()
    {
        // special case: empty heap
        if (empty())
            throw std::runtime_error("heap is empty!");

        // save minimum for return. Root is now the new hole.
        Comparable min = std::move(array[1]);
        
        // find last element
        Comparable& last = array[array.size() - 1];
        
        // percolate hole down (= move child up) till it is a leaf (i.e., has no left child in this case)
        // or the last element fits or hole
        size_t hole = 1;
        size_t left, right, child;

        while ((left = left_child(hole)) < array.size())
        {
            // find smaller child index: left or right.
            // we can use the fact that vector manages the true size and capacity to check if it exists
            right = left + 1; // right child index is left child + 1
            if (right < array.size() && array[left] > array[right])
                child = right;
            else
                child = left;

            // found position where the last element fits
            if (last < array[child])
                break;

            // move child up (std::move just marks the child as moveable if it has a move assignment operator)
            array[hole] = std::move(array[child]);  
            hole = child;    
        }

        // move last element to the hole and make heap smaller using pop_back
        array[hole] = std::move(last);
        array.pop_back();

        return min;
    }

    void make_empty()
    {
        array.resize(1); // remember: The 1st element is not used!
    }

    void print_tree() const
    {
        print_tree(1, std::string(""), false);
    }

private:
    // Calculates the index of the left child or the parent of the node with index i. Note: right_child is left_child + 1
    inline std::size_t left_child(std::size_t i) const
    {
        return 2 * i;
    }

    inline std::size_t parent(std::size_t i) const
    {
        return i / 2;  // this is an int division
    }

    // Modified from: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
    void print_tree(size_t nodeID, const std::string &prefix, bool isRight) const
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
        print_tree(left_child(nodeID) + 1, prefix + (isRight ? "│   " : "    "), true);
        print_tree(left_child(nodeID), prefix + (isRight ? "│   " : "    "), false);
    }
};

#endif