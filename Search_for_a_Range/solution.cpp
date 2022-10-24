#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftBound(nums, target);
        int right = rightBound(nums, target);
        return {left, right};
    }

    int leftBound(vector<int>& nums, int target) {

        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }

        if (left == nums.size()) return -1;
        return (nums[left] == target)? left: -1;
    }

    int rightBound(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }

        if (left - 1 < 0) return -1;
        return (nums[left-1] == target)? left-1: -1;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    auto print = [](vector<int> v) { for(auto i: v) std::cout << i << "\t"; std::cout << std::endl << std::endl; };
    
    v = {5,7,7,8,8,10};
    v = so->searchRange(v, 8);
    print(v);


    v = {5,7,7,8,8,10};
    v = so->searchRange(v, 6);
    print(v);


    v = {};
    v = so->searchRange(v, 0);
    print(v);
}
