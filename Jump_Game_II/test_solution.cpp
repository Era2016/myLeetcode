#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public :
		int jump(vector<int>& nums) {

			if (nums.size() == 0 || (nums.size() == 1 && nums[1] != 0)) {
				return 0;
			}

			int reach = 0;
			int lastReach = 0;
			int step = 0;
			int i = 0;
			for (; i <= reach && i < (int)nums.size(); ++ i) {

				if (i >= 1 && lastReach < nums[i-1]+i-1 ) {
					step ++;
					lastReach = reach;
					cout << "current step : " << step << endl;
				}

				reach = max(reach, nums[i]+i);
				cout << "current reach : " << reach << endl;
			}

			if (reach > lastReach && lastReach > i) {
				step ++;
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
    int arr[] = {1,2};
    //int arr[] = {3,2,1,0,4};
    
    vector<int> v(begin(arr), end(arr));
    int result = so->jump(v);

    cout << result << endl;
}

