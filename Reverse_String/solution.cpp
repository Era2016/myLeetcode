#include <iostream>

using namespace std;

class Solution {
    public:
        string reverseString(string s) {
            int length = s.length();
            for (int i = 0, j = length - 1; i < j; ++ i, --j) {
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
            }

            return s;
        }
};

int main()
{
    Solution* so = new Solution();
    string str = so->reverseString("Hello");
    cout << str << endl;
}
