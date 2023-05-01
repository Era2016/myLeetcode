#include <iostream>
#include "../utils/listNode.h"

using std::cout;
using std::endl;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *first = head, *second = dummy;
        int cnt = 1;
        while (first != nullptr && cnt <= n) {
            first = first->next;
            cnt ++;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        ListNode *toDelete = second->next;
        second->next = second->next->next;
        delete(toDelete);
        return dummy->next;
    }
};

ListNode* initList(int n) {
    ListNode *dummy = new ListNode(-1);
    ListNode *ptr = dummy;
    for (int i = 0; i < n; i ++) {
        ListNode *node = new ListNode(i+1);
        ptr->next = node;
        ptr = node;
    }
    return dummy->next;
}

void print(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->next) {
        cout << p->val << "\t";
    }
    cout << endl;
}

int main() {

    Solution* solution = new Solution();
    ListNode* pHead = initList(2);
    print(pHead); 

    ListNode* ptr = solution->removeNthFromEnd(pHead, 2);
    //cout << ptr->val << endl;
    print(ptr);
    return 0;
}
