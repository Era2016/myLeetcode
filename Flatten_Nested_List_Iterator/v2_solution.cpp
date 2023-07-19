#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::deque;

 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    vector<int> res;
    vector<int>::iterator cur;
    void init(const vector<NestedInteger> &nestedList) {
        for (const auto& val: nestedList) {
            if (val.isInteger()) {
                res.push_back(val.getInteger());
            } else {
                init(val.getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        init(nestedList);
        cur = res.begin();
    }

    int next() {
        return *cur ++;
    }

    bool hasNext() {
        return cur != res.end();
    }
};
