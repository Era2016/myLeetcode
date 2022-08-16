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
ListNode* reverseBetween_v2(ListNode* head, int left, int right) {
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

/*
 * curr：指向待反转区域的第一个节点 left；
 * next：永远指向 curr 的下一个节点，循环过程中，curr 变化以后 next 会变化；
 * pre：永远指向待反转区域的第一个节点 left 的前一个节点，在循环过程中不变。
 *
 */

// a->b->c->d->e->f
// a->c->b->d->e->f
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *pre = dummyNode;
    for (int i = 0; i < left - 1; i ++) {
        pre = pre->next;
    }

    ListNode *cur = pre->next;  // cur -> b; pre -> a
    ListNode *next;             // next ->c;
    for (int i = 0; i < right - left; i ++) {
        next = cur->next;

        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }

    return dummyNode->next;
}

// 反转以 head 为起点的 n 个节点，返回新的头结点
ListNode *successor;
ListNode* reverseN(ListNode *head, int n) {
    if (n == 1) {
        // 记录第 n + 1 个节点
        successor = head->next;
        return head;
    }
    // 以 head.next 为起点，需要反转前 n - 1 个节点
    ListNode *last = reverseN(head->next, n - 1);

    head->next->next = head;
    // 让反转之后的 head 节点和后面的节点连起来
    head->next = successor;
    return last;
}

ListNode* reverseBetweenRecursively(ListNode *head, int m, int n) {
    // base case
    if (m == 1) {
        return reverseN(head, n);
    }
    // 前进到反转的起点触发 base case
    head->next = reverseBetweenRecursively(head->next, m - 1, n - 1);
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
