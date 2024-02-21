#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0, right = height.size()-1;
        while (left < right) {
            int tArea = std::min(height[left], height[right]) * (right-left); 
            area = std::max(area, tArea);
            if (height[left] <= height[right]) {
                left ++;
            } else {
                right --;
            }
        }
        return area;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> height;

    height = {1,8,6,2,5,4,8,3,7};
    std::cout << so->maxArea(height) << std::endl; // 49

    height = {1,1};
    std::cout << so->maxArea(height) << std::endl; // 1
}
