#include <iostream>
#include <vector>

using namespace std;

static int kap = []() {
    std::ios::sync_with_stdio(false);
    return 0;
}();


class Solution {
    public:
        int getStart(const std::vector<int>& nums, int target, int idx)
        {
            int s{0}, e{idx - 1}, m{0};

            while (s <= e)
            {
                m = s + ((e-s) >> 1);

                if (target == nums[m])
                {
                    if (m == s) return m;
                    else
                    {
                        if (nums[m-1] != target)    return m;
                        else                        e = m - 1;
                    }
                }
                else    s = m + 1;
            }
        }

        int getEnd(const std::vector<int>& nums, int target, int idx)
        {
            int s{idx + 1}, e{nums.size() - 1}, m{0};

            while (s <= e)
            {
                m = s + ((e - s) >> 1);

                if (target == nums[m])
                {
                    if (m == e) return m;
                    else
                    {
                        if (nums[m+1] != target)    return m;
                        else                        s = m + 1;
                    }
                }
                else    e = m - 1;
            }
        }

        vector<int> searchRange(vector<int>& nums, int target) {
            std::vector<int> res;

            if (nums.size() == 0)
            {
                res.push_back(-1);
                res.push_back(-1);
                return res;
            }

            int s{0}, e{nums.size() - 1}, m{0}, idx{-1};

            while (s <= e)
            {
                m = s + ((e-s) >> 1);

                if (nums[m] == target)
                {
                    idx = m;
                    break;
                }
                else if(target < nums[m])   e = m - 1;
                else                        s = m + 1;
            }

            if (idx == -1)
            {
                res.push_back(-1);
                res.push_back(-1);
                return res;
            }

            int fs{-1}, fe{-1};

            if (idx == 0)   fs = 0;
            else if (nums[idx - 1] != target)   fs = idx;

            if (idx == nums.size() - 1) fe = nums.size() - 1;
            else if (nums[idx + 1] != target)   fe = idx;


            if (fs == -1)   fs = getStart(nums, target, idx);
            if (fe == -1)   fe = getEnd(nums, target, idx);

            res.push_back(fs);
            res.push_back(fe);

            return res;
        }
};
