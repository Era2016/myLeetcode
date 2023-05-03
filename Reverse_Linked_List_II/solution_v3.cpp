#include <iostream>
#include <vector>

#include "../utils/listNode.h"

using std::vector;

class Solution {
private:
    ListNode *successor;
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }
        ListNode* newHead = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = successor; 
        return newHead;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left-1, right-1);
        return head;
    }
};
