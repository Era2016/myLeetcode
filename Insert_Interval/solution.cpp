#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }
        int first = newInterval[0], second = newInterval[1];
        vector<vector<int>> result;
        int start = -1, end = -1;
        for (int i = 0; i < intervals.size(); i ++) {
            // if (intervals[i][0] > first) {
            //     start = i;
            // }
            if (intervals[i][0] <= first && intervals[i][1] >= first) {
                start = i;
                if (intervals[i][1] < second) {
                    end = i;
                } else if (intervals[i][1] >= second) {
                    end = i; 
                    break;
                }
            } 
            if (intervals[i][0] <= second && intervals[i][1] >= second) {
                end = i;
                break;
            }
        }
        cout << "start: " << start << "; end: " << end << endl;
        vector<int> merge;
        bool hasInsert = false;
        for (int i = 0; i < intervals.size(); i ++) {
            if (i >= start && i <= end) {
                if (i == start) {
                    merge.push_back(min(intervals[i][0], start));
                }
                if (i == end) {
                    merge.push_back(max(intervals[i][1], second));
                }
                if (merge.size() == 2) {
                    result.push_back(merge);
                    merge.clear();
                    hasInsert = true;
                }
            } else {
                if (start == -1 && first < intervals[i][0]) {
                    result.push_back(newInterval);
                    hasInsert = true;
                }
                result.push_back(intervals[i]);
            }
        }

        if (!hasInsert) {
            result.push_back(newInterval);
        }

        return result;
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

    // error
    intervals = {{1,5}};
    newInterval = {0,3};
    result = so->insert(intervals, newInterval);
    print(result); 
}