#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::string;

class Solution {
public:
    enum State {
        STATE_INITIAL,          // 初始状态
        STATE_INT_SIGN,         // 符号位
        STATE_INTEGER,          // 整数部分
        STATE_POINT,            // 左侧部分有整数的小数点
        STATE_POINT_WITHOUT_INT,// 左侧部分无整数的小数点
        STATE_FRACTION,         // 小数部分
        STATE_EXP,              // 字符e
        STATE_EXP_SIGN,         // 指数部分的符号位
        STATE_EXP_NUMBER,       // 指数部分的整数部分
        STATE_END               // 接受状态
    };

    enum CharType {
        CHAR_NUMBER,    // 数字
        CHAR_EXP,       // e/E
        CHAR_POINT,     // .
        CHAR_SIGN,      // +/-
        CHAR_ILLEGAL    // 异常
    };

    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {
                STATE_INITIAL, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                    {CHAR_SIGN, STATE_INT_SIGN}
                }
            }, {
                STATE_INT_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                }
            }, {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_POINT, STATE_POINT}
                }
            }, {
                STATE_POINT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP}
                }
            }, {
                STATE_POINT_WITHOUT_INT, {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            }, {
                STATE_FRACTION,
                {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP}
                }
            }, {
                STATE_EXP,
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SIGN, STATE_EXP_SIGN}
                }
            }, {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }, {
                STATE_EXP_NUMBER, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }
        };

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++) {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->isNumber("+3.14") << std::endl;
    std::cout << so->isNumber("95a54e53") << std::endl;
    std::cout << so->isNumber("3e+7") << std::endl;
    std::cout << so->isNumber("-.9") << std::endl;
}