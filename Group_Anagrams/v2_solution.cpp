#include <array>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <functional>

using std::vector;
using std::string;
using std::unordered_map;
using std::hash;
using std::accumulate;
using std::array;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = std::hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return std::accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
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
