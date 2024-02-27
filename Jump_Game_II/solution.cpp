#include <iostream>
#include <vector>

using namespace std;

/**
 *关键的问题1：到底什么时候总步数+1呢？
 *回答：假设到遍历到数组index=i的位置，在此之前jump到的位置为k；在位置k最远可以到达的范围是[k,reach]，
 *如果reach<i，说明[k-reach]之间必须再jump一次，这样才能保证i在可以reach的范围内！

 *关键问题2：那究竟在[k-reach]的哪个位置再次jump呢？
 *回答：根据贪心算法，应该挑可以reach范围最远的那个点，如果需要求jump game的最短次数的jump路径，就需要记录这个点了。
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int reach = 0;
        int lastReach = 0;
        int step = 0;

        for (int i = 0; i <= reach && i < (int)nums.size(); ++ i) {
            if (lastReach < i) {
                step ++;
                lastReach = reach;
                cout << "current step : " << step << endl;
            }

            reach = max(reach, nums[i]+i);
            cout << "current reach : " << reach << endl;
        }

        if (reach < (int) nums.size() - 1) {
            return 0;
        }

        return step;
    }
};


int main()
{
    Solution* so = new Solution();
    //int arr[] = {2,3,1,1,4};
    int arr[] = {1,3,2};
    //int arr[] = {3,2,1,0,4};

    vector<int> v(begin(arr), end(arr));
    int result = so->jump(v);

    cout << result << endl;
}

