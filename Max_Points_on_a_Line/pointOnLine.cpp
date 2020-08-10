#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

	// 存在精度问题
	int maxPoints(vector<vector<int>>& points) {
        int result = 0;
        for(int i = 0; i < (int)points.size(); i++){
            int samePoint = 1;
            unordered_map<double, int> map;
            for(int j = i + 1; j < (int)points.size(); j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                    samePoint++;
                }
                else if(points[i][0] == points[j][0]){
                    map[INT_MAX]++;
                }
                else{
                    double slope = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                    map[slope]++;
                }
            }
            int localMax = 0;
            for(auto it = map.begin(); it != map.end(); it++){
                localMax = max(localMax, it->second);
            }
            localMax += samePoint;
            result = max(result, localMax);
        }
        return result;
    }
};

int main() {
	vector<vector<int> > vv1 = {{1, 1}, {2, 2}, {3, 3}};
	vector<vector<int> > vv2 = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
	vector<vector<int> > vv3 = {{0, 0}};
	vector<vector<int> > vv4 = {};
	vector<vector<int> > vv5 = {{3, 10}, {0, 2}, {0, 2}, {3, 10}};
	vector<vector<int> > vv6 = {{0,0},{94911151,94911150},{94911152,94911151}};

	Solution* so = new Solution();
	cout << so->maxPoints(vv1) << endl;
	cout << so->maxPoints(vv2) << endl;
	cout << so->maxPoints(vv3) << endl;
	cout << so->maxPoints(vv4) << endl;
	cout << so->maxPoints(vv5) << endl;
	cout << so->maxPoints(vv6) << endl;
}
