#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::string;

class Solution {
private:
    vector<string> res;
    void backtrack(string s, int idx, unordered_set<string>& us, vector<string>& v) {
        if (idx == s.length()) {
            string tmp = ""; 
            for (const auto& s: v) {
                tmp += s + " ";
            }
            tmp.erase(tmp.length()-1, 1);
            res.push_back(tmp);
            return;
        }

        for (int len = 1; len <= s.length()-idx; len ++) {
            if (us.find(s.substr(idx, len)) != us.end()) {
                v.emplace_back(s.substr(idx, len));
                backtrack(s, idx+len, us, v);
                v.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        res.clear();
        vector<string> v;
        backtrack(s, 0, us, v);
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> v, res;
    auto print=[](vector<string>& vv) {
        for (auto v: vv) {
            std::cout << v << std::endl;
        }
        std::cout << std::endl;
    };

    v = {"cat","cats","and","sand","dog"};
    res = so->wordBreak("catsanddog", v);
    print(res);

    v = {"apple","pen","applepen","pine","pineapple"}; 
    res = so->wordBreak("pineapplepenapple", v);
    print(res);

    v = {"cats","dog","sand","and","cat"}; 
    res = so->wordBreak("catsandog", v);
    print(res);
}
