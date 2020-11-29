#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool> > dp(len, vector<bool>(len, false));
    	vector<vector<string> > result;
		vector<string> currentList;
		dfs(result, 0, s, currentList, dp);
		return result;
	}
private:
	void dfs(vector<vector<string> >& result, int start, string& s, 
            vector<string>& currentList, vector<vector<bool> >& dp) {
        if (start >= (int)s.length()) result.push_back(currentList);
        for (int end=start; end < (int)s.length(); end ++) {
            if (s[start] == s[end] && (end-start <= 2 || dp[start+1][end-1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end-start+1));
                dfs(result, end+1, s, currentList, dp);
                currentList.pop_back();
            }
        }
	}
};

void print(vector<vector<string> > vv) {
    for (vector<vector<string> >::iterator it=vv.begin();
            it != vv.end(); it ++) {
        for (vector<string>::iterator i=it->begin(); i != it->end(); i ++) {
            cout << *i << "\t";
        }
        cout << endl;
    }
}

int main() {
    Solution* so = new Solution();
    vector<vector<string> > res;
    res = so->partition("aab");
    print(res);
}
