#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    // 内存超限
    vector<vector<int>> memo;
    int dp(string s1, int m, string s2, int n) {
        int sum = 0;
        if (m == 0) {
            std::for_each(s2.begin(), s2.begin()+n, [&sum](char c) {sum += c;});
            memo[m][n] = sum;
            return sum;
        }
        if (n == 0) {
            std::for_each(s1.begin(), s1.begin()+m, [&sum](char c) {sum += c;});
            memo[m][n] = sum;
            return sum;
        }
        if (memo[m][n] != -1) {
            return memo[m][n];
        }
        
        if (s1[m-1] == s2[n-1]) {
            memo[m][n] = dp(s1, m-1, s2, n-1);
        } else {
            memo[m][n] = std::min(dp(s1, m-1, s2, n)+s1[m-1], dp(s1, m, s2, n-1)+s2[n-1]);
        }
        return memo[m][n];
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        this->memo = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        return dp(s1, m, s2, n);
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->minimumDeleteSum("sea", "eat") << std::endl; // 231
    std::cout << so->minimumDeleteSum("delete", "leet") << std::endl; // 403
    std::cout << so->minimumDeleteSum("llrseubegfbbforocgnpemtubqiumwgfmgdkhjtsyjbndtgbxdkwzzockdntxkipkpcaqetreyhrubneiidagirzvsqjhirdcyqbxjsxqfuhmblkqszlkhmvhlhwvworivjtagkvhrfhgeeeevvcsiygyfpeepmxekvhkuryjpsckilzvgpdfkcmqcmrpxvnazdodlsgftggehzltfsarvjexpgvzqnwzlbeeagakyrvaylgjyfautcnubojohvfbzziaudfkloxcelmqwzwqvlwmfmjqmkzcztceoxsakfmjfpwfvhmurvrkouavxgxkdepvzktttthfakppkipwdnpwjgrmywtxwtnsfwaawsljgychkgpwmuoywizqcwppyqzaevgmefudmoabxnjnnuibdiwocwaqoitltgwnbpqfajkuzbescdlrzltaxjrfajbnqe", "qkynliglsdnadlyoofjcvwcrwuuqjoqqobyebajhyakcbxqjzdntluzjjktukbxrpqnebnquplklpzkyfjnqeoicukwimvknxevvuzminepdltysbmkgcgpfzqddzgrohpqtlbqxujfetgjcbyqrtwjczrfcngcmuykruwaypcscujrhecjeualpswrtptxbommmvmayehpmfmyerjwoaohexrorqntvkqemdrqhlmjymtus") << std::endl; // 54344
}
