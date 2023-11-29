/**
// 输入：中文数字；输出：阿拉伯数字
// 例1：三千五百四十二万五千三百六十八亿七千九百六十万零五千二百三十八 ->3542536879605238
// 例2：三十亿零五千万零三 --> 3050000003
// 输入全部正确；不考虑溢出；最大单位是亿（千亿，万亿，不会有亿亿）
// 语言不限
*/
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;
class Solution {
private:
    unordered_map<string, int> mapping_1 = {
        {"一", 1}, {"二", 2}, {"三", 3}, {"四", 4}, {"五", 5}, 
        {"六", 6}, {"七", 7}, {"八", 8}, {"九", 9},
    };
    unordered_map<string, int> mapping_2 = {
        { "十", 10}, {"百", 100}, {"千", 1000}, {"万", 10000}, 
        {"十万", 100000}, {"百万", 1000000}, {"千万", 10000000}, {"亿", 100000000},
    };
public:
    //32w 三十二万
    int trans(string s) {
        int index = 0;
        int result = 0;
        while (index < s.length()-1) {
            string str1 = "", str2 = "";
            char c1 = s[index];
            char c2 = s[index+1];
            str1 += c1;
            str2 += c2;
            if (mapping_1.find(str1) != mapping_1.end()) {
                if (str2 == "万" || str2 == "亿") {
                    result = (result+mapping_1[str1]) * mapping_2[str2];
                } else {
                    result = result +mapping_1[str1]*mapping_2[str2] ; 
                }
                index += 2;
            } else if (mapping_2.find(str1) != mapping_2.end()){
                result = mapping_2[str1]*result;
                index ++;
            } else {
                index ++;
                continue;
            }
            cout << result << endl;
        }
        string str = "";
        str.append(1, s.length()-1);
        if (mapping_1.find(str) != mapping_1.end()) {
            result += mapping_1[str];
        } else {
            result *= mapping_2[str];
        }

        return result;
    }
};

int main() {
    Solution* so = new Solution();
    std::cout << so->trans("三千五百四十二万五千三百六十八亿七千九百六十万零五千二百三十八") << std::endl;
}
