#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

unordered_map<wchar_t, int> unitMap = {{L'十', 10}, {L'百', 100}, {L'千', 1000}, {L'万', 10000}, {L'亿', 100000000}};
unordered_map<wchar_t, int> chineseDigitMap = {{L'一', 1}, {L'二', 2}, {L'三', 3}, {L'四', 4}, {L'五', 5}, 
    {L'六', 6}, {L'七', 7}, {L'八', 8}, {L'九', 9}};

int ChineseToNumber(const string& chineseNumber) {
    int result = 0;
    int currentNumber = 0;
    int lastNumber = 0;
    int tempResult = 0;

    for (char ch : chineseNumber) {
        if (chineseDigitMap.find(ch) != chineseDigitMap.end()) {
            currentNumber = chineseDigitMap[ch];
        } else if (unitMap.find(ch) != unitMap.end()) {
            tempResult += (lastNumber == 0 ? 1 : lastNumber) * unitMap[ch];
            lastNumber = 0;
        } else {
            lastNumber = currentNumber;
            currentNumber = 0;
        }
    }

    result = tempResult + lastNumber + currentNumber;
    return result;
}

int main() {
    string chineseNumber1 = "三千五百四十二万五千三百六十八亿七千九百六十万零五千二百三十八";
    string chineseNumber2 = "三十亿零五千万零三";

    int number1 = ChineseToNumber(chineseNumber1);
    int number2 = ChineseToNumber(chineseNumber2);

    cout << chineseNumber1 << " -> " << number1 << endl;
    cout << chineseNumber2 << " -> " << number2 << endl;

    return 0;
}
