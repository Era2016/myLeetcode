#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    long factorial(int n) {
        long res = 1;
        while (n > 0) {
            res *= n --;
        }
        return res;
    }
public:
    int trailingZeroes_v2(int n) {
        int count = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = i; j != 0 && j%5==0; j /= 5) {
                count ++;
            }
        }
        return count;
    }

    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            count += n / 5;
            n = n / 5;
        }
        return count;
    }
};

int main() {
    Solution *so = new Solution();
    //for (int i = 1; i < 30; i ++) {
    //    std::cout << i << "=====" << so->factorial(i) << std::endl;
    //}
    std::cout << so->trailingZeroes(3) << "===" << so->trailingZeroes_v2(3) << std::endl;
    std::cout << so->trailingZeroes(5) << "===" << so->trailingZeroes_v2(5) << std::endl;
    std::cout << so->trailingZeroes(0) << "===" << so->trailingZeroes_v2(0) << std::endl;
}
