#include <iostream>
#include <deque>

using std::deque;
class MinStack {
private:
    deque<int> stack;
    deque<int> minSt;
public:
    MinStack(): stack(0), minSt(0) {}
    
    void push(int val) {
        stack.emplace_back(val);
        int minVal = INT_MAX;
        if (!minSt.empty()) {
            minVal = minSt.back();
        }

        if (val <= minVal) {
            minSt.emplace_back(val);
        } else {
            minSt.emplace_back(minVal);
        }
    }
    
    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
            minSt.pop_back();
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minSt.back();
    }
};

int main() {
    MinStack* minStack = new MinStack();

    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->getMin() << std::endl; // return -3
    minStack->pop();
    std::cout << minStack->top() << std::endl;    // return 0
    std::cout << minStack->getMin() << std::endl; // return -2

}
