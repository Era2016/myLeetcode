#include <climits>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int newX = 0;
        int prev = x;
        while (x != 0) {
            if (newX > INT_MAX/10 || (newX == INT_MAX/10 && x%10 > 7)) {
                return false;
            }
            newX = newX*10 + x%10;
            x /= 10;
        }
        return newX == prev;
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->isPalindrome(121) << std::endl;
    std::cout << so->isPalindrome(-121) << std::endl;
    std::cout << so->isPalindrome(1) << std::endl;
}
