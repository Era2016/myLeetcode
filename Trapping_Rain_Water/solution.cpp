#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxS = 0, s = 0;

        while (left < right) {
            s = (right - left) * min(height[left], height[right]);
            maxS = max(s, maxS);
            if (height[left] <= height[right]) {
                left ++;
            } else {
                right --;
            } 
        }
        return maxS;
    }
};

int main() {
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    Solution* so = new Solution();
    cout << so->maxArea(v) << endl;   
}
