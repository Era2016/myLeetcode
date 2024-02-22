#include <iostream>
#include <vector>

#include "../utils/listNode.h"

using std::vector;
class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(-1, head), *prev = dummy;
        while (head != nullptr) {
            ListNode *next1 = head->next;
            if (next1 == nullptr) return dummy->next;
            ListNode *tmp = next1->next;

            prev->next = next1;
            next1->next = head;
            head->next = tmp;

            prev = head;
            head = tmp;
        }
        return dummy->next;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    ListNode *head;

    v = {1,2,3,4};
    head = createList(v);
    showList(head);
    head = so->swapPairs(head);
    showList(head);

    v = {1,2,3,4,5};
    head = createList(v);
    showList(head);
    head = so->swapPairs(head);
    showList(head);

    v = {1};
    head = createList(v);
    showList(head);
    head = so->swapPairs(head);
    showList(head);
}
