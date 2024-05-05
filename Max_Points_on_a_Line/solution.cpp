#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::string;
class Solution {
public:
    int maxPoint(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int res = 0;
        for (int i = 0; i < n; i ++) {
            if (res >= n-i || res > n/2) {
                return res;
            }

            unordered_map<string, int> um;
            for (int j = i+1; j < n; j ++) {

                int dx = points[i][0]-points[j][0];
                int dy = points[i][1]-points[j][1];
                //std::cout << "[" << dx << ", " << dy << "], ";
                if (dx == 0) {
                    dy = 1;    
                } else if (dy == 0) {
                    dx = 1;
                } else {
                    if (dy < 0) {
                        dx = -dx; dy = -dy;
                    }

                    int gcdxy = std::gcd(dx, dy);
                    dx = dx/gcdxy;
                    dy = dy/gcdxy;
                }
                
                string str = std::to_string(dx)+"."+std::to_string(dy);
                //std::cout << i << ":" << ">>>" << str << "<<<" << std::endl;
                um[str]++;
            }

            int currRes = 0;
            for (auto [_, num]: um) {
                currRes = std::max(currRes, num+1); 
            }

            res = std::max(res, currRes);
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> points;

    points = {{1,1},{2,2},{3,3}};
    std::cout << so->maxPoint(points) << std::endl;

    points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    std::cout << so->maxPoint(points) << std::endl;
}
