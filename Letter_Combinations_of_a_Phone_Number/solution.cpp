#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> res;
            if (digits.empty()) {
                return res;
            }            
            string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            letterCombinationsDFS(digits, dict, 0, "", res);
            return res;
        }
        void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string>& res) {
            if (level == (int)digits.size()) {
                res.push_back(out);
            } else {
                string str = dict[digits[level] - '2'];
                for (int i = 0; i < (int)str.size(); ++ i) {
                    out.push_back(str[i]);
                    letterCombinationsDFS(digits, dict, level + 1, out, res);
                    out.pop_back();
                }
            }
        }

        vector<string> letterCombinations_v2(string digits) {
	        vector<string> res;
	        if (digits.empty()) 
	        	return res;
	        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	        res.push_back("");
	        for (int i = 0; i < digits.size(); ++i) {
	            int length = res.size();
	            string str = dict[digits[i] - '2'];
	            for (int j = 0; j < length; ++j) {
	                string tmp = res.front();
	                res.erase(res.begin());
	                for (int k = 0; k < str.size(); ++k) {
	                    res.push_back(tmp + str[k]);
	                }
	            }
        }
        return res;
    }
};

int main()
{
    Solution* so = new Solution();
    string str = "234";
    vector<string> v = so->letterCombinations(str);
    int count = 0;
    for (vector<string>::iterator iter = v.begin(); iter != v.end(); ++ iter) {
        cout << *iter << endl;
        count ++;
    }
    cout << "total count: " << count << endl;
    return 0;
}
