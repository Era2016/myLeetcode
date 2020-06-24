#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

class Solution {
    public:
        int myAtoi(string str) {
            int length = str.length();
            if (length == 0) {
                return 0;
            }

            int index = 0;
            bool negative = false;  
            while (index < length && str[index] == ' ') {
                index ++;
            }
            if (str[index] == '+' || str[index] == '-' ) {
                if (str[index] == '-') negative = true;
                index ++;
            }

            /*unsigned int result = 0;
            for (int i = index; i < length; ++ i) {
                if (str[i] >= '0' && str[i] <= '9') {
                    if (!negative) {
                        if ((result == INT_MAX/10 && str[i] < '7') || result < INT_MAX/10) {
                            result = result * 10 + str[i] - '0';
                        } else {
                            result = INT_MAX;
                        }
                    } else {
                        if ((result == INT_MAX/10 && str[i] < '8') || result < INT_MAX/10) {                        //if (result * 10 < INT_MAX + 1 - str[i] + '0') {
                            result = result * 10 + str[i] - '0';
                        } else {
                            result = INT_MIN;
                        }
                    }
                } else {
                    break;
                }
            }*/
            long result = 0;
            while (index < length) {
                if (str[index] < '0' || str[index] > '9') {
                    break;
                }
                result = result * 10 + str[index ++] - '0';
                if (result > INT_MAX)
                    return (negative == 0) ? INT_MIN : INT_MAX;
            }
            return (negative == true)? (0 - result): result;
        }
        int myAtoi_v2(string str) {
            int i = str.find_first_not_of(' '), s = 1;
            long res = 0;
            if(str[i] == '+' || str[i] == '-') 
                s = (str[i ++] == '+')? 1: -1;
            while (isdigit(str[i]) ) {
                res = res * 10 + (str[i ++] - '0');
                if (res > INT_MAX) return s > 0? INT_MAX: INT_MIN;
            }
            return s*res;
        }
};

int main()
{
    Solution* so = new Solution();
    string str = to_string(INT_MAX);
    int result = so->myAtoi(str);
    cout << result << endl;
    return 0;
}
