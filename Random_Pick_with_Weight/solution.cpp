#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;
using std::rand;
using std::srand;
using std::time;

class Solution {
    private:
    vector<int> presum;
    int leftBound(vector<int>& v, int target) {
        int left = 0, right = v.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (v[mid] == target) {
                right = mid - 1;
            } else if (v[mid] < target) {
                left = mid + 1;
            } else if (v[mid] > target) {
                right = mid - 1;
            }
        }

        // 未找到/超出边界 都返回left值
        return left;
    }
    public:
    Solution(vector<int>& w) {
        presum.resize(w.size()+1);
        for (int i = 1; i <= w.size(); i ++) {
            presum[i] = presum[i-1] + w[i-1];
        }
    }

    int pickIndex() {
        int randMax = presum[presum.size()-1];
        int randomVal = rand()%randMax+1; // [1, presum[n-1] ], not [presum[1/0], presum[n-1] ]
        int bound = leftBound(presum, randomVal)-1;
        //std::cout << "random:" << randomVal<< "; bound:" << bound << std::endl;
        return bound;
    }

};

int main() {
    vector<int> v;
    Solution *so;

    srand(time(0));
    v = {1};
    so = new Solution(v);
    for (int i = 0; i < 100; i ++) {
        std::cout << so->pickIndex() << " ";
    }
    std::cout << std::endl;

    v = {1, 3};
    so = new Solution(v);
    for (int i = 0; i < 100; i ++) {
        so->pickIndex();
        std::cout << so->pickIndex() << " ";
    }
    std::cout << std::endl;

    v = {1, 15, 3, 5, 10};
    so = new Solution(v);
    for (int i = 0; i < 100; i ++) {
        so->pickIndex();
        std::cout << so->pickIndex() << " ";
    }
    std::cout << std::endl;
}
