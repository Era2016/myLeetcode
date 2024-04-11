#include <iostream>
#include <vector>
#include "../utils/listNode.h"
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(): val(0), next(nullptr) {};
//    ListNode(int val): val(val), next(nullptr) {};
//    ListNode(int val, ListNode *next): val(val), next(next) {};
//};

using std::vector;
class Solution {
private:
    ListNode* reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        for (int i = 0; i < left - 1; i ++) {
            prev = prev->next;
        }

        ListNode *cur = prev->next;
        ListNode *next;
        int cnt = 0;
        while (cnt < right-left) {
            next = cur->next;

            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
            cnt ++;
        }
        return dummy->next;
    }

public:
    ListNode* reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;
        ListNode *cur = head;

        while (cur != nullptr) {
            ListNode *tail = cur;
            for (int i = 1; i < k && tail != nullptr; i ++) {
                tail = tail->next; 
            }
            if (tail == nullptr) {
                return dummy->next;
            }

            ListNode *next = tail->next; 
            prev->next = reverseBetween(cur, 1, k);
            cur->next = next;

            prev = cur;
            cur = prev->next;
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
