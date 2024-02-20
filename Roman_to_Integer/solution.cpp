#include <ios>
#include <iostream>
#include <iterator>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
private:
unordered_map<char, int> mapping = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
}; 
public:
int romanToInt(string s) {
    int integer = 0;
    int len = s.length();
    for (int i = 0; i < len; i ++) {
        if (i<len-1 && mapping[s[i]]<mapping[s[i+1]]) {
            integer -= mapping[s[i]];
        } else {
            integer += mapping[s[i]];
        }
    }
    return integer;
}
};

int main() {
    Solution *so = new Solution();

    std::cout << so->romanToInt("III") << std::endl;
    std::cout << so->romanToInt("IV") << std::endl;
    std::cout << so->romanToInt("IX") << std::endl;
    std::cout << so->romanToInt("LVIII") << std::endl; // 58
    std::cout << so->romanToInt("MCMXCIV") << std::endl; // 1994
}
