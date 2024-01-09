#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::string;

class Solution {
private:
    unordered_map<string, vector<string>> memo; 
    vector<string> dp(string s, unordered_set<string>& us, int idx) {
        if (s.length() == idx) {
            return {""};
        }

        vector<string> res;
        for (int len = 1; len <= s.length()-idx; len ++) {
            string s_string = s.substr(idx, len);
            if (us.find(s_string) != us.end()) {
                if (memo.count(s_string)) {
                    return memo[s_string];
                }
                vector<string> sub = dp(s, us, idx+len);
                for (auto& s: sub) {
                    res.push_back(s_string + (s.empty()? "": " "+s)); 
                }
            }
        }
       
        memo[s] = res;
        return memo[s];
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->memo.clear();
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        vector<string> res = dp(s, us, 0);
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
