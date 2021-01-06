#include <iostream>
#include <vector>
#include <map>

using namespace std;
void print(vector<char>);

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 31;
        while (n != 0) {
            ret += (n & 1) << power;
            n = n >> 1;
            power -= 1;
        }
        return ret;
    }
    
	uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t> cache) {
        if (cache.find(byte) != cache.end()) {
            return cache[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.emplace(byte, value);
        return value;
    }

	// 利用内存缓存计算结果，避免重复计算
	// 适用于多次调用场景
    uint32_t reverseBits_V2(uint32_t n) {
        uint32_t ret = 0, power = 24;
        map<uint32_t, uint32_t> cache;
        while (n != 0) {
            ret += reverseByte(n & 0xff, cache) << power;
            n = n >> 8;
            power -= 8;
        }
        return ret;
    }

private:
    uint32_t reverseBitsFromNumber(uint32_t n) {
        vector<char> v(32, '0');
        transToBits(v, n);

        uint32_t ret = 0;
        int shift = 1;
        for (int i = (int)v.size()-1; i >= 0; i --) {
            ret += shift * (v[i]-'0');
            shift <<= 1;
        }
        return ret;
    }

    void transToBits(vector<char>& v, uint32_t n) {
    	for (int i = 0; i < 32 && n != 0; i ++) {
            v[i] = n % 2 + '0';
    		n /= 2;
    	}

        return;
    }
};

void print(vector<char> v) {
	for (int i = 0; i < (int)v.size(); i ++) {
		cout << v[i];
	}
	cout << endl;
}

int main() {
	Solution* so = new Solution();
    uint32_t input;
    uint32_t output;

    input = 10;
   	output = so->reverseBits(input);
    cout << output << endl;

    input = 43261596; 
    //output = so->reverseBits(input);
    output = so->reverseBits_V2(input);
    cout << output << endl;

    input = 4294967293; 
    //output = so->reverseBits(input);
    output = so->reverseBits_V2(input);
    cout << output << endl;
}
