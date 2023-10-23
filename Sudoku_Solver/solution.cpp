#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    const int row = 9;
    const int column = 9;
    bool isValid(vector<vector<char>>& vv, int row, int col, char c) {
        for (int i = 0; i < 9; i ++) {
            if (vv[row][i] == c) return false;
            if (vv[i][col] == c) return false;

            if (vv[row/3*3+ i/3][col/3*3 + i%3] == c) return false;
        }
        return true;
    }
    bool backtrack(vector<vector<char>>& board, int _r, int _c) {
        if (_r == row) {
            return true;
        }

        if (_c == column) {
            return backtrack(board, _r+1, 0);
        }

        if (board[_r][_c] != '.') {
            return backtrack(board, _r, _c+1);
        }
        
        for (char c = '1'; c <= '9'; c ++) {
            if (!isValid(board, _r, _c, c)) {
                continue;
            }

            board[_r][_c] = c;
            if (backtrack(board, _r, _c+1)) {
                return true;
            }
            board[_r][_c] = '.';
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<char>> board;

    auto print=[](vector<vector<char>>& vv) {
        for (const auto& arr: vv) {
            for (const auto& v: arr) {
                std::cout << v << " ";
            }
            std::cout << std::endl << std::endl;
        }
    };
    board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    so->solveSudoku(board);
    print(board);
}