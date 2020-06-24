#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int sum = 0;
            int max = nums[0];
            for (int i = 0; i < (int)nums.size(); ++ i) {
                // sum = max(nums[i], sum+nums[i])
                if (sum + nums[i] < nums[i]) {
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }

                //cout << "current sum: " << sum << endl;
                if (max < sum) {
                    max = sum;
                    //cout << "current max: " << max << endl;
                }
            }
            return max;

        }

        int maxSubArray_v2(vector<int>& nums) {
            if (nums.size() == 0) {
                return 0;
            }
            int result = nums[0], sum = nums[0];
            for (size_t i = 1; i < nums.size(); ++i) {
                sum = max(sum + nums[i], nums[i]);
                result = max(result, sum);
            }
            return result;
        }
};

int main()
{

    Solution* so = new Solution();
    //int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int arr[] = {-1};
    vector<int> v(begin(arr), end(arr));
    /*int tmp;
      while (true) {
      cin >> tmp;
      if (tmp == -9) {
      break;
      }
      v.push_back(tmp);
      }*/

    int result = so->maxSubArray(v);
    cout << result << endl;
    return 0;
}
