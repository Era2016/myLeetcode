#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
class Solution {
private:
    vector<int> tmp;
    int cnt;
    void msort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int mid = (end-start)/2 + start;
            msort(nums, start, mid);
            msort(nums, mid+1, end);
            merge(nums, start, mid, end);
        }
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        for (int i = low; i <= high; i ++)
            tmp[i] = nums[i];

        int p = mid + 1;
        for (int i = low; i <= mid; i ++) {
            while (p <= high && (long)nums[i] > (long)nums[p]*2) {
                p ++;
            } 
            cnt += p - mid - 1;
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
    int reversePairs(vector<int>& nums) {
        tmp.clear(); tmp.resize(nums.size());
        this->cnt = 0;
        msort(nums, 0, nums.size()-1);
        return cnt;
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

    v = {1,3,2,3,1};
    cnt = so->reversePairs(v);    
    std::cout << cnt << std::endl;

    v = {2,4,3,5,1}; 
    cnt = so->reversePairs(v);    
    std::cout << cnt << std::endl;
}
