#include <iostream>

using namespace std;
struct ListNode{
    ListNode *next;
    int val;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int val): val(val), next(nullptr) {};
    ListNode(int val, ListNode* next): val(val), next(next) {};
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        ListNode *dummy = new ListNode();
        ListNode *ptr = dummy;
        for (int i = 1; i <= n; i ++) {
            ListNode *node = new ListNode(i);
            ptr->next = node;
            ptr = ptr->next;
        }

        ptr->next = dummy->next;
        ListNode *prev = ptr;
        ptr = ptr->next;

        int cnt = n;
        while (cnt > 1) {
            for (int i = 1; i < k; i ++) {
                prev = ptr;
                ptr = ptr->next;
            }
            ListNode *toDelete = ptr;
            prev->next = ptr->next;
            ptr = ptr->next;
            delete(toDelete);
            cnt --;
        }

        return ptr->val;
    }
};

int main() {
    int n = 7; // 总人数
    int m = 3; // 数到第 m 个人

    Solution *so = new Solution();
    cout << "The survivor is at position: " << so->findTheWinner(3, 1) << endl;
    cout << "The survivor is at position: " << so->findTheWinner(3, 2) << endl;
    cout << "The survivor is at position: " << so->findTheWinner(5, 2) << endl;
    cout << "The survivor is at position: " << so->findTheWinner(5, 3) << endl;

    return 0;
}
