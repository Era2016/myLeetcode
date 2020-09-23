#include <iostream>
#include <vector>
#include <unordered_set>

//basic_string substr (size_type pos = 0, size_type len = npos) const;
using namespace std;

class Solution {
public:
    // time out: 2的n次方复杂度
    bool wordBreak1(string s, vector<string>& wordDict) {
		if (s.length() == 0) {
			return true;
		}

		unordered_set<string> uset(wordDict.begin(), wordDict.end());

 		for (int i = 1; i <= (int)s.length(); i ++) {
			string slice = s.substr(0, i); // substr -> [0,i); i means count
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

    // before optimize
    bool wordBreak2(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end()); 
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;

        for (int i = 1; i <= (int)s.length(); i ++) {
            for (int j = 0; j < i; j ++) {
                string slice = s.substr(j, i-j);
                //cout << "i: " << i << " j: " << j << " slice: " << slice << endl;
                unordered_set<string>::iterator iter = uset.find(slice);
                if (dp[j] == true && iter != uset.end()) {
                    dp[i] = true; 
                    //cout << "index: " << i << " flag: " << j << " slice: " << slice << endl;
                    break;
                }
            }
        }
        return dp[s.length()];
    }

    // after optimize: 
    // 减少查询次数，以字典中最长word为准；
    // 优先判断之前计算结果，然后再查找
    bool wordBreak3(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end()); 
        int longestWord = 0;
        for (string word: uset) {
            longestWord = max(longestWord, (int)word.length()); 
        }

        vector<bool> dp(s.length()+1, false);
        dp[0] = true;

        for (int i = 1; i <= (int)s.length(); i ++) {
            for (int j = i-1; j >= max(0, i-longestWord); j --) {
                if (dp[j] == true) {
                    string slice = s.substr(j, i-j);
                    //cout << "i: " << i << " j: " << j << " slice: " << slice << endl;
                    unordered_set<string>::iterator iter = uset.find(slice);
                    if (iter != uset.end()) {
                        dp[i] = true; 
                        //cout << "index: " << i << " flag: " << j << " slice: " << slice << endl;
                        break;
                    }
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
	val = so->wordBreak3(str, v);
	cout << val << endl << endl;

    v = {"apple", "pen"};
    str = "applepenapple";
	val = so->wordBreak3(str, v);
	cout << val << endl << endl;

    v = {"cats", "dog", "sand", "and", "cat"};
    str = "catsandog";
	val = so->wordBreak3(str, v);
	cout << val << endl << endl;
}
