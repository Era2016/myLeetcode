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
            int mid = (right-left)/2 + left;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        if (left == nums.size()) return -1;
        return nums[left] == target? left: -1;
    }

    int rightBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (right-left)/2 + left;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] <= target) {
                left = mid + 1;
            }
        }
        
        if (right < 0) return -1;
        return nums[right] == target? right: -1;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v, ret;
    auto print=[](vector<int>& v) {
        for (auto i: v) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
    };

    v = {5,7,7,8,8,10};
    ret = so->searchRange(v, 8);
    print(ret);

    v = {5,7,7,8,8,10};
    ret = so->searchRange(v, 6);
    print(ret);

    v = {}; 
    ret = so->searchRange(v, 0);
    print(ret);
}
