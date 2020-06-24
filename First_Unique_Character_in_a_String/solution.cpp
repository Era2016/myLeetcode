#include <iostream>

using namespace std;

class Solution {
    public:
        int firstUniqChar(string s) {
            int hash[256] = {0};
            for (int i = 0; i < (int)s.length(); ++ i) {
                hash[s[i]] ++;
            }

            for (int i = 0; i < (int)s.length(); ++ i) {
                if (1 == hash[s[i]]) {
                    return i;
                }
            }
            return -1;
        }
};


int main()
{
    Solution* so = new Solution();
    string str = "HeoelolHa";
    int index = so->firstUniqChar(str);
    cout << str.length() << "\t"<<index << endl;
}
