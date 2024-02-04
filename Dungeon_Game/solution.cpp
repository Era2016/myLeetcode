#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    /*
     * dp[i][j]: <i, j>到右下角所需血条
     * dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]
     *
     * return dp[0][0]
     */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[m-1][n-1] = dungeon[m-1][n-1]>0 ? 1: -dungeon[m-1][n-1]+1;
        for (int i = m-2; i >= 0; i --) {
            dp[i][n-1] = dp[i+1][n-1] - dungeon[i][n-1];
            dp[i][n-1] = std::max(dp[i][n-1], 1);
        }
        for (int j = n-2; j >= 0; j --) {
            dp[m-1][j] = dp[m-1][j+1] - dungeon[m-1][j];
            dp[m-1][j] = std::max(dp[m-1][j], 1);
        }
        for (int i = m-2; i >= 0; i --) {
            for (int j = n-2; j >= 0; j --) {
                dp[i][j] = std::min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                //dp[i][j] = dp[i][j]<0 ? 1: dp[i][j];
                dp[i][j] = std::max(dp[i][j], 1);
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> nums; 
    
    nums = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    std::cout << so->calculateMinimumHP(nums) << std::endl; // 7

    nums = {{0}};
    std::cout << so->calculateMinimumHP(nums) << std::endl; // 1

    nums = {{0,0,0},{1,1,-1}};
    std::cout << so->calculateMinimumHP(nums) << std::endl; // 1
}
