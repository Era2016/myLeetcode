#include <iostream>
#include <unordered_map>

using std::string;
using std::unordered_map;
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> um{ 
            {1,'I'}, {5,'V'}, {10, 'X'}, {50, 'L'},
            {100, 'C'}, {500, 'D'}, {1000, 'M'},
        };

        string result;
        int bitsNum = 1;
        while (num != 0) {
            int end = num % 10;
            num /= 10;
            switch (end) {
                case 1: case 2: case 3:
                    result = result.insert(0, end, um[1*bitsNum]);
                    break;
                case 4:
                    result = result.insert(0, 1, um[5*bitsNum]);
                    result = result.insert(0, 1, um[1*bitsNum]);
                    break;
                case 5:
                    result = result.insert(0, 1, um[end*bitsNum]);
                    break;
                case 6: case 7: case 8:
                    result = result.insert(0, end-5, um[1*bitsNum]);
                    result = result.insert(0, 1, um[5*bitsNum]);
                    break;
                case 9:
                    result = result.insert(0, 1, um[10*bitsNum]);
                    result = result.insert(0, 1, um[1*bitsNum]);
                    break;
                //case 0:
                //    result = result.insert(0, um[10*bitsNum], 1);
                //    break;

            }
            bitsNum *= 10;
        }

        return result;
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->intToRoman(3) << std::endl;
    std::cout << so->intToRoman(4) << std::endl;
    std::cout << so->intToRoman(9) << std::endl;
    std::cout << so->intToRoman(58) << std::endl;
    std::cout << so->intToRoman(1994) << std::endl;
    std::cout << so->intToRoman(1600) << std::endl;
}
