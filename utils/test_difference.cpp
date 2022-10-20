#include "difference.h"
#include <iostream>
#include <vector>

using std::vector;
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
