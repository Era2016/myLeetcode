#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            if (nums.size() == 0) {
                return 0;
            } 

            int max_1 = nums[0];
            int min_1 = nums[0];
            int max_product = nums[0];
            int min_product = nums[0];

            for (int i = 1; i < (int) nums.size(); ++ i) {
                int cur_max = max_product * nums[i];
                int cur_min = min_product * nums[i];
                max_product = max(max(cur_max, nums[i]), cur_min);
                min_product = min(min(cur_min, nums[i]), cur_max);

                // 可能涉及到IO, 输出影响效率
                //cout << "current max: " << max_product << " current min: " << min_product << endl;
                max_1 = max(max_1, max_product);
                //min_1 = min(min_1, min_product);

            }
            return max_1;
        }

        int maxProduct_v2(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];

            int curmin = 0, curmax = 0, res = 0, tmpmax;
            for(int i = 0; i < n; ++i)
            {
                tmpmax = curmax;
                curmax = max(nums[i], max(tmpmax*nums[i], curmin*nums[i]));
                curmin = min(nums[i], min(tmpmax*nums[i], curmin*nums[i]));
                res = max(curmax, res);

            }
            return res;
        }
};

int main(int argc, char const *argv[])
{
    Solution* so = new Solution();
    int arr[] = {2,3,-2,4};
    std::vector<int> v(begin(arr), end(arr));

    int result = so->maxProduct(v);
    cout << result << endl;
    return 0;
}
