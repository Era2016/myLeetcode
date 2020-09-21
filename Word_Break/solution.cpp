#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // time out: 2的n次方复杂度
    bool wordBreak2(string s, vector<string>& wordDict) {
		if (s.length() == 0) {
			return true;
		}

		unordered_set<string> uset(wordDict.begin(), wordDict.end());

 		for (int i = 1; i <= (int)s.length(); i ++) {
			string slice = s.substr(0, i); // substr -> [0,i)
			unordered_set<string>::iterator iter = uset.find(slice);
			if (iter != uset.end() && wordBreak2(s.substr(i), wordDict)) {
                return true;
            }

            // also works 
			/*if (iter != uset.end()) {
				return wordBreak2(s.substr(i), wordDict);
			}*/
		}       
		return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end()); 
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;

        for (int i = 1; i <= (int)s.length(); i ++) {
            for (int j = 0; j < i; j ++) {
                string slice = s.substr(j, i);
                unordered_set<string>::iterator iter = uset.find(slice);
                if (dp[j] == true && iter != uset.end()) {
                    dp[i] = true; break;
                }
            }
        }
        return dp[s.length()];
    }
};

int main() {
	Solution* so = new Solution();
	vector<string> v = {"leet", "code"};
	bool val = true;
	string str = "leetcode";
	val = so->wordBreak(str, v);
	cout << val << endl;

    v = {"apple", "pen"};
    str = "applepenapple";
	val = so->wordBreak(str, v);
	cout << val << endl;

    v = {"cats", "dog", "sand", "and", "cat"};
    str = "catsandog";
	val = so->wordBreak(str, v);
	cout << val << endl;
}
