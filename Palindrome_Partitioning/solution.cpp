#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
    	vector<vector<string> > result;
		vector<string> currentList;
		dfs(result, 0, s, currentList);
		return result;
	}
private:
	void dfs(vector<vector<string> >& result, int start, string& s, vector<string>& currentList) {
        if (start >= (int)s.length()) result.push_back(currentList);
        for (int end=start; end < (int)s.length(); end ++) {
            if (isPalindrome(s, start, end)) {
                currentList.push_back(s.substr(start, end-start+1));
                dfs(result, end+1, s, currentList);
                currentList.pop_back();
            }
        }
	}

	bool isPalindrome(string str, int start, int end) {
		while (start < end) {
			if (str[start++] != str[end--]) return false;
		}	
		return true;
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
