#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int mid, left = 0, right = length - 1;
        bool find = false;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] > nums[left] && nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
                right = mid - 1;
            } else if (nums[mid] > nums[left] && nums[mid] < nums[right]) {
                return -1;
            } else { // nums[mid] = nums[left] = nums[right]
                int i = left - 1;
                while (i >= 0 && nums[left] == nums[i]) { i --; }
                mid = i;
            }
        }
        
        if (nums[mid] == target) return mid;
        return -1;
    }    
};

int main() {
    vector<int> v = {3,4,5,6,0,1,2};
    int target = 0;
    Solution* so = new Solution();
    cout << so->search(v, target) << endl;
}
