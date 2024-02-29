#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp=[](vector<int> a, vector<int> b) {
            return a.at(0) < b.at(0);
        };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = std::max(merged.back()[1], R);
            }
        }
        return merged;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> intervals, res;
    auto print=[&]() {
        for (const auto& v: res) {
            for (const auto& val: v) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    };

    intervals = {{1,3},{2,6},{8,10},{15,18}};
    res = so->merge(intervals);
    print();

    intervals = {{1,4},{4,5}};
    res = so->merge(intervals);
    print();
}
