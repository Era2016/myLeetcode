#include <iostream>
#include <vector>

#include "../utils/listNode.h"
using std::vector;
using std::string;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(), *head = dummy;
        int carry = 0;
        int n1 = 0, n2 = 0;
        while (l1 || l2) {
            n1 = l1 == nullptr? 0: l1->val;
            n2 = l2 == nullptr? 0: l2->val;
            
            int val = n1+n2+carry;
            carry = val / 10;
            ListNode *node = new ListNode(val%10);
            head->next = node; 
            head = head->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry != 0) {
            ListNode *node = new ListNode(carry%10);
            head->next = node;
            head = head->next;
        }

        return dummy->next;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v1, v2;
    ListNode *l1, *l2;
    ListNode *head;

    v1 = {2,4,3}, v2 = {5,6,4};
    l1 = createList(v1), l2 = createList(v2);
    head = so->addTwoNumbers(l1, l2);
    showList(head);

    v1 = {0}, v2 = {0};
    l1 = createList(v1), l2 = createList(v2);
    head = so->addTwoNumbers(l1, l2);
    showList(head);

    v1 = {9,9,9,9,9,9,9}, v2 = {9,9,9,9};
    l1 = createList(v1), l2 = createList(v2);
    head = so->addTwoNumbers(l1, l2);
    showList(head);
}
