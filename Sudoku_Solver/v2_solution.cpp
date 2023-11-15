#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    int r, c;
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i ++) {
            if (board[row][i] == num) return false;
            if (board[i][col] == num) return false;
        }
        
        for (int i = 0; i <= 2; i ++) {
            for (int j = 0; j <= 2; j ++) {
                if (board[row/3*3+i][col/3*3+j] == num) return false;
            }
        }
        return true;
    }
    bool backtrack(vector<vector<char>>& board, int row, int col) {
        if (row == r) {
            return true;
        }
        
        if (col == c) {
            //col = 0; row = row+1; // wrong
            return backtrack(board, row+1, 0);
        }

        if (board[row][col] != '.') {
            return backtrack(board, row, col+1);
        }

        for (int i = 0; i <= 9; i ++) {
            char c = i+'0';
            if (isValid(board, row, col, c)) {
                board[row][col] = c; 
                if (backtrack(board, row, col+1)) {
                    return true;
                }
                board[row][col] = '.';
            } 
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        this->r = this->c = 9;
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
