#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    int leftBound(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = (high-low)/2 + low;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (low >= nums.size() || nums[low] != target) {
            return -1;
        }
        return low;
    }

    int rightBound(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = (high-low)/2 + low;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (high < 0 || nums[high] != target) {
            return -1;
        }
        return high;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftBound(nums, target, 0, nums.size()-1);
        int right = rightBound(nums, target, 0, nums.size()-1);
        return {left, right};
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v, res;
    int target;
    auto print=[](vector<int>& nums) {
        for (const auto& num: nums) {
            std::cout << num << "\t";
        }
        std::cout << std::endl;
    };

    target = 8;
    v = {5,7,7,8,8,10};
    res = so->searchRange(v, target);
    print(res);

    target = 6;
    res = so->searchRange(v, target);
    print(res);

    target = 0;
    v = {};
    res = so->searchRange(v, target);
    print(res);
}
