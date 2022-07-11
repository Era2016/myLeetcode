#include <iostream>
#include <vector>
#include "listNode.h"

ListNode* createList(std::vector<int>& v) {
    if (v.empty()) return nullptr;
    
    ListNode *dummy = new ListNode(-1), *ptr = dummy;
    for (int i = 0; i < v.size(); i ++) {
    //for (auto k: v) {
        ListNode* p = new ListNode(v[i]);
        
        ptr->next = p;
        ptr = p;
    }

    return dummy->next;
}

void showList(ListNode* p) {
    while (p) {
        std::cout << p->val << "\t";
        p = p->next;
    }

    std::cout << std::endl << std::endl;
}

ListNode* reverse(ListNode* head) {
    ListNode* dummy = new ListNode(-1), *pHead = dummy;
    ListNode* ptr = head;
    while (ptr) {
        ListNode* tmp = ptr->next;

        ptr->next = dummy->next;
        dummy->next = ptr;

        ptr = tmp;
    }
    //dummy->next = nullptr;
    return pHead->next;
}
