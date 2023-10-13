#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int end = nums.size();
        if (end <= 2) {
            return end;
        }

        int cursor = 2;
        int index = 2; 
        while (index < end) {
            if (nums[index] != nums[cursor-2]) {
                nums[cursor ++] = nums[index];
            }
            index ++;
        }
        return cursor;
    }
};
int main() {
    Solution *so = new Solution();
    vector<int> nums;
    int result;
    auto print=[](vector<int>& nums, int end) {
        for (int i = 0; i < end; i ++) {
            cout << nums[i] << "\t";
        }
        cout << endl;
    };

    nums = {1,1,1,2,2,3};
    result = so->removeDuplicates(nums); 
    print(nums, result);

    nums = {0,0,1,1,1,1,2,3,3};
    result = so->removeDuplicates(nums); 
    print(nums, result);   
}
