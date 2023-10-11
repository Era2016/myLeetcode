#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int length1 = a.length()-1, length2 = b.length()-1;
        int added = 0;
        string result;
        while (length1 >= 0 || length2 >= 0 || added != 0) {
            int num1 = (length1>=0) ? a[length1]-'0': 0;
            int num2 = (length2>=0) ? b[length2]-'0': 0;

            int sum = num1+num2+added;
            added = sum/2;
            result.push_back(sum%2);
            length1 --, length2 --;
        }

        reverse(result.begin(), result.end());
        for (auto& n: result) {
            n += '0';
        }
        return result;
    }
};

int main() {
    Solution *so = new Solution();
    cout << so->addBinary("11", "1") << endl;
    cout << so->addBinary("1010", "1011") << endl;
    cout << so->addBinary("10", "10") << endl;
}
