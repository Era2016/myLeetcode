#include <iostream>
#include <vector>

using std::vector;
class Solution {
    public:
    // 黄色的边是与网格边界相邻的周长，而蓝色的边是与海洋格子相邻的周长
    //
    // 当我们的 dfs 函数因为「坐标 (r, c) 超出网格范围」返回的时候，实际上就经过了一条黄色的边；
    // 而当函数因为「当前格子是海洋格子」返回的时候，实际上就经过了一条蓝色的边。

    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    // 题目限制只有一个岛屿，计算一个即可
                    return dfs(grid, i, j);
                }
            }
        } 
        return 0;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        // 函数因为「坐标 (r, c) 超出网格范围」返回，对应一条黄色的边
        if (!inArea(grid, r, c)) {
            return 1;
        } 

        // 函数因为「当前格子是海洋格子」返回，对应一条蓝色的边
        if (grid[r][c] == 0) {
            return 1;
        }

        // 函数因为「当前格子是已遍历的陆地格子」返回，和周长没关系
        if (grid[r][c] != 1) {
            return 0;
        }
        
        grid[r][c] = 2;
        return dfs(grid, r-1, c)
            + dfs(grid, r+1, c)
            + dfs(grid, r, c+1)
            + dfs(grid, r, c-1);
    }

    int inArea(vector<vector<int>>& grid, int r, int c) {
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
        {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}
    };
    std::cout << so->islandPerimeter(vv) << std::endl;

    vv = {{1}};
    std::cout << so->islandPerimeter(vv) << std::endl;

    vv = {{1,0}};
    std::cout << so->islandPerimeter(vv) << std::endl;
}
