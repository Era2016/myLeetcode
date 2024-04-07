#include <iostream>
#include <vector>

#include "../utils/listNode.h"
using std::vector;

class Solution {
private:
    // [ , )
    ListNode* reverseBetween(ListNode* head, ListNode* tail) {
        ListNode *prev = nullptr, *ptr = head;
        while (ptr != tail) {
            ListNode *next = ptr->next;
            ptr->next = prev;

            prev = ptr;
            ptr = next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head), *prev = dummy;    
        for (int i = 1; i < left; i ++) {
            prev = prev->next;
        }

        ListNode *ptr = prev->next;
        // 实际上从left到right共移动(right-left)次
        for (int i = left; i < right; i ++) {
            ListNode *next = ptr->next;
            ptr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy->next;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
    
        ListNode* dummy = new ListNode(-1, head), *prev = dummy;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            ListNode *tail = ptr;
            int i;
            for (i = 1; i <= k && tail; i ++) {
                tail = tail->next; 
            }
            if (i <= k) return dummy->next;

            ListNode *next = tail;
            prev->next = reverseBetween(ptr, tail);
            ptr->next = next;

            prev = ptr;
            ptr = next;
        }
        return dummy->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k, bool isNum) {
        if (!head) return nullptr;

        ListNode *dummy = new ListNode(-1, head), *prev = dummy;
        ListNode *ptr = head;
        while (ptr != nullptr) {
            ListNode *tail = ptr;
            int i = 1;
            while (i < k) {
                tail = tail->next;
                if (!tail) return dummy->next;
                i ++;
            }

            // 有可能同时不符合条件
            //if (i < k) return dummy->next;
            
            ListNode *next = tail->next;
            prev->next = reverseBetween(ptr, 1, k);
            ptr->next = next;

            prev = ptr;
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
    //head = so->reverseKGroup(head, 2);
    //showList(head);
    head = so->reverseKGroup(head, 2, 1);
    showList(head);

    v = {1,2,3,4,5,6,7};
    head = createList(v);
    showList(head);
    //head = so->reverseKGroup(head, 3);
    //showList(head);
    head = so->reverseKGroup(head, 3, 1);
    showList(head);

    v = {1,2,3,4,5};
    head = createList(v);
    showList(head);
    //head = so->reverseKGroup(head, 2);
    //showList(head);
    head = so->reverseKGroup(head, 2, 1);
    showList(head);

    v = {1,2};
    head = createList(v);
    showList(head);
    //head = so->reverseKGroup(head, 2);
    //showList(head);
    head = so->reverseKGroup(head, 2, 1);
    showList(head);
}
