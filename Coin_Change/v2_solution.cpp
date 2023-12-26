#include <ctime>
#include <iostream>
#include <vector>

using std::vector;

/*
 * 贪心算法
 * */
class Solution {
private:
    int res;
    vector<int> tmp;
    void dfs(vector<int>& coins, int idx, int amount, int cnt) {
        if (amount == 0) {
            res = std::min(res, cnt);
            std::cout << ">>>>>>" << std::endl;
            for (auto& v: tmp) {
                std::cout << v << " ";
            }
            std::cout << std::endl << "<<<<<<<" << std::endl;
            return;
        } 
        if (amount < 0) {
            return;
        }
        for (int i = idx; i < coins.size(); i ++) {
            if (amount-coins[i] < 0) {
                continue;
            }
            tmp.emplace_back(coins[i]);
            dfs(coins, i, amount-coins[i], cnt+1);
            tmp.pop_back();
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), std::greater<int>());

        res = INT_MAX;
        dfs(coins, 0, amount, 0);
        return res==INT_MAX? -1: res;
    }
};

int main() {
    Solution* so = new Solution();
    vector<int> v;

    //v = {1,2,5};
    //std::cout << so->coinChange(v, 11) << std::endl;

    //v = {1,7,10};
    //std::cout << so->coinChange(v, 14) << std::endl;

    clock_t start,end;
    start = clock();
    v = {411,412,413,414,415,416,417,418,419,420,421,422};
    std::cout << so->coinChange(v, 9864) << std::endl; // timeout
    end = clock();
    std::cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<< std::endl;
}
