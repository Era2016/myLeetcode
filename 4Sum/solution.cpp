#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 4) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < len-3; i ++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if ((long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) {
                break;
            }
            if ((long)nums[i]+nums[len-3]+nums[len-2]+nums[len-1] < target) {
                continue;
            }

            for (int j = i+1; j < len-2; j ++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                if ((long)nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) {
                    break;
                }
                if ((long)nums[i]+nums[j]+nums[len-2]+nums[len-1] < target) {
                    continue;
                }

                int left = j+1, right = len-1;
                while (left < right) {
                    long cur = (long)nums[i]+nums[j]+nums[left]+nums[right]; 
                    if (cur < target) {
                        left ++;
                    } else if (cur > target) {
                        right --;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});                        
                        left ++; while (left < right && nums[left] == nums[left-1]) left ++;
                        right --; while (left < right && nums[right] == nums[right+1]) right --;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    vector<vector<int>> vv;
    auto print=[](vector<vector<int>>& vv) {
        for (auto v: vv) {
            for (auto val: v) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    };
    
    v = {1,0,-1,0,-2,2};
    vv = so->fourSum(v, 0);
    print(vv);

    v = {2,2,2,2,2};
    vv = so->fourSum(v, 8);
    print(vv);

    v = {-1,0,-5,-2,-2,-4,0,1,-2};
    vv = so->fourSum(v, -9);
    print(vv);

    v = {1000000000,1000000000,1000000000,1000000000};
    vv = so->fourSum(v, -9);
    print(vv);
}
