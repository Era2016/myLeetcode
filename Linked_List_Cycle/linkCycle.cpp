#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p1 = head, *p2 = head;
        while (p1 != NULL && p2 != NULL) {
            p1 = p1->next;
            if (p2->next != NULL) {
                p2 = p2->next->next;
            } else {
                return false;
            }

            if (p1 == p2) {
                return true;
            } 
        }
        
        return false;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(1);
    ListNode* n4 = new ListNode(1);
    ListNode* n5 = new ListNode(1);
    ListNode* n6 = NULL;
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2;
    Solution* so = new Solution();
    cout << so->hasCycle(n1) << endl;
    cout << so->hasCycle(n5) << endl;
    cout << so->hasCycle(n6) << endl;
}
