#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            } else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            } else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> newInterval;
    vector<vector<int>> intervals, result;

    auto print=[](vector<vector<int>>& arr){
        for (const auto& aa: arr) {
            cout << "[ ";
            for (const auto& b: aa) {
                cout << b << " ";
            }
            cout << "] ";
        }
        cout << endl;
    };
    intervals = {{1,3},{6,9}};
    newInterval = {2,5};
    result = so->insert(intervals, newInterval);
    print(result);

    intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    newInterval = {4,8};
    result = so->insert(intervals, newInterval);
    print(result);

    intervals = {};
    newInterval = {5,7};
    result = so->insert(intervals, newInterval);
    print(result);

    intervals = {{1,5}};
    newInterval = {2,3};
    result = so->insert(intervals, newInterval);
    print(result);

    intervals = {{1,5}};
    newInterval = {2,7};
    result = so->insert(intervals, newInterval);
    print(result);

    intervals = {{1,5}};
    newInterval = {6,8};
    result = so->insert(intervals, newInterval);
    print(result);

    intervals = {{6,8}};
    newInterval = {1,5};
    result = so->insert(intervals, newInterval);
    print(result);

    intervals = {{1,2}, {5,6}};
    newInterval = {3,4};
    result = so->insert(intervals, newInterval);
    print(result);

    intervals = {{1,5}};
    newInterval = {0,3};
    result = so->insert(intervals, newInterval);
    print(result); 
}