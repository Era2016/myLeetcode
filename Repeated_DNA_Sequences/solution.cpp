#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::string;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<int> nums = transform(s);
        //auto print = [] (vector<int> v) { for (auto str: v) std::cout << str;  std::cout << std::endl; };
        //print (nums);

        unordered_map<int, int> window;
        unordered_set<string> filter;
        vector<string> res;

        int left = 0, right = 0;
        int L = 10; // 数字位数
        int R = 4; // 进制
        int RL = pow(R, L-1); // 存储 R^(L - 1) 的结果

        int hash = 0;

        while (right < nums.size()) {
            hash = hash*R + nums[right ++]; 

            if (right - left == L) {
                if (window.count(hash)) {
                    filter.insert(s.substr(left, right-left));
                    //std::cout << s.substr(left, right-left) << std::endl;
                } else {
                    window[hash] ++;
                }

                hash = hash - RL*nums[left ++];
            }
        }
        for (auto k: filter) res.push_back(k);
        return res;
    }

    vector<int> transform(string s) {
        vector<int> v(s.size());
        for (int i = 0; i < s.size(); i ++) {
            switch (s[i]) {
                case 'A':
                    v[i] = 0;
                    break;
                case 'C':
                    v[i] = 1;
                    break;
                case 'G':
                    v[i] = 2;
                    break;
                case 'T':
                    v[i] = 3;
                    break;
            }
        } 
        return v;
    }
};

int main() {
    Solution* so = new Solution();
    vector<string> v;

    auto print = [] (vector<string> v) { for (auto str: v) std::cout << str << std::endl; std::cout << std::endl; };
    v = so->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    print(v);

    v = so->findRepeatedDnaSequences("AAAAAAAAAAAAA");
    print(v);
}
