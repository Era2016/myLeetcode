#include <climits>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = triangle[0][0];
        int minVal = INT_MAX; 
        for (int i = 1; i < m; i ++) {
            for (int j = 0; j <= i; j ++) {
                dp[i][j] = (unsigned long)triangle[i][j] + std::min(dp[i-1][j], j>0? dp[i-1][j-1]: INT_MAX);
                if (i == m-1) {
                    minVal = std::min(minVal, dp[i][j]);
                }
            }
        }
        return minVal==INT_MAX? triangle[0][0]: minVal;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> triangle;

    triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    std::cout << so->minimumTotal(triangle) << std::endl;

    triangle = {{-10}};
    std::cout << so->minimumTotal(triangle) << std::endl;
}
