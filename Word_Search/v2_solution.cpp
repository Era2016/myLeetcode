#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    bool backtrack(vector<vector<char>>& board, string word, int x, int y, int idx) {
        int m = board.size(), n = board[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[idx]) {
            return false;
        }
        if (idx == word.length()-1) return true;

        board[x][y] = '\0';
        bool res = backtrack(board, word, x+1, y, idx+1) ||
            backtrack(board, word, x-1, y, idx+1) ||
            backtrack(board, word, x, y+1, idx+1) ||
            backtrack(board, word, x, y-1, idx+1);
        board[x][y] = word[idx];
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<char>> board;

    board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::cout << so->exist(board, "ABCCED") << std::endl;
    std::cout << so->exist(board, "SEE") << std::endl;
    std::cout << so->exist(board, "ABCB") << std::endl;

    board = {{'a'}};
    std::cout << so->exist(board, "a") << std::endl;

    board = {{'a','b','c'},{'a','e','d'},{'a','f','g'}};
    std::cout << so->exist(board, "abcdefg") << std::endl;

    board = {{'a','a'}};
    std::cout << so->exist(board, "aaa") << std::endl;
}
