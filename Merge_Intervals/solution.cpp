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

        vector<vector<int>> res;
        int left = intervals[0].at(0), right = intervals[0].at(1);
        int tLeft = left, tRight = right;
        for (int i = 1; i < intervals.size(); i ++) {
            tLeft = intervals[i][0], tRight = intervals[i][1]; 
            if (tLeft <= right && tRight >= right) {
                right = tRight;
            } else if (tLeft > right) {
                res.push_back({left, right});
                left = tLeft;
                right = tRight;
            }
        }

        if (res.empty()) {
            res.push_back({left, right});
        } else {
            auto v = res.back();
            if (v[0] != left) {
                res.push_back({left, right});
            }
        }
        return res;
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
