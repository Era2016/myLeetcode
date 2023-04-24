#include <iostream>
#include <vector>

using std::vector;
using std::max;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    res = max(area, res); 
                }
            }
        }
        
        return res;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (!inArea(grid, r, c)) return 0;

        if (grid[r][c] != 1) return 0;

        grid[r][c] = 2;

        return 1  
            +dfs(grid, r-1, c)
            +dfs(grid, r+1, c)
            +dfs(grid, r, c+1)
            +dfs(grid, r, c-1);
    }

    bool inArea(vector<vector<int>>& grid, int r, int c) {
        if (r >= 0 && r < grid.size() &&
                c >= 0 && c < grid[0].size()) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> vv;

    vv = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    std::cout << so->maxAreaOfIsland(vv) << std::endl;
    
    vv = {{0,0,0,0,0,0,0,0}};
    std::cout << so->maxAreaOfIsland(vv) << std::endl;
}
