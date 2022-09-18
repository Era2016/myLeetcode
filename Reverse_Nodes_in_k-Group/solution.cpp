#include <iostream>
#include <utility>
#include <vector>
#include "../utils/listNode.h"

using std::pair;
using std::vector;

class Solution {
private:
    pair<ListNode*, ListNode*> reverseBetween(ListNode* head, ListNode* tail) {
        ListNode *pre = nullptr, *cur = head;
        while (pre != tail) {
            ListNode *next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return {tail, head};
    }

public:
    ListNode* reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *pre, *start, *end;
        pre = dummy;
        end = start = dummy->next;
        while (start) {
            for (int i = 0; i < k-1; i ++) {
                end = end->next;
                if (end == nullptr)
                    return dummy->next;
            }

            ListNode *next = end->next;

            pair<ListNode*, ListNode*> p = reverseBetween(start, end);
            pre->next = p.first;
            p.second->next = next;

            pre = p.second;
            start = next;
            end = start;
        }

        return dummy->next;
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
}
