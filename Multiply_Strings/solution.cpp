#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string add(string num1, string num2) {
        int length1 = num1.length(), length2 = num2.length();
        int added = 0;
        string result;
        int i = length1-1, j = length2-1;
        while (i >= 0 || j >= 0 || added != 0) {
            int x = i >= 0? num1.at(i)-'0': 0;
            int y = j >= 0? num2.at(j)-'0': 0;
            int sum = x + y + added;
            result.push_back(sum%10);
            added = sum/10;
            i --, j --;
        }

        reverse(result.begin(), result.end());
        for (auto &c: result) {
            c += '0';
        }
        return result;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int length1 = num1.length(), length2 = num2.length();
        string result = "0";
        for (int i = length2-1, cnt = 0; i >= 0; i --, cnt ++) {
            int added = 0;
            string tmp;
            for (int j = 0; j < cnt; j ++) {
                tmp.push_back(0);
            }

            int y = num2.at(i)-'0';
            for (int j = length1-1; j >= 0; j --) {
                int x = num1.at(j)-'0';
                int product = x * y + added;
                tmp.push_back(product%10);
                added =  product/10;
            }
            while (added) {
                tmp.push_back(added%10);
                added /= 10;
            }

            reverse(tmp.begin(), tmp.end());
            for (auto& c: tmp) {
                c += '0';
            }

            result = add(result, tmp);
        }
        return result;
    }

    /* bignumber overflow */
    string multiply2(string num1, string num2) {
        int length1 = num1.size(), length2 = num2.size();
        vector<int> result(length1+length2);
        long sum = 0;
        long cnt1, cnt2 = 1;
        for (int i = length2-1; i >= 0; i --) {
            long tmpSum = 0, cnt1 = 1;
            for (int j = length1-1; j >= 0; j --) {
                cout << num2[i] << "*" << num1[j] << "*" << cnt1 << endl;
                tmpSum += (num2[i]-'0') * (num1[j]-'0') * long(cnt1);
                cnt1 *= 10;
                cout << "tmp sum: " << tmpSum << endl;
            }

            sum += tmpSum * cnt2;
            cnt2 *= 10;
        }
        return to_string(sum);
    }
};

int main() {
    Solution *so = new Solution();
    cout << so->multiply("2", "3") << endl;
    cout << so->multiply("123", "456") << endl;
    cout << so->multiply("1234", "567") << endl;
    cout << so->multiply("0", "123") << endl;
    cout << so->multiply("123", "0") << endl;
    cout << so->multiply("881095803", "61") << endl;
    cout << so->multiply("498828660196", "840477629533") << endl;
}
