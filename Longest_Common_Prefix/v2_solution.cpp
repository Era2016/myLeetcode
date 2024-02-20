#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int sz = strs.size();
        if (sz == 0) return "";

		string prefix;
		int minLen = INT_MAX;
		for (const auto& str: strs) {
			minLen = std::min(minLen, (int)str.length());
		}

		for (int i = 0; i < minLen; i ++) {
			int cnt = 1;
			char c = strs[0][i];
			for (int j = 1; j < sz; j ++) {
				if (strs[j][i] == c) {
					cnt ++;
				}
			}
			if (cnt == sz) {
				prefix += c;
			} else {
				break;
			}
		}
		return prefix;
	}
};

int main() {
    Solution *so = new Solution();
    vector<string> strs;

    strs = {"flower","flow","flight"};
    std::cout << so->longestCommonPrefix(strs) << std::endl;

    strs = {"dog","racecar","car"};
    std::cout << so->longestCommonPrefix(strs) << std::endl;

    strs = {};
    std::cout << so->longestCommonPrefix(strs) << std::endl;
}
