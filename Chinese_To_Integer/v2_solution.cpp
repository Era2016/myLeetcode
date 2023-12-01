#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int ChineseToNumber(wstring s)
{
    map<wchar_t, int> chineseNum;
    chineseNum.insert(pair<wchar_t, int>(L'零', 0));
    chineseNum.insert(pair<wchar_t, int>(L'一', 1));
    chineseNum.insert(pair<wchar_t, int>(L'二', 2));
    chineseNum.insert(pair<wchar_t, int>(L'三', 3));
    chineseNum.insert(pair<wchar_t, int>(L'四', 4));
    chineseNum.insert(pair<wchar_t, int>(L'五', 5));
    chineseNum.insert(pair<wchar_t, int>(L'六', 6));
    chineseNum.insert(pair<wchar_t, int>(L'七', 7));
    chineseNum.insert(pair<wchar_t, int>(L'八', 8));
    chineseNum.insert(pair<wchar_t, int>(L'九', 9));
    chineseNum.insert(pair<wchar_t, int>(L'十', 10));
    chineseNum.insert(pair<wchar_t, int>(L'百', 100));
    chineseNum.insert(pair<wchar_t, int>(L'千', 1000));
    chineseNum.insert(pair<wchar_t, int>(L'万', 10000));
    chineseNum.insert(pair<wchar_t, int>(L'亿', 100000000));

    int result=0, tmp = 0, hnd_mln=0;
    wchar_t curr_char;
    int curr_digit;
    for (int i = 0; i < s.length(); ++i)
    {
        curr_char = s.at(i);
        if (chineseNum.find(curr_char) == chineseNum.end())
            return 0;
        curr_digit = chineseNum.at(curr_char);

        if (curr_digit == pow(10, 8))//meet 「亿」 or 「億」
        {
            result = result + tmp;
            result = result * curr_digit;
            //get result before 「亿」 and store it into hnd_mln
            //reset `result`
            hnd_mln = hnd_mln * pow(10, 8) + result;
            result = 0;
            tmp = 0;
        }
        else
        {
            if (curr_digit == pow(10, 4))//meet 「万」 or 「萬」
            {
                result = result + tmp;
                result = result * curr_digit;
                tmp = 0;
            }
            else
            {
                if (curr_digit >= 10)//meet 「十」, 「百」, 「千」 or their traditional version
                {
                    if (tmp == 0)
                        tmp = 1;
                    result = result + curr_digit * tmp;
                    tmp = 0;
                }
                else
                {
                    tmp = tmp * 10 + curr_digit;
                    /*if (curr_digit != NULL)

                    else
                    {
                        return result;
                    }*/
                }
            }
        }
    }
    result = result + tmp;
    result = result + hnd_mln;
    return result;
}

template <class T>
int getArrayLen(T& array)
{//使用模板定义一 个函数getArrayLen,该函数将返回数组array的长度
    return (sizeof(array) / sizeof(array[0]));
}

int main() {
    //wcout.imbue(locale("chs"));
    wstring chineseNumber1 = L"三千五百四十二万五千三百六十八亿七千九百六十万零五千二百三十八";
    wstring chineseNumber2 = L"三十亿零五千万零三";

    int number1 = ChineseToNumber(chineseNumber1);
    int number2 = ChineseToNumber(chineseNumber2);
    cout << number1 << endl;
    cout << number2 << endl;

    //wcout << chineseNumber1 << " -> " << number1 << endl;
    //wcout << chineseNumber2 << " -> " << number2 << endl;
    return 0;
}
