#include <iostream>
#include <vector>

using std::vector;
using std::max;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        sort(points.begin(), points.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int tmp = 0;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dy = y1 - y2, dx = x1 - x2;
                for(auto& p : points) {
                    if(dy * (p[0] - x1) == dx * (p[1] - y1)) tmp++;
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
