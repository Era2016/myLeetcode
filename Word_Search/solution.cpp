#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    bool backtrack(vector<vector<char>>& board, 
            std::pair<int, int> point, vector<vector<int>>& visit, string word, int idx) {

        if (idx == word.length()) {
            return true;
        }

        int m = board.size(), n = board[0].size();
        int x = point.first, y = point.second;
        if (x+1 < m && board[x+1][y] == word[idx] && !visit[x+1][y]) {
            visit[x+1][y] = true;
            if (true == backtrack(board, {x+1, y}, visit, word, idx+1) ) {
                return true;
            }
            visit[x+1][y] = false;
        } 
        if (x-1 >= 0 && board[x-1][y] == word[idx] && !visit[x-1][y]) {
            visit[x-1][y] = true;
            if (true == backtrack(board, {x-1, y}, visit, word, idx+1) ) {
                return true;
            }
            visit[x-1][y] = false;
        } 

        if (y+1 < n && board[x][y+1] == word[idx] && !visit[x][y+1]) {
            visit[x][y+1] = true;
            if (true == backtrack(board, {x, y+1}, visit, word, idx+1)) {
                return true;
            }
            visit[x][y+1] = false;
        }
        if (y-1 >= 0 && board[x][y-1] == word[idx] && !visit[x][y-1]) {
            visit[x][y-1] = true;
            if (true == backtrack(board, {x, y-1}, visit, word, idx+1)) {
                return true;
            }
            visit[x][y-1] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<std::pair<int, int>> record;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == word[0]) {
                    record.push_back({i, j});
                }
            }
        }

        if (word.length() == 1) {
            return !record.empty(); 
        }
        for (auto p: record) {
            vector<vector<int>> visit(m, vector<int>(n, 0));
            visit[p.first][p.second] = true;
            if (backtrack(board, p, visit, word, 1) == true) {
                return true;
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
