#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::deque;
using std::string;
class Solution {
public:
    bool isOperator(string s) {
        return (s=="+" || s=="-" || s=="*" || s== "/");
    }
    int evalRPN(vector<string>& tokens) {
        deque<string> q;
        int ret = 0;
        for (auto& token : tokens) {
            if (!isOperator(token)) {
                q.push_back(token);
            } else {
                string num1 = q.back(); q.pop_back();
                string num2 = q.back(); q.pop_back();
                if (token == "+") {
                    ret = stoi(num1) + stoi(num2);
                } else if (token == "-") {
                    ret = stoi(num2) - stoi(num1);
                } else if (token == "*") {
                    ret = stoi(num2) * stoi(num1);
                } else {
                    ret = stoi(num2) / stoi(num1);
                }
                q.push_back(std::to_string(ret));
            }
        }
        string num = q.back(); q.pop_back();
        return stoi(num);
    }
};

int main() {
    Solution* so = new Solution();
    vector<string> tokens;

    tokens = {"2", "1", "+", "3", "*"};
    std::cout << so->evalRPN(tokens) << std::endl;
    
    tokens = {"4", "13", "5", "/", "+"};
    std::cout << so->evalRPN(tokens) << std::endl;

    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}; 
    std::cout << so->evalRPN(tokens) << std::endl;
}
