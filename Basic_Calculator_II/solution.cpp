#include <iostream>
#include <stack>

using namespace std;

class Solution {
    public:
        int calculate(string s) {
            stack<int> stack;
            char sign = '+';
            int num = 0;

            int i = 0;
            while (i < (int)s.length()) {
                if (isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                }
                if ((!isdigit(s[i]) && !isspace(s[i]) ) || i == (int)s.length() - 1) {
                    switch (sign) {
                        case '+':
                            break;
                        case '-':
                            num = -num;
                            break;
                        case '*':
                            num = stack.top() * num;
                            stack.pop();
                            break;
                        case '/':
                            num = stack.top() / num;
                            stack.pop();
                            break;
                        default:
                            break;
                    }	
                    stack.push(num);
                    sign = s[i];
                    num = 0;
                }
                i ++;
            }

            num = 0;
            while (!stack.empty()) {
                num += stack.top();
                stack.pop();
            }
            return num;
        }
};

int main()
{
    Solution* so = new Solution();
    cout << so->calculate("2 + 3*5 -1") << endl;
    return 0;
}
