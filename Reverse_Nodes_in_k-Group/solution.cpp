#include <iostream>
#include <vector>
#include "../utils/listNode.h"

using std::vector;
using std::pair;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *ptr = head, *pre = dummy;
        while (ptr != nullptr) {
            ListNode *tail = ptr;
            for (int cnt = 1; cnt < k; cnt ++) {
                tail = tail->next;
                if (tail == nullptr) return dummy->next;
            }

            ListNode *next = tail->next;

            auto nodes = reverseBetween(ptr, tail);
            pre->next = nodes.first;
            nodes.second->next = next;

            pre = nodes.second;
            ptr = next;
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

    v = {1,2};
    head = createList(v);
    showList(head);
    head = so->reverseKGroup(head, 2);
    showList(head);
}
