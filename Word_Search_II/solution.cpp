#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

class Solution {
private:
    bool backtrack(vector<vector<char>>& board, string& str, int row, int col,
                   int idx) {
        int m = board.size(), n = board[0].size();
        if (row >= m || col >= n || row < 0 || col < 0 ||
            board[row][col] != str[idx])
            return false;
        if (idx == str.length()-1)
            return true;

        board[row][col] = '.';
        bool ret = backtrack(board, str, row - 1, col, idx + 1) ||
                   backtrack(board, str, row + 1, col, idx + 1) ||
                   backtrack(board, str, row, col - 1, idx + 1) ||
                   backtrack(board, str, row, col + 1, idx + 1);
        board[row][col] = str[idx];
        return ret;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        unordered_set<string> filter;
        int m = board.size(), n = board[0].size();
        for (auto word : words) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (backtrack(board, word, i, j, 0)) {
                        // res.push_back(word);
                        filter.insert(word);
                    }
                }
            }
        }
        return {filter.begin(), filter.end()};
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<char>> board;
    vector<string> words, res;
    auto print=[&]() {
        for (auto str: res) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    };

    // 不分测试用例超时
    // 所有单元格都是 a 的二维字符网格和单词列表 ["a", "aa", "aaa", "aaaa"]

    board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    words = {"oath","pea","eat","rain"};
    res = so->findWords(board, words);
    print();

    board = {{'a','b'},{'c','d'}};
    words = {"abcb"};
    res = so->findWords(board, words);
    print();
}
