#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 遍历数组，找到从后算递增的第一个数组下标
        // 选择该下标后数组中刚刚大于该数组下标值，交换元素
        // 交换后，将后面数组按升序排列
        int length = nums.size();
        int index = length - 1;
        for (int i = length - 1; i >= 0; i --) {
            if (i >= 1 && nums[i] > nums[i-1]) {
                index = i - 1;
                break;
            }
        }

        int minNums = INT_MIN, minIndex = index;
        for (int i = index + 1; i < length; i ++) {
            if (nums[i] > nums[index]) {
                minNums = min(minNums, nums[i]);
                minIndex = i;
            }
        } 

        //cout << "index: " << index << "\t minIndex: " << minIndex << endl;
        swap(nums[index], nums[minIndex]);
        if (index == length - 1) { // 数组已是倒叙排列，需转换成正序输出
            sort(nums.begin(), nums.end());
        } else {
            sort(nums.begin()+index+1, nums.end());
        }
    }

    void nextPermutation_v2(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        // 此时已经是倒叙了
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;
    auto print=[](vector<int>& nums) {
        for (const auto& n: nums) {
            std::cout << n << " ";
        }
        std::cout << "\n";
    };

    nums = {1,2,3,4,5};
    for (int i = 0; i < 120; i ++) {
        so->nextPermutation_v2(nums);
        print(nums);
    } 

    nums = {1,1,5};
    for (int i = 0; i < 6; i ++) {
        so->nextPermutation_v2(nums);
        print(nums);
    }
}
