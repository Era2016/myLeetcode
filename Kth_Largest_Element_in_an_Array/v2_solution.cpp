#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    int partition(vector<int>& nums, int low, int high) {
        //srand(time(nullptr));
        //int randomIndex = rand()%(high-low)+low;
        //swap(nums[high], nums[randomIndex]);

        int small = low - 1;
        for (int i = low; i < high; i ++) {
            if (nums[i] < nums[high]) {
                swap(nums[++ small], nums[i]);
            }
        }

        swap(nums[++ small], nums[high]);
        return small;
    }
public:
    int getKthLargestElement(vector<int>& nums, int k) {
        k = nums.size()-k;
        int low = 0, high = nums.size()-1;
        int pivote = -1;
        random_shuffle(nums.begin(), nums.end());
        while (low <= high) {
            pivote = partition(nums, low, high);
            if (pivote == k) {
                break;
            } else if (pivote < k) {
                low = pivote+1;
            } else {
                high = pivote-1;
            }
        }

        return nums[pivote];
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;


    v = {1,2,3,6,4,5};
    cout << so->getKthLargestElement(v, 2) << endl;

    v = {1};
    cout << so->getKthLargestElement(v, 1) << endl;
}
