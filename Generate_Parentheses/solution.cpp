#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {        
        vector<string> v;
        string str;
        generateParenthesisDFS(n, n, v, str);
        return v;
    }

    void generateParenthesisDFS(int left, int right, vector<string>& v, string str) {

        if (left > 0) {
            //str = "(" + str;
            generateParenthesisDFS(left-1, right, v, str+'(');
        } 
        if (right > 0 && left < right) {
            //str = ")" + str;
            generateParenthesisDFS(left, right-1, v, str+')');
        }

        if (left == right && left == 0) {
            v.push_back(str);
        }
    }
};

int main()
{
    Solution* so = new Solution();
    vector<string> v = so->generateParenthesis(3);
    for (vector<string>::iterator iter = v.begin(); iter != v.end(); ++ iter) {
        cout << * iter << endl;
    }
    return 0;
}
