#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int siz = gas.size();
        int i = 0;
        while (i < siz) {
            int cnt = 0;
            int gasSum = 0, costSum = 0;
            while (cnt < siz) {
                int j = (i+cnt)%siz;
                gasSum += gas[j];
                costSum += cost[j];
                if (gasSum < costSum) {
                    break;
                }
                cnt ++;
            }

            if (cnt == siz) {
                return i;
            } else {
                i = i+cnt+1;
            }
        }

        return -1;
    }
};

int main() {
    Solution* so = new Solution();
    vector<int> gas, cost;
    int result = 0, result2 = 0, result3 = 0;

    gas = {1,2,3,4,5};
    cost = {3,4,5,1,2};
    result = so->canCompleteCircuit(gas, cost);
    cout << "result: " << result << "<==>" << result2 << "<==>" << result3 << endl;

    gas = {2,3,4};
    cost = {3,4,3};
    result = so->canCompleteCircuit(gas, cost);
    cout << "result: " << result << "<==>" << result2 << "<==>" << result3 << endl;

    gas = {3,1,1};
    cost = {1,2,2};
    result = so->canCompleteCircuit(gas, cost);
    cout << "result: " << result << "<==>" << result2 << "<==>" << result3 << endl;
}
