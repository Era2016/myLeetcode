#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {

        int left = 1, right = 0;
        for (auto i : piles) {
            if (right < i) right = i;
        }

        while (left <= right) {
            int mid = left + (right - left)/2;
            if (_eat(piles, mid) <= h) {
                right = mid - 1;
            } else if (_eat(piles, mid) > h) {
                left = mid + 1;
            }
        }

        return left;
    }

    int _eat(vector<int>& piles, int speed) {
        int cnt = 0;
        for (int i = 0; i < piles.size(); i ++) {
            cnt += piles[i]/speed; 
            if (piles[i]%speed) cnt += 1;
        } 
        return cnt;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    int h;
    int ret;

    v = {3,6,7,11};
    h = 8;
    ret = so->minEatingSpeed(v, h);
    std::cout << ret << std::endl;

    v = {30,11,23,4,20};
    h = 5;
    ret = so->minEatingSpeed(v, h);
    std::cout << ret << std::endl;

    v = {30,11,23,4,20};
    h = 6;
    ret = so->minEatingSpeed(v, h);
    std::cout << ret << std::endl;

    v = {805306368,805306368,805306368};
    h = 1000000000;
    // TODO OJ needs _eat(vector<int>&, int) return long
    ret = so->minEatingSpeed(v, h);
    std::cout << ret << std::endl;
}
