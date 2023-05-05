#include <iostream>
#include <vector>
#include "../utils/listNode.h"

using std::vector;
using std::pair;
class Solution {
private:
    // 左闭右开
     ListNode* reverseBetween(ListNode* head, ListNode* tail) {
        ListNode *pre = nullptr, *cur = head;
        while (cur != tail) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
       }
        return pre; 
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ptr = head;
        for (int cnt = 1; cnt <= k; cnt ++) {
            if (ptr == nullptr) return head;
            ptr = ptr->next;
        }
        
        ListNode *newHead = reverseBetween(head, ptr);
        head->next = reverseKGroup(ptr, k);
        return newHead;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    ListNode *head;

    v = {1,2,3,4,5,6};
    head = createList(v);
    showList(head);
    head = so->reverseKGroup(head, 2);
    showList(head);

    v = {1,2,3,4,5,6,7};
    head = createList(v);
    showList(head);
    head = so->reverseKGroup(head, 3);
    showList(head);

    v = {1,2,3,4,5};
    head = createList(v);
    showList(head);
    head = so->reverseKGroup(head, 2);
    showList(head);

    v = {1,2};
    head = createList(v);
    showList(head);
    head = so->reverseKGroup(head, 2);
    showList(head);
}
