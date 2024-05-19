#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_set;
using std::unordered_map;
struct TrieNode {
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() { this->word = ""; };
};

void insertTrie(TrieNode* root, string str) {
    TrieNode *node = root;
    for (auto& c: str) {
        if (root->children.count(c) == 0) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = str;
}

class Solution {
private:
    bool backtrack(vector<vector<char>>& board, TrieNode* root,
                    int row, int col, unordered_set<string>& res) {

        char ch = board[row][col];
        int m = board.size(), n = board[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || ch == '.') return false;

        if (root == nullptr || !root->children.count(ch)) return false;

        TrieNode *nxt = root->children[ch];
        if (nxt->word.size() > 0) {
            res.insert(nxt->word);
            nxt->word = "";
        }

        bool ret = false;
        if (!nxt->children.empty()) {
            board[row][col] = '.';
            ret = backtrack(board, nxt, row-1, col, res) ||
                  backtrack(board, nxt, row+1, col, res) ||
                  backtrack(board, nxt, row, col-1, res) ||
                  backtrack(board, nxt, row, col+1, res);
            board[row][col] = ch;
        }

        if (nxt->children.empty()) {
            root->children.erase(ch);
        }
        return ret;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, 
            vector<string>& words) {

        TrieNode *root = new TrieNode();
        unordered_set<string> res;
        for (auto &word: words) {
            insertTrie(root, word);
        }

        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                backtrack(board, root, i, j, res);
            }
        }

        return {res.begin(), res.end()};
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

    board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    words = {"oath","pea","eat","rain"};
    res = so->findWords(board, words);
    print();

    board = {{'a','b'},{'c','d'}};
    words = {"abcb"};
    res = so->findWords(board, words);
    print();
}
