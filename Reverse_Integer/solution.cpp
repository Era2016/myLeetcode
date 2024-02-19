#include <iostream>
#include <cassert>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            if (rev < INT_MIN/10 || rev > INT_MAX/10) {
                return 0;
            }
            rev = 10 * rev + x%10;
            x /= 10;
        }
        return rev;
    }
};

int main() {
    Solution *so = new Solution();

    assert(so->reverse(123) == 321);
    assert(so->reverse(-123) == -321);
    assert(so->reverse(120) == 21);
}
