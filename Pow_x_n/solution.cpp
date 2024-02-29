#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;

        long big_n = n;
        if (big_n < 0) {
            x = 1/x;
            big_n = -big_n;
        }

        double res = 1.0;
        while (big_n != 0) {
            if (big_n & 1) res *= x; 
            x *= x;
            big_n >>= 1;
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->myPow(2.00000, 10) << std::endl;
    std::cout << so->myPow(2.10000, 3) << std::endl;
    std::cout << so->myPow(2.00000, -2) << std::endl;
    std::cout << so->myPow(2.00000, -2^31) << std::endl;
    std::cout << so->myPow(2.00000, 2^31+1) << std::endl;
}
