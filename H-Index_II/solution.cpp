#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = (right-left)/2 + left;
            if (citations[mid] >= n-mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n-left;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> citations;

    citations = {0,1,3,5,6};
    std::cout << so->hIndex(citations) << std::endl; // 3
    
    citations = {1,2,100};
    std::cout << so->hIndex(citations) << std::endl; // 2

    citations = {0};
    std::cout << so->hIndex(citations) << std::endl; // 0
}
