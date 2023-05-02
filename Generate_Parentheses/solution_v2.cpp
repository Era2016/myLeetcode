#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Solution {
private:
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n*2) {
            ans.push_back(cur);
            return;
        }

        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open+1, close, n);
            cur.pop_back();
        }
        
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close+1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {        
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};

int main()
{
    Solution* so = new Solution();
    vector<string> v = so->generateParenthesis(3);
    for (vector<string>::iterator iter = v.begin(); iter != v.end(); ++ iter) {
        cout << * iter << endl;
    }
    return 0;
}
