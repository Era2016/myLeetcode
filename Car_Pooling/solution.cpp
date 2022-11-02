#include <iostream>
#include <vector>

using std::vector;

// 差分数组
class Difference {
private: 
    vector<int> diff;
public:
    Difference(vector<int>& v) {
        diff.resize(v.size());
        diff[0] = v[0];
        for (int i = 1; i < v.size(); i ++) {
            diff[i] = v[i] - v[i-1];
        }
    }

    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j+1 < diff.size())
            diff[j+1] -= val;
    }

    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i ++) {
            res[i] = res[i-1] + diff[i-1];
        }
        return res;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001, 0);
        Difference* d = new Difference(v);
        auto isOverload = [](vector<int> v, int val) {
            for (auto k : v) {
                if (k > val) return true;
            }
            return false;
        };
        for (auto trip: trips) {
            d->increment(trip[1], trip[2]-1, trip[0]); 

            if (isOverload(d->result(), capacity)) return false;
        }

        return true;
    }

};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    bool overload = so->carPooling(trips, 4);
    std::cout << "result: " << overload << std::endl;

    overload = so->carPooling(trips, 5);
    std::cout << "result: " << overload << std::endl;
}
