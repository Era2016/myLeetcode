#include <climits>
#include <iostream>
#include <vector>
#include <assert.h>

using std::vector;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int left = 0;
        int minIndex = -1, minVal = INT_MAX;
        for (int i = 0; i < len; i ++) {
            left += gas[i] - cost[i];
            if (left < minVal) {
                minVal = left;
                minIndex = i;
            }
        }
        
        // 因为油量不管在任何时候为起点时都能绕一圈， 那就返回 0
        if (minVal > 0) return 0;
        return (left >= 0)? (minIndex+1)%len: -1;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> gas, cost;

    //assert(so->canCompleteCircuit(gas, cost) == )
    gas = {1,2,3,4,5};
    cost = {3,4,5,1,2};
    std::cout << so->canCompleteCircuit(gas, cost) << std::endl; // 3
    
    gas = {2,3,4};
    cost = {3,4,3};
    std::cout << so->canCompleteCircuit(gas, cost) << std::endl; // -1

    gas = {2};
    cost = {2}; 
    std::cout << so->canCompleteCircuit(gas, cost) << std::endl; // 0

    gas = {3,3,4};
    cost = {3,4,4}; 
    std::cout << so->canCompleteCircuit(gas, cost) << std::endl; // -1 
}
