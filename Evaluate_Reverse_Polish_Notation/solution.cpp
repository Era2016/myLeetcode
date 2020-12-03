#include <iostream>
#include <vector>
#include <stack>

using namespace std;
void print(stack<string> s);

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int ret = 0;
        for (int i = 0; i < (int)tokens.size(); i ++) {
            if (!isOperator(tokens[i])) { s.push(tokens[i]); } 
            else {
                int a = stoi(s.top()); s.pop();
                int b = stoi(s.top()); s.pop();
                if (tokens[i] == "*") { ret = a * b; }
                else if(tokens[i] == "/") { ret = b / a; }
                else if(tokens[i] == "+") { ret = a + b; }
                else { ret = b - a; }
                s.push(to_string(ret)); 
            }
        }
        ret = stoi(s.top());
        s.pop();
        return ret;
    }
private:
    bool isOperator(string s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") { return true; }
        return false;
    }
};

void print(stack<string> s) {
    while (!s.empty()) {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << endl;
}

int main() {
    Solution* so = new Solution();
    //vector<string> tokens = {"2", "1", "+", "3", "*"};
    //vector<string> tokens = {"4", "13", "5", "/", "+"};
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}; 
    int ret = so->evalRPN(tokens);
    cout << ret << endl;
}
