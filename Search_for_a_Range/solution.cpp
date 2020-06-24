#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int length = nums.size();
            int start = 0;
            int end = length - 1;
            int index = -1;
            vector<int> v;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (nums[mid] > target) {
                    end = mid - 1;
                } else if (nums[mid] < target) {
                    start = mid + 1;
                } else {
                    index = mid;
                    cout << index << endl;
                    while (true) {
                        if (index - 1 > -1) {
                            if (nums[index - 1] == target) {
                                index --;
                            } else {
                                break;
                            }
                        } else {
                            break;
                        }
                    } 
                    cout << index << endl;
                    v.push_back(index);
                    index = mid;
                    while (true) {
                        if (index + 1 < length) {
                            if (nums[index + 1] == target) {
                                index ++;
                            } else {
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                    cout << index << endl;
                    v.push_back(index);
                    return v;
                }
            }
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
};

int main()
{
    Solution* so = new Solution();
    vector<int> v;
    while (true) {
        int temp;
        cin >> temp;
        if (temp != -1) {
            v.push_back(temp);
        } else {
            cout << "input done" << endl;
            break;
        }
    }
    int target;
    cin >> target;

    vector<int> ret = so->searchRange(v, target);
    cout << ret[0] << "\t" << ret[1] << endl;
    return 0;
}
