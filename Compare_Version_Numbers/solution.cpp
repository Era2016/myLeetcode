#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::string;
class Solution {
private:
    int getSub(string version, int index, int& cursor) {
        int i = index;
        int j = index;
        bool isFirst = true;
        while (i < version.length()) {
            if (version[i] == '0' && isFirst) {
                j ++, i ++;
            } else if (version[i] == '.') {
                break;
            } else {
                i ++;
                isFirst = false;
            }
        }

        cursor = i;
        return (i==j)? 0: stoi(version.substr(j, i-j)); // i-1-j+1
    }
public:
    int compareVersion(string version1, string version2) {
        int cursor1 = 0, cursor2 = 0;
        int len1 = version1.length(), len2 = version2.length();
        while (cursor1 < len1 || cursor2 < len2) {
            int nCursor1 = -1, nCursor2 = -1;
            int str1 = (cursor1<len1)? getSub(version1, cursor1, nCursor1): 0; 
            int str2 = (cursor2<len2)? getSub(version2, cursor2, nCursor2): 0;
            //printf("[%d - %d]\n", str1, str2);
            if (str1 != str2) {
                return (str1 > str2)? 1: -1;
            }

            cursor1 = (cursor1 < len1)? nCursor1+1: len1; 
            cursor2 = (cursor2 < len2)? nCursor2+1: len2;
        }

        return 0;
    }

    void test() {
        //string str = "7.003.500.2.0.001.00.001";
        //string str = "2.0.001.00.001";
        string str = "1.01.0";
        int cursor = 0;
        int len = str.length();
        while (cursor < len) {
            int nCursor = 0;
            int val = getSub(str, cursor, nCursor);
            std::cout << "num:" <<  val << std::endl;
            cursor = nCursor+1;
        }
    }
};

int main() {
    Solution *so = new Solution();
    //so->test();
    //return 1;
    std::cout << so->compareVersion("1.01", "1.001") << std::endl;
    std::cout << so->compareVersion("1.0", "1.0.0") << std::endl;
    std::cout << so->compareVersion("0.1", "1.1") << std::endl;
    std::cout << so->compareVersion("7.5.2.4", "7.5.3") << std::endl;
    std::cout << so->compareVersion("3.2", "3.02.0") << std::endl;
}
