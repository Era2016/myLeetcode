#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::deque;

class MonotonicQueue {
private:
    deque<int> maxQ;
public:
    void push_back(int element) {
        // cannot contains '=': 7,5,7,1,6,0 will failed 
        while (!maxQ.empty() && maxQ.back() < element) {
            maxQ.pop_back();
        }
        maxQ.push_back(element);
    }

    int get_max() {
        return maxQ.front();
    }

    void pop_front(int element) {
        if (maxQ.front() == element) {
            maxQ.pop_front();
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue *window = new MonotonicQueue();
        vector<int> res;

        for (int i = 0; i < nums.size(); i ++) {
            if (i < k-1) {
                window->push_back(nums[i]);
            } else {
                window->push_back(nums[i]);
                res.push_back(window->get_max()); 
                window->pop_front(nums[i-k+1]);
            }
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    int k;
    vector<int> nums, res;

    auto print = [](vector<int> v) {
        for (int i: v) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
    };

    k = 3;
    nums = {1,3,-1,-3,5,3,6,7};
    res = so->maxSlidingWindow(nums, k);
    print(res);

    k = 1;
    nums = {1};
    res = so->maxSlidingWindow(nums, k);
    print(res);
}
