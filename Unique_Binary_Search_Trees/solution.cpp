#include <iostream>
#include <vector>

using std::vector;
class Solution {
    public:
    int numTrees(int n) {
        // G(n) = G(1-1)*G(n-1)+G(2-1)*G(n-2)+G(3-1)*G(n-3)...+G(n-1)*G(n-n)
        // G(n) = G(0)*G(n-1)+G(1)*(n-2)+G(2)*(n-3)...+G(n-1)*G(0)
        vector<int> G(n+1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }

        return G[n];
    }
};

int main() {
    Solution* so = new Solution();
    std::cout << "n=3: " << so->numTrees(3) << std::endl;
    std::cout << "n=5: " << so->numTrees(5) << std::endl;
    std::cout << "n=1: " << so->numTrees(1) << std::endl;
    std::cout << "n=8: " << so->numTrees(8) << std::endl;
    std::cout << "n=19: " << so->numTrees(19) << std::endl;
}
