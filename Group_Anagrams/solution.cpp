#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (const auto& str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if (um.find(tmp) != um.end()) {
                um[tmp].push_back(str);
            } else {
                um[tmp] = {str};
            }
        }

        vector<vector<string>> res;
        for (auto v: um) {
            res.push_back(v.second);
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> strs;
    vector<vector<string>> res;
    auto print=[&]() {
        for (const auto& arr: res) {
            for (const auto& val: arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    };

    strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    res = so->groupAnagrams(strs);
    print();

    strs = {"eat"}; 
    res = so->groupAnagrams(strs);
    print();

    strs = {""}; 
    res = so->groupAnagrams(strs);
    print();
}
