#include <iostream>

using namespace std;

class Solution {
public:
    // int有符号，可能会导致无限循环
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }

    int hammingWeight_V2(uint32_t n) {
        int count = 0, mask = 1;
        for (int i = 0; i < 32; i ++) {
            if (n & mask) { count ++; }
            mask <<= 1;
        }
        return count;
    }

    int hammingWeight_V3(uint32_t n) {
        int count = 0;
        while (n) {
            count ++;
            n = n & (n-1);
        }
        return count;
    }
};

int main() {
    Solution* so = new Solution();
    uint32_t number;
    int count;

    number = 5;
    //count = so->hammingWeight(number);
    //count = so->hammingWeight_V2(number);
    count = so->hammingWeight_V3(number);
    cout << "ret: " << count << endl;

    number = uint32_t(0b00000000000000000000000000001011);
    //count = so->hammingWeight(number);
    //count = so->hammingWeight_V2(number);
    count = so->hammingWeight_V3(number);
    cout << "ret: " << count << endl;

    number = 0b11111111111111111111111111111101;
    //count = so->hammingWeight(number);
    //count = so->hammingWeight_V2(number);
    count = so->hammingWeight_V3(number);
    cout << "ret: " << count << endl;
}
