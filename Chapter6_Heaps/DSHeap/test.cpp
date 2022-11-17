// NOTE: We use Catch2 V2
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

#include "DSHeap.h"

using namespace std;

TEST_CASE("Case 1&2", "[DSHeap]")
{
    DSHeap<int> heap = DSHeap<int>{};
    vector<int> in = {30, 100, 80, 25, 40};

    // expected output in reverse order (we will use pop_back())
    vector<int> out = in;
    sort(out.begin(), out.end(), greater<int>());

    for (auto const &d : in)
        heap.insert(d);

    while (!heap.empty())
    {
        REQUIRE(heap.deleteMin() == out.back());
        out.pop_back();
    }
}

TEST_CASE("Case 1&3", "[DSHeap]")
{
    DSHeap<int> heap = DSHeap<int>{};
    vector<int> in = {30, 100, 25, 40};
    vector<int> out = in;
    sort(out.begin(), out.end(), greater<int>());

    for (auto const &d : in)
        heap.insert(d);

    while (!heap.empty())
    {
        REQUIRE(heap.deleteMin() == out.back());
        out.pop_back();
    }
}

TEST_CASE("string", "[DSHeap]")
{
    DSHeap<string> heap = DSHeap<string>{};
    vector<string> in = {"Strawberry", "Grape", "Pear", "Apple"};
    vector<string> out = in;
    sort(out.begin(), out.end(), greater<string>());

    for (auto const &d : in)
        heap.insert(d);

    while (!heap.empty())
    {
        REQUIRE(heap.deleteMin() == out.back());
        out.pop_back();
    }
}

TEST_CASE("doubles", "[DSHeap]")
{
    DSHeap<double> heap = DSHeap<double>{};
    vector<double> in = {30.1, 100.2, 25.3, 40.4};
    vector<double> out = in;
    sort(out.begin(), out.end(), greater<double>());

    for (auto const &d : in)
        heap.insert(d);

    while (!heap.empty())
    {
        REQUIRE(heap.deleteMin() == out.back());
        out.pop_back();
    }
}

TEST_CASE("100 random int inputs up to length 100,000", "[DSHeap]")
{
    srand(time(nullptr));

    for (int i = 0; i < 100; ++i)
    {
        int len = rand() % 100000;
        vector<int> in(len);
        generate(in.begin(), in.end(), rand);
        vector<int> out = in;
        sort(out.begin(), out.end(), greater<int>());

        DSHeap<int> heap = DSHeap<int>{};

        for (auto const &d : in)
            heap.insert(d);

        while (!heap.empty())
        {
            REQUIRE(heap.deleteMin() == out.back());
            out.pop_back();
        }
    }
}