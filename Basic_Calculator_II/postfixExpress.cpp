#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
    public:
        int calculate(string s) {
            stack<int> number;
            vector<char> v = in2Post(s);
            /*for (vector<char>::iterator iter = v.begin(); iter != v.end(); ++ iter) {
                cout << *iter << " ";
            } 
            cout << endl;*/
            return 0;
        }

        // 比较操作符A和操作符B的优先级
        // opA：待输入字符， opB：栈内字符
        // opA 优先级大于 opB时，返回1；同级或小于返回0
        // '(' | '*, /'| '+, -'| ')'
        bool opAisBiggerThanOpB(char opA, char opB)
        {
            if (opA == '(') {
                return 1;
            } else if ((opA == '*' || opA == '/') && (opB == '+' || opB == '-' || opB == ')')) {
                return 1;
            } else if ((opA == '+' || opA == '-') && opB == ')' ) {
                return 1;
            } else {
                return 0;
            }
        }

        vector<char> in2Post(string s) {
            stack<char> stack;
            vector<char> v; 

            int i = 0;
            int num = 0;
            while (i < (int) s.length() || !stack.empty()) {
                if (isdigit(s[i])) {
                    // 仅支持个位数处理
                    while (i < (int) s.length() && isdigit(s[i])) {
                        num = num * 10 + s[i] - '0';   
                        i ++; 
                    }
                    cout << "num: " << num << endl;
                    v.push_back(num + '0');
                    num = 0;
                } else if (!isdigit(s[i]) && !isspace(s[i])) {
                    if (stack.empty() || opAisBiggerThanOpB(s[i], stack.top())) {
                        stack.push(s[i]);
                        cout << "instack: op: " << s[i] << endl;
                    } else {
                        while (!stack.empty() && !opAisBiggerThanOpB(s[i], stack.top())) {
                            cout << "popstack: op: " << stack.top() << endl;
                            v.push_back(stack.top());
                            stack.pop();
                        }
                        if (i < (int) s.length()) {
                            stack.push(s[i]);
                        }
                    }
                    i ++;
                }
            }
            vectorPrint(v);
            return v;
        }

        void vectorPrint(vector<char> v) {
            for (vector<char>::iterator iter = v.begin(); iter != v.end(); ++ iter) {
                cout << *iter << " ";
            } 
            cout << endl;
        }
};

int main()
{
    Solution* so = new Solution();
    string str = "1+5*3/2";
    so->calculate(str);
    return 0;
}
