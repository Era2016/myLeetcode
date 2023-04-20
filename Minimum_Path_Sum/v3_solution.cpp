#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][1] = dp[1][0] = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        // print path
        /*
        vector<vector<int>> path;
        int x = m, y = n;
        path.push_back({x - 1, y - 1});
        while(x != 1 || y != 1){
            if(dp[x - 1][y] < dp[x][y - 1]) x--;
            else y--;
            path.push_back({x - 1, y - 1});
        }
        reverse(path.begin(), path.end());

        for(int i = 0; i < path.size(); i++)
            std::cout << path[i][0] << " " << path[i][1] << std::endl;
        
        */
        return dp[m][n];
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> vv; 

    vv = {{1,3,1}, {1,5,1}, {4,2,1}};
    std::cout << so->minPathSum(vv) << std::endl;
    
    vv = {{1,2,3}, {4,5,6}};
    std::cout << so->minPathSum(vv) << std::endl;
}
