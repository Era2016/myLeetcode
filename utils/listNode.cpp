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

ListNode* createRingList(std::vector<int>& v, int pos) {
    if (v.empty()) return nullptr;

    ListNode *dummy = new ListNode(-1), *ptr = dummy;
    ListNode *terminal = dummy, *p;
    for (int i = 0; i < v.size(); i ++) {
        p = new ListNode(v[i]);

        ptr->next = p;
        ptr = p;
        if (pos == i) terminal = p;
    }
    if (pos != -1) p->next = terminal;

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

// a->b->c->d->e->f
// a->d->c->b->e->f
ListNode* reverseBetween(ListNode* head, int left, int right) {
    int index = 1;
    ListNode *ptr = head;

    ListNode *prev1 = nullptr;
    while (ptr != nullptr && index < left) {
        prev1 = ptr;
        ptr = ptr->next; index ++;
    } // ptr == b, prev1 == a

    ListNode *dummy = new ListNode();//, *pTmpHead = dummy;
    ListNode *prev2 = nullptr;
    while (ptr != nullptr && index <= right) {
        ListNode *tmp = ptr->next;
        prev2 = ptr;

        ptr->next = dummy->next;
        dummy->next = ptr;

        ptr = tmp;
        index ++;
    } // ptr == e, prev2 == d

    if (prev1 == nullptr) {
        head->next = ptr;
        head = prev2;
    } else {
        prev1->next->next = ptr;
        prev1->next = prev2;
    }

    return head;
}


bool isCycle(ListNode* head, ListNode* pCross) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            if (pCross) pCross = fast;
            return true;
        }
    }

    return false;
}
