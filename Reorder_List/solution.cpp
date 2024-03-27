#include <iostream>
#include <vector>

#include "../utils/listNode.h"

using std::vector;
using std::string;
class Solution {
private:
    ListNode* getMidListNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *next = head->next;
        ListNode *pHead = reverseList(head->next);
        next->next = head;
        head->next = nullptr;
        return pHead;
    }
public:
    void reorderList(ListNode* head) {
        if (!head) return;

        ListNode *mid = getMidListNode(head);
        ListNode *l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        ListNode *l1 = head;

        while (l1 && l2) {
            ListNode *ptr1 = l1->next;
            ListNode *ptr2 = l2->next;
            
            l2->next = l1->next;
            l1->next = l2;

            l1 = ptr1;
            l2 = ptr2;
        }
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    ListNode *head;

    v = {1,2,3,4};
    head = createList(v);
    so->reorderList(head);
    showList(head);

    v = {1,2,3,4,5};
    head = createList(v);
    so->reorderList(head);
    showList(head);
}
