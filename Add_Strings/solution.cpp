#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> v;
        int left = 0;
        int i1 = num1.length()-1, i2 = num2.length()-1;
        while (i1 >= 0 || i2 >= 0 || left) {
            int n1 = (i1>=0)? num1[i1]-'0': 0;
            int n2 = (i2>=0)? num2[i2]-'0': 0;

            int sum = n1 + n2 + left;
            left = sum/10;
            v.push_back(sum%10);

            i1 --;
            i2 --;
        }

        std::reverse(v.begin(), v.end());
        string str;
        for (auto i: v) {
            str += i+'0';
        }
        return str;
    }
};

int main() {
    Solution *so = new Solution();
    string num1, num2;

    num1 = "11"; num2 = "123";
    std::cout << so->addStrings(num1, num2) << std::endl;

    num1 = "456"; num2 = "77";
    std::cout << so->addStrings(num1, num2) << std::endl;

    num1 = "0"; num2 = "0";
    std::cout << so->addStrings(num1, num2) << std::endl;

    num1 = "1"; num2 = "9";
    std::cout << so->addStrings(num1, num2) << std::endl;
}
