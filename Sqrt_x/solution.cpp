#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int ans = 0;
        while (left <= right) {
            int mid = (right-left)/2 + left;
            if ((long) mid*mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->mySqrt(8) << std::endl;
    std::cout << so->mySqrt(4) << std::endl;
}
