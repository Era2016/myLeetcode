#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m-1; i >= 0; i --) {
            nums1[i+n] = nums1[i];
        }

        int i1 = n, i2 = 0;
        int index = 0;
        while (i1<m+n && i2<n) {
            if (nums1[i1] < nums2[i2]) {
                nums1[index ++] = nums1[i1 ++];
            } else {
                nums1[index ++] = nums2[i2 ++];
            }
        }

        while (i2 < n) {
            nums1[index] = nums2[i2];
            i2 ++;
            index ++;
        }
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums1, nums2;
    auto print=[&]() {
        for (auto n: nums1) {
            std::cout << n << " ";
        }
        std::cout << "\n";
    };

    nums1 = {1,2,3,0,0,0};
    nums2 = {2,5,6};
    so->merge(nums1, 3, nums2, 3);
    print();

    nums1 = {1};
    nums2 = {};
    nums1.resize(1);
    so->merge(nums1, 1, nums2, 0);
    print();

    nums1 = {};
    nums2 = {1};
    nums1.resize(1);
    so->merge(nums1, 0, nums2, 1);
    print();
}
