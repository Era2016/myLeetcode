#include <iostream>
#include <vector>

using namespace std;
void print(vector<char>);

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            vector<char> v;
    		for (int i = 0; i < 32 && n != 0; i ++) {
                v.push_back(n % 2 + '0');
    			n /= 2;
    		}
            print(v);

            uint32_t ret = 0;
            int shift = 1;
            for (int i = (int)v.size()-1; i > 0; i --) {
                ret += shift * (v[i]-'0');
                shift <<= 1;
            }
        	return ret;
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
    output = so->reverseBits(input);
    cout << output << endl;

    input = 4294967293; 
    output = so->reverseBits(input);
    cout << output << endl;
}
