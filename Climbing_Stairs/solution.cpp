#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int climbStairs(int n) {
        //vector<int> dp(n+1, 0);
        //dp[0] = dp[1] = 1;
        //for (int i = 2; i <= n; i ++) {
        //    dp[i] = dp[i-1] + dp[i-2];
        //}
        //return dp[n];
        int a = 1, b = 1;
        int c = 1;
        for (int i = 2; i <= n; i ++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->climbStairs(2) << std::endl; // 2
    std::cout << so->climbStairs(3) << std::endl; // 3
    std::cout << so->climbStairs(5) << std::endl;
    std::cout << so->climbStairs(1) << std::endl; // 1
}
