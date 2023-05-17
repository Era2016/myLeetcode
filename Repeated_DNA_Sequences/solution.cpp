#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<int> nums(s.length(), 0);
        int cnt = 0;
        for (const auto& c: s) {
            if (c == 'A') nums[cnt ++] = 0;
            if (c == 'G') nums[cnt ++] = 1;
            if (c == 'C') nums[cnt ++] = 2;
            if (c == 'T') nums[cnt ++] = 3;
        }
        
        int L = 10;
        int R = 4;
        int RL = pow(R, L-1); 
        int windowHash = 0;

        unordered_set<string> ret;
        unordered_set<int> seen;
        int left = 0, right = 0;
        while (right < s.length()) {
            windowHash = R * windowHash + nums[right ++];
            if (right - left == L) {
                if (seen.count(windowHash)) {
                    ret.insert(s.substr(left, right-left));
                } else {
                    seen.insert(windowHash);
                }

                windowHash = windowHash - nums[left ++]*RL;
            }
        }
        return vector<string>(ret.begin(), ret.end());
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> res;
    auto print = [] (vector<string> v) { 
        for (auto str: v) 
            std::cout << str << "\t";  
        std::cout << std::endl; 
    };

    res = so->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    print(res);

    res = so->findRepeatedDnaSequences("AAAAAAAAAAAAA");
    print(res);
}
