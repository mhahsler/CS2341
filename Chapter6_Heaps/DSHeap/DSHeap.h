#ifndef DSHEAP
#define DSHEAP

#include <vector>
#include <stdexcept>

using namespace std;

template <typename Comparable>
class DSHeap
{
private:
    vector<Comparable> array;

public:
    explicit DSHeap()
    {
        array = vector<Comparable>(1);
    }

    bool empty() const
    {
        return array.size() == 1;
    }

    void insert(const Comparable &x)
    {
        // add hole
        array.resize(array.size() + 1);

        size_t hole = array.size() - 1;
        size_t holeParent = hole / 2;

        // percolate up
        while (x < array[holeParent] && hole > 1)
        {

            swap(array[hole], array[holeParent]);
            hole = holeParent;
            holeParent = hole / 2;
        }

        array[hole] = x;
    }

    Comparable deleteMin()
    {
        if (empty())
            throw std::runtime_error("heap is empty!");

        Comparable min = array[1];
        size_t hole = 1;
        size_t childLeft, childRight;
        size_t x = array.size() - 1;

        // percolate down till x fits
        while (true)
        {
            childLeft = 2 * hole;
            childRight = 2 * hole + 1;

            // Case 1: 2 children (not x)
            // Case 2: left child and x on the right
            // Case 3: only x as the left child, right is empty

            // Case 1
            if (childRight < x)
            {
                // x fits
                if (array[x] < array[childLeft] && array[x] < array[childRight])
                {
                    swap(array[x], array[hole]);
                    array.resize(array.size() - 1);
                    break;
                }

                // move hole
                if (array[childLeft] < array[childRight])
                {
                    swap(array[childLeft], array[hole]);
                    hole = childLeft;
                }
                else
                {
                    swap(array[childRight], array[hole]);
                    hole = childRight;
                }
            }
            else if (childRight == x) // Case 2
            {
                if (array[childLeft] < array[x])
                {
                    swap(array[childLeft], array[hole]);
                    hole = childLeft;
                    swap(array[x], array[hole]);
                    array.resize(array.size() - 1);
                    break;
                }
                else
                {
                    swap(array[x], array[hole]);
                    array.resize(array.size() - 1);
                    break;
                }
            }
            else // Case 3: childLeft == x
            {
                swap(array[x], array[hole]);
                array.resize(array.size() - 1);
                break;
            }
        }
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
        cout << array[nodeID] << " [" << nodeID << "]" << "\n";

        // enter the next tree level - left and right branch
        prettyPrintTree(2 * nodeID + 1, prefix + (isRight ? "│   " : "    "), true);
        prettyPrintTree(2 * nodeID, prefix + (isRight ? "│   " : "    "), false);
    }
};

#endif