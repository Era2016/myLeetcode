#include <iostream>
#include <queue>

using std::queue;
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i ++) {
            q.push(i);
        }

        int left = n;
        while (left > 1) {
            for (int i = 1; i < k; i ++) {
                q.push(q.front());
                q.pop();
            }
            std::cout << "val: " << q.front() << std::endl;
            q.pop();
            left --;
        }
        return q.front();
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->findTheWinner(3,1) << std::endl;
    std::cout << so->findTheWinner(3,2) << std::endl;
    std::cout << so->findTheWinner(5,2) << std::endl;
    std::cout << so->findTheWinner(5,3) << std::endl;
}
