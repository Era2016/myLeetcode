#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int search (vector<int>& nums, int target) {
            int start = 0;
            int end = nums.size() - 1;
            int index = -1;

            while (start <= end) {
                int mid = (start + end) / 2;
                if (nums[mid] == target) {
                    index = mid;
                    break;
                }
                // 左半段有序，中间值位于递增阶段
                if (nums[start] <= nums[mid]) {
                    if (nums[start] <= target && target < nums[mid]) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                } else { // 右半段有序
                    if (nums[mid] < target && target <= nums[end]) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }
            return index;
        }

        int search_v2(vector<int>& nums, int target) {
            if (nums.size() == 0) return -1;
            if (nums.size() == 1) return nums[0] == target ? 0 : -1;

            int ns = nums.size();
            int low, high;
            low = 0;
            high = ns - 1;

            while (low < high - 1) {
                int mid = (low + high) / 2;

                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[mid] < target) {
                    if (nums[high] < nums[mid]) {
                        low = mid + 1;
                    }
                    else if (target > nums[high]) {
                        high = mid - 1;
                    } 
                    else if (target == nums[high]) {
                        return high;
                    } 
                    else {
                        low = mid + 1;
                    }
                }
                else {
                    if (nums[mid] < nums[low]) {
                        high = mid - 1;
                    }
                    else if (nums[low] > target) {
                        low = mid + 1;
                    }
                    else if (nums[low] == target) {
                        return low;
                    }
                    else {
                        high = mid - 1;
                    }

                }
            }

            if (nums[low] == target) return low;
            if (nums[high] == target) return high;

            return -1;
        }
};

int main()
{
    Solution* so = new Solution();
    std::vector<int> v;
    int temp = 0;
    while (true) {
        cin >> temp;
        if (temp == -1) {
            break;
        } else {
            v.push_back(temp);
        }
    }

    int target = 0;
    cin >> target;
    int result = so->search(v, target);
    cout << result << endl;
    return 0;
}
