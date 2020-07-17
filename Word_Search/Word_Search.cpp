#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution2 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                // traverse the board to find the first char
                if (dfsSearch(board, word, 0, i, j)) return true;
        return false;
    }
private:
    int m;
    int n;
    bool dfsSearch(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || word[k] != board[i][j]) return false;
        if (k == (int)word.length() - 1) return true;  // found the last char

        char cur = board[i][j];
        board[i][j] = '*';  // used
        bool search_next = dfsSearch(board, word, k+1, i-1 ,j) 
                        || dfsSearch(board, word, k+1, i+1, j) 
                        || dfsSearch(board, word, k+1, i, j-1)
                        || dfsSearch(board, word, k+1, i, j+1);
        board[i][j] = cur;  // reset
        return search_next;
    }
};


class Solution{
    public:
        bool exist(vector<vector<char> >& board, string word) {
            for (int i = 0; i < (int)board.size(); i ++) {
                for (int j = 0; j < (int)board[0].size(); j ++) {
                    if (isExist(board, i, j, word)) {
                        return true;
                    }
                }
            }

            return false;
        }

    private:
        // dfs algo
        bool isExist(vector<vector<char> >&vv, int i, int j, string word) {
            if (word.length() == 0) {
                return true;
            }

            if (i < 0 || i >= (int)vv.size() || 
                    j < 0 || j >= (int)vv[0].size() || 
                    vv[i][j] != word[0]) {
                return false;
            } 

            char tmpV = vv[i][j];
            vv[i][j] = '#';
            
            bool res = isExist(vv, i-1, j, word.substr(1)) || 
                isExist(vv, i, j-1, word.substr(1)) || 
                isExist(vv, i+1, j, word.substr(1)) ||
                isExist(vv, i, j+1, word.substr(1));

            vv[i][j] = tmpV;
            return res;
        }

};

int main() {
    //Solution* so = new Solution();
    Solution2* so = new Solution2(); // more efficient
    vector<vector<char> > vv = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'},
    };

    //string word = "ABCCED";
    //bool found = so->exist(vv, word);
    //cout << "string:\t" << word << endl;
    //cout << "result:\t" << found << endl; 
    vector<string> word = {"ABCCED", "SEE", "ABCB"}; 
    for (int i = 0; i < (int)word.size(); i ++) {
        bool found = so->exist(vv, word[i]);
        cout << "string:\t" << word[i] << endl;
        cout << "result:\t" << found << endl; 
    }
}
