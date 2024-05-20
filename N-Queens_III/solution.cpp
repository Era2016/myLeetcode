#include <cstddef>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
private:
    int cnt = 0;
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < row; i ++) {
            if (board[i][col] == c) {
                return false;
            }
        }
        return true;
    }
    void backtrack(vector<vector<char>>& board, int k, int row) {
        int m = board.size(); 
        if (k == 0) {
            cnt ++; return;
        }

        if (row == m) return;
        for (int i = 0; i < m; i ++) {
            if (board[row][i] == '#' && isValid(board, row, i, '*')) {
                board[row][i] = '*';
                backtrack(board, k-1, row+1);
                board[row][i] = '#';
            }
        }
        backtrack(board, k, row+1);
    }

    int getCnt() {
        return this->cnt;
    }
    void initCnt() {
        this->cnt = 0;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<char>> board;

    so->initCnt();
    board = {{'#','.'},{'.', '#'}};
    so->backtrack(board, 1, 0);
    std::cout << so->getCnt() << std::endl;

    so->initCnt();
    board = {{'.','.','.','#'},{'.','#','#','.'},{'.','#','.','.'},{'#','.','.','.'}};
    so->backtrack(board, 4, 0);
    std::cout << so->getCnt() << std::endl;

    //int n, k;
    //while (std::cin >> n >> k && n != -1 && k != -1) {
    //    vector<vector<char>> board(n, vector<char>(n));
    //    for (int i = 0; i < n; ++i) {
    //        for (int j = 0; j < n; ++j) {
    //            std::cin >> board[i][j];
    //        }
    //    }
    //    vector<bool> cols(n, false);
    //    so->backtrack(board, k, 0);
    //    std::cout << so->getCnt() << std::endl;
    //}
    //return 0;
}
