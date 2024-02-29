#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    int cnt;
    string res;
    bool backtrack(string &str, int n, int k, vector<int>& visit) {
        if (str.length() == n) {
            cnt ++;
            if (cnt == k) { 
                res = str;
                return true;
            }
            return false;
        }
        
        for (int i = 0; i < n; i ++) {
            if (visit[i]) continue;
            visit[i] = true;
            str.push_back(i+1+'0');
            if (true == backtrack(str, n, k, visit)) {
                return true;
            }
            visit[i] = false;
            str.pop_back();
        }
        return false;
    }
public:
    string getPermutation(int n, int k) {
        this->cnt = 0;
        this->res = "";
        vector<int> visit(n, 0);
        string str;
        backtrack(str, n, k, visit);
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->getPermutation(3, 3) << std::endl;
    std::cout << so->getPermutation(4, 9) << std::endl;
    std::cout << so->getPermutation(3, 1) << std::endl;
}
