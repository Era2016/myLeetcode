#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // time out: 2的n次方复杂度
    bool wordBreak(string s, vector<string>& wordDict) {
		if (s.length() == 0) {
			return true;
		}

		unordered_set<string> uset(wordDict.begin(), wordDict.end());

 		for (int i = 1; i <= (int)s.length(); i ++) {
			string slice = s.substr(0, i); // substr -> [0,i)
			unordered_set<string>::iterator iter = uset.find(slice);
			if (iter != uset.end() && wordBreak(s.substr(i), wordDict)) {
                return true;
            }

            // also works 
			/*if (iter != uset.end()) {
				return wordBreak(s.substr(i), wordDict);
			}*/
		}       
		return false;
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
