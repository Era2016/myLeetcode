#include <climits>
#include <cmath>
#include <iostream>

using std::string;
class Solution {
public:
    int myAtoi(string s) {
        int cursor = 0;
        int len = s.length();

        while (s[cursor] == ' ') {
            cursor ++;
            if (cursor == len) return 0;
        }
        
        int sign = 1;
        if (s[cursor] == '-') {
            sign = -1;
        }
        if (s[cursor] == '-' || s[cursor] == '+') cursor ++;
    
        int ret = 0;
        while (cursor < len) {
            if (s[cursor] < '0' || s[cursor] > '9') break;
            if (ret>INT_MAX/10 || (ret==INT_MAX/10 && s[cursor]>'7')) {
                return sign==-1 ?INT_MIN: INT_MAX;
            }
            
            ret = ret*10 + (s[cursor]-'0');
            cursor ++;
        }

        return sign * ret;
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->myAtoi("42") << std::endl;
    std::cout << so->myAtoi("     -42") << std::endl;
    std::cout << so->myAtoi("4193 with words") << std::endl;
    std::cout << so->myAtoi("2147483647") << std::endl;
    std::cout << so->myAtoi("2147483648") << std::endl;
    std::cout << so->myAtoi("-2147483647") << std::endl;
    std::cout << so->myAtoi("-2147483648") << std::endl;
    std::cout << so->myAtoi("-2147483649") << std::endl;
    std::cout << so->myAtoi("-21474836470") << std::endl;
    std::cout << so->myAtoi("") << std::endl;
}
