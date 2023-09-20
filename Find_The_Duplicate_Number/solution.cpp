#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int binarySearch(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int ans = 0;
        while (low <= high) {
            int mid = (high-low)/2 + low;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i ++) {
                if (nums[i] <= mid) cnt ++;
            }

            if (cnt <= mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
public:
    int findDuplicate(vector<int>& nums) {
        return binarySearch(nums);
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {1,3,4,2,2};
    std::cout << so->findDuplicate(nums) << std::endl;

    nums = {3,1,3,4,2};
    std::cout << so->findDuplicate(nums) << std::endl;
}
