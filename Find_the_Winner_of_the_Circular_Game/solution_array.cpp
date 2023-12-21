#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int Josephus(int n, int k) {
        vector<int> visited(n, 1);
        int cnt = 0;
        int i = 0;
        while (cnt != n - 1) {
            int tmp = 0;
            //i = (i + n) % n;
            while (tmp < k) {
                i = (i + n) % n;
                if (visited[i] == 1) {
                    tmp ++;
                    i ++;
                } else {
                    i ++;
                }
            }
            i = (i - 1 + n) % n;
            visited[i] = 0;
            cnt ++;
        }
        for (int i = 0; i < n; i++)
            if (visited[i] == 1)
                return i + 1;

        return -1;  //为了让编译通过
    }
    
};

int main() {
    Solution *so = new Solution();

    std::cout << so->Josephus(3, 1) << std::endl; //2
    std::cout << so->Josephus(3, 2) << std::endl; //2
    std::cout << so->Josephus(5, 2) << std::endl; //2
    std::cout << so->Josephus(5, 3) << std::endl; //1
}
