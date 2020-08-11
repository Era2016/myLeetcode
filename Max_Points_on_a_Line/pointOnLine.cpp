//c++ 17

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric> // gcd
#include <sstream> // stringstream

using namespace std;

class Solution {
public:
	// 存在精度问题
	int maxPoints1(vector<vector<int>>& points) {
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

    int maxPoints2(vector<vector<int> >& points) {
	    int result = 0;
	    for(int i = 0; i < (int)points.size(); i++ ) {
	        int samePoint = 0;
	        int overFlowSlope = 0;
	        int curMax = 0;
	        unordered_map<string,int> map;
	        for(int j = i+1; j < (int)points.size(); j++ ) {
	            if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
	                samePoint ++;
	            else if(points[i][0] == points[j][0])
	                overFlowSlope ++;
	            else{
	                int yDif = points[i][1] - points[j][1];
	                int xDif = points[i][0] - points[j][0];
	                int g = gcd(yDif, xDif);
	                yDif /= g;
	                xDif /= g;
	                if (xDif < 0) { // 此处只能用xDif 来判断
	                    yDif = -yDif;
	                    xDif = -xDif;
	                }

	                stringstream str;
	                str<< yDif << "," << xDif;
	                cout << str.str() << endl;
	                map[str.str()] ++;
	                curMax = max(curMax, map[str.str()]);
	            }
	            curMax = max(curMax, overFlowSlope);
	        }
	        result = max(result, curMax+samePoint+1);
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
	vector<vector<int> > vv7 = {{4, 0}, {4, -1}, {4, 5}};
	vector<vector<int> > vv8 = {{2, 3}, {3, 3}, {-5, 3}};

	Solution* so = new Solution();
	cout << so->maxPoints2(vv1) << endl;
	cout << so->maxPoints2(vv2) << endl;
	cout << so->maxPoints2(vv3) << endl;
	cout << so->maxPoints2(vv4) << endl;
	cout << so->maxPoints2(vv5) << endl;
	cout << so->maxPoints2(vv6) << endl;
	cout << so->maxPoints2(vv7) << endl;
	cout << so->maxPoints2(vv8) << endl;
}
