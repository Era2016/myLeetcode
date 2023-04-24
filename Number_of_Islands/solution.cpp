#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res ++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (!inArea(grid, r, c)) {
            return;
        }

        if (grid[r][c] != '1') {
            return;
        }

        grid[r][c] = '2'; // 已遍历

        // 访问上下左右
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    bool inArea(vector<vector<char>>& grid, int r, int c) {
        return r >= 0 && r < grid.size() &&
            c >= 0 && c < grid[0].size();
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<char>> vv;

    vv = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };
    std::cout << so->numIslands(vv) << std::endl;

    vv = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    std::cout << so->numIslands(vv) << std::endl;
}
