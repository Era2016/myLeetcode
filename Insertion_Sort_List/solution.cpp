#include <iostream>
#include <vector>

#include "../utils/listNode.h"

using std::vector;
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode *dummyHead = new ListNode(0, head);
        ListNode *lastSorted = head;
        ListNode *curr = head->next;

        while (curr != nullptr) {
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode *prev = dummyHead;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        return dummyHead->next;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    ListNode *head;

    v = {4,2,1,3};
    head = createList(v);
    head = so->insertionSortList(head);
    showList(head);
}
