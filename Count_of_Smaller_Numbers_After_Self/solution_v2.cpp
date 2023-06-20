#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    struct pair {
        int val;
        int index;
    };
    vector<int> ans;
    vector<pair> tmp;
    void msort(vector<pair>& arr, int start, int end) {
        if (start < end) {
            int mid = (end-start)/2 + start;
            msort(arr, start, mid);
            msort(arr, mid+1, end);
            merge(arr, start, mid, end);
        }
    }
    
    void merge(vector<pair>& arr, int low, int mid, int high) {
        //tmp = arr; // time consumes too much
        for (int i = low; i <= high; i ++) {
            tmp[i] = arr[i];
        }
        int index = low;
        int i = low, j = mid + 1;
        while (i <= mid && j <= high) {
            if (tmp[i].val <= tmp[j].val) {
                arr[index] = tmp[i];
                ans[arr[index].index] += j - mid - 1;
                i ++;
            } else {
                arr[index] = tmp[j];
                j ++;
            }
            index ++;
        } 

        while (i <= mid) {
            arr[index] = tmp[i];
            ans[arr[index].index] += j - mid - 1;
            index ++, i ++;
        }
        while (j <= high) {
            arr[index] = tmp[j];
            index ++, j ++;
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        ans.clear(); ans.resize(nums.size()); 
        tmp.clear(); tmp.resize(nums.size());
        vector<pair> arr(nums.size());
        vector<pair>::iterator iter = arr.begin();
        for (int i = 0; i < nums.size(); i ++) {
            (*iter).index = i;
            (*iter).val = nums[i];
            iter ++;
        }

        //tmp = arr;
        //print(tmp);
        msort(arr, 0, nums.size()-1);
        return this->ans;
    }

    void print(vector<pair>& v) {
        for (const auto& k: v) {
            std::cout << "(" << k.index << ":" << k.val << ")" << "\t";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution* so = new Solution();
    vector<int> v;
    vector<int> res;
    auto print=[](vector<int>& res) {
        for (const auto& k: res) {
            std::cout << k << "\t";
        }
        std::cout << std::endl;
    };

    v = {5,2,6,1};
    res = so->countSmaller(v);
    print(res);

    v = {-1,-1};
    res = so->countSmaller(v);
    print(res);
    
    v = {-1};
    res = so->countSmaller(v);
    print(res);
}
