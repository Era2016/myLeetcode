#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
        	int i = 0;
        	int length = nums.size();
        	print(nums);
        	cout << endl;
        	while (i < length) {
        		if (nums[i] > 0 && nums[i] <= length && nums[i] != nums[nums[i] - 1]) {
        			cout << i <<"\t" << nums[i] - 1 << "\t" << nums[nums[i]] << endl;
        			swap(nums[i], nums[nums[i] - 1]);
        			i--;
        			print(nums);
        			cout << endl;
        		}
        		i ++;
        	}

        	cout << endl;
        	print(nums);
        	for (int i = 0; i < length; ++ i) {
        		if (nums[i] != i + 1) {
        			return i + 1;
        		}
        	}
        	return length + 1; 
        }

        void print(vector<int> num) {
        	for(vector<int>::iterator iter = num.begin(); iter != num.end(); ++ iter) {
        		cout << *iter << "\t";
        	}
        	cout << endl;
        }
};


int main()
{
	Solution* so = new Solution();
	std::vector<int> v;
	while (true) {
		int num;
		cout << "please input num: " << endl;
		cin >> num;
		if (num != -9) {
			v.push_back(num);
		} else {
			break;
		}
	}
	int result = so->firstMissingPositive(v);
	cout << "result is : " << result << endl; 
    return 0;
}
