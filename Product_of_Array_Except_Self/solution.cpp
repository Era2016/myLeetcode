#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> L(length, 1);
        vector<int> R(length, 1);

        // length >= 2
        // L[0] = 1;
        for (int i = 1; i < length; i ++) {
            L[i] = L[i-1] * nums[i-1];
        }

        //R[length-1] = 1;
        for (int i = length-2; i >= 0; i --) {
            R[i] = R[i+1] * nums[i+1];
        }

        vector<int> ret(length);
        for (int i = 0; i < length; i ++) {
            ret[i] = L[i] * R[i];
        }

        return ret;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;
    vector<int> ret;
    auto print=[](vector<int>& v) {
        for (auto k: v) {
            std::cout << k << "\t";
        }
        std::cout << std::endl;
    };

    nums = {1,2,3,4};
    ret = so->productExceptSelf(nums); 
    print(ret);

    nums = {-1,1,0,-3,3};
    ret = so->productExceptSelf(nums); 
    print(ret);
}
