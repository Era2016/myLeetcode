#include <iostream>
#include <vector>
#include "listNode.h"

ListNode* createList(std::vector<int>& v) {
    if (v.empty()) return nullptr;
    
    ListNode *pHead, *ptr;
    for (int i = 0; i < v.size(); i ++) {
    //for (auto k: v) {
        ListNode* p = new ListNode(v[i]);
        if (i == 0) { 
            pHead = p; ptr = p;
        }
        
        ptr->next = p;
        ptr = p;
    }

    return pHead;
}

void showList(ListNode* p) {
    while (p) {
        std::cout << p->val << "\t";
        p = p->next;
    }

    std::cout << std::endl << std::endl;
}
