#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    int m, n;
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') {
            return;
        }
        board[row][col] = 'A';
        dfs(board, row-1, col);
        dfs(board, row+1, col);
        dfs(board, row, col-1);
        dfs(board, row, col+1);
    }
public:
    void solve(vector<vector<char>>& board) {
        this->m = board.size();
        this->n = board[0].size();

        for (int i = 0; i < m; i ++) {
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }

        for (int j = 0; j < n; j ++) {
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<char>> board;
    auto print=[&]() {
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        std::cout << "\n";
    };

    board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    so->solve(board);
    print();

    board = {{'X'}};
    so->solve(board);
    print();
}
