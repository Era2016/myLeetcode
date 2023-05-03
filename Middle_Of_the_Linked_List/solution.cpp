#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int _val): val(_val), next(nullptr) {}
    ListNode(int _val, ListNode *_next): val(_val), next(_next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *fast = head, *small = head;
        while (fast != nullptr && fast->next != nullptr) {
            small = small->next;
            fast = fast->next->next;
        }
        return small;
    }
};
