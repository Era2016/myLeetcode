#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    vector<long> tmp;
    vector<long> prefixSum;
    int cnt; // result
    int lower;
    int upper;
    void msort(vector<long>& nums, int start, int end) {
        if (start < end) {
            int mid = (end-start)/2 + start;
            msort(nums, start, mid);
            msort(nums, mid+1, end);
            merge(nums, start, mid, end);
        }
    }

    void merge(vector<long>& nums, int low, int mid, int high) {
        for (int i = low; i <= high; i ++)
            tmp[i] = nums[i];

        // local ordered
        int start = mid+1, end = mid+1;
        for (int i = low; i <= mid; i ++) {
            while (start <= high && nums[start] - nums[i] < lower) {
                start ++;
            }
            while (end <= high && nums[end] - nums[i] <= upper) {
                end ++;
            }

            cnt += end - start;
        }

        int i = low, j = mid+1;
        int index = low;
        while (i <= mid && j <= high) {
            if (tmp[i] <= tmp[j]) {
                nums[index ++] = tmp[i ++];
            } else {
                nums[index ++] = tmp[j ++];
            }
        }

        while (i <= mid) {
            nums[index ++] = tmp[i ++];
        }

        while (j <= high) {
            nums[index ++] = tmp[j ++];
        }
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->cnt = 0;
        this->lower = lower, this->upper = upper;
        tmp.clear(); tmp.resize(nums.size()+1);
        prefixSum.clear(); prefixSum.resize(nums.size()+1);
        for (int i = 1; i <= nums.size(); i ++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1]; 
        }

        msort(prefixSum, 0, prefixSum.size()-1);
        return this->cnt;
    }
};

int main() {
    Solution* so = new Solution();
    vector<int> v;
    vector<int> res;
    int cnt = 0;
    auto print=[](vector<int>& res) {
        for (const auto& k: res) {
            std::cout << k << "\t";
        }
        std::cout << std::endl;
    };

    v = {-2,5,-1}; 
    cnt = so->countRangeSum(v, -2 ,2);    
    std::cout << cnt << std::endl;

    v = {0}; 
    cnt = so->countRangeSum(v, 0, 0);    
    std::cout << cnt << std::endl;
    
    v = {-2147483647,0,-2147483647,2147483647};
    cnt = so->countRangeSum(v, -564, 3864);
    std::cout << cnt << std::endl;
}
