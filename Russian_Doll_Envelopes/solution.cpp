#include <algorithm>
#include <iostream>
#include <sys/errno.h>
#include <vector>
#include <cassert>

using std::vector;
class Solution {
public:
    // timeout
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto cmp=[](vector<int>& v1, vector<int>& v2) {
            if (v1[0] < v2[0]) {
                return true;
            } else if (v1[0] == v2[0] && v1[1] > v2[1]) {
                return true;
            }
            return false;
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(envelopes.size(), 1);
        int maxLength = 1;
        for (int i = 0; i < envelopes.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
            maxLength = std::max(maxLength, dp[i]);
        }
        return maxLength;
    }

    int maxEnvelopes_v2(vector<vector<int>>& envelopes) {
        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] != v2[0]) {
                return v1[0] < v2[0];
            }
            return v1[1] > v2[1];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp;
        dp.emplace_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i ++) {
            if (dp.back() < envelopes[i][1]) {
                dp.emplace_back(envelopes[i][1]);
            } else {
                auto it = std::lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        return dp.size();
    }
};

int main () {
    Solution *so = new Solution();
    vector<vector<int>> vv;
    
    vv = {{5,4},{6,4},{6,7},{2,3}};
    assert(so->maxEnvelopes_v2(vv) == 3);

    vv = {{1,1},{1,1},{1,1}};
    assert(so->maxEnvelopes_v2(vv) == 1);
}
