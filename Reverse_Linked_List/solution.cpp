#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL, *pre = head;
        while (pre != NULL) {
            ListNode* tmp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = tmp;
        }
        return cur;
    }
};

ListNode* construct(int cnt) {
    int i = 0;
    ListNode* head = new ListNode(-1);
    ListNode* ptr = head;
    while (i < cnt) {
        ListNode* node = new ListNode(i);
        ptr->next = node;
        ptr = ptr->next;
        i ++;
    }
    return head->next;
}

void print(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << std::endl;
        head = head->next;
    }
}

int main() {
    Solution *so = new Solution();
    
    ListNode *head = construct(5);
    //print(head);

    ListNode *newHead = so->reverseList(head);
    print(newHead);

}
