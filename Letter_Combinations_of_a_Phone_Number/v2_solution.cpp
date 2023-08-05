#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
private:
    vector<string> res;
    unordered_map<char, string> um;
    void init() {
        um = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        res.clear();
    }

    void backtrack(string digits, string& target, int idx) {
        if (target.length() == digits.length()) {
            res.push_back(target);
            return;
        }

        for (int i = idx; i < digits.length(); i ++) {// 该层循环可有可无
            string curStr = um[digits[i]];
            for (int j = 0; j < curStr.length(); j ++) {
                target += curStr[j];
                backtrack(digits, target, i+1); 
                target = target.substr(0, target.length()-1);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        init(); 
        string target = "";
        if (digits.empty()) return {};
        backtrack(digits, target, 0);
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> res;
    string s;
    auto print=[](vector<string>& res) {
        for (const auto& v: res) {
            std::cout << v << "\t";
        }
        std::cout << std::endl << std::endl;
    };

    s = "23";
    res = so->letterCombinations(s);
    print(res);

    s = "";
    res = so->letterCombinations(s);
    print(res);

    s = "2";
    res = so->letterCombinations(s);
    print(res);
}
