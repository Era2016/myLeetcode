#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < (int)gas.size(); i ++) {
            int ret = 0, j = i;
            bool isFirst = false, found = true;
            //cout << "current round: " << j << endl;
            while(j != i || isFirst == false) {
                isFirst = true;
                //cout << "details: "<< gas[j] << "\t" << cost[j] << "\t" << ret << endl;
                ret += gas[j] - cost[j];                 
                if (ret < 0) { found = false; break; }
                j ++;
                if (j >= (int)gas.size()) { j %= gas.size(); }
            }
            if (found == true) { return i; }
        }
        return -1;
    }

    int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
        int start(0),total(0),tank(0);
        //if car fails at 'start', record the next station
        for(int i=0;i<(int)gas.size();i++) { 
            if((tank=tank+gas[i]-cost[i])<0) {
                start=i+1;total+=tank;tank=0;
            }
        }
        return (total+tank<0)? -1:start;
    }

/*
The basic idea is every time we start from a station, we go as far as possible by increasing end until remaining gas is less than 0. If 'end' finally hits start we know we can travel around from 'start'. If we haven't traveled around, we know we cannot start from this station. Then we check the station before our start station if we can start from this station. Repeat until we have checked all stations.

Note there is a little trick that every time we try to find the next start station, we always to back to extend the distance from start to end so that we can check all stations on the circuit. Otherwise, if we move start forward to decrease the distance from start to end, we are likely to end up with only checking part of the circuit. Another trick is we start from the end of the array so as to avoid some corner cases.
*/
	int canCompleteCircuit3(vector<int> &gas, vector<int> &cost) {

       int start = gas.size()-1;
       int end = 0;
       int sum = gas[start] - cost[start];
       while (start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
    }
};

int main() {
    Solution* so = new Solution();
    vector<int> gas, cost;
    int result = 0, result2 = 0, result3 = 0;

    gas = {1,2,3,4,5};
    cost = {3,4,5,1,2};
    result = so->canCompleteCircuit(gas, cost);
    result2 = so->canCompleteCircuit2(gas, cost);
	result3 = so->canCompleteCircuit3(gas, cost);
    cout << "result: " << result << "<==>" << result2 << "<==>" << result3 << endl;

    gas = {2,3,4};
    cost = {3,4,3};
    result = so->canCompleteCircuit(gas, cost);
    result2 = so->canCompleteCircuit2(gas, cost);
	result3 = so->canCompleteCircuit3(gas, cost);
    cout << "result: " << result << "<==>" << result2 << "<==>" << result3 << endl;

    gas = {3,1,1};
    cost = {1,2,2};
    result = so->canCompleteCircuit(gas, cost);
    result2 = so->canCompleteCircuit2(gas, cost);
	result3 = so->canCompleteCircuit3(gas, cost);
    cout << "result: " << result << "<==>" << result2 << "<==>" << result3 << endl;
}
