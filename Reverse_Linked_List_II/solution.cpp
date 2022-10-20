#include <iostream>
#include <vector>

#include "../utils/listNode.h"

using std::vector;

/*
 * 头插入法
 * curr：指向待反转区域的第一个节点 left；
 * next：永远指向 curr 的下一个节点，循环过程中，curr 变化以后 next 会变化；
 * pre：永远指向待反转区域的第一个节点 left 的前一个节点，在循环过程中不变。
 *
 */

// a->b->c->d->e->f
// a->c->b->d->e->f
// a->d->c->b->e->f
class Solution {
public:
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
};

int main() {
    Solution* so = new Solution();
    vector<int> v;
    ListNode *p = nullptr, *head = nullptr;
    
    v = {1,2,3,4,5,6};
    head = createList(v); 
    std::cout << "origin: " << std::endl;
    showList(head);
    std::cout << std::endl;

    //p = reverse(head);
    p = head;

    p = so->reverseBetween(p, 1, 6);
    showList(p);
    p = so->reverseBetween(p, 1, 6);
    showList(p);


    p = so->reverseBetween(p, 1, 3);
    showList(p);
    p = so->reverseBetween(p, 1, 3);
    showList(p);


    p = so->reverseBetween(p, 2, 4);
    showList(p);
    p = so->reverseBetween(p, 2, 4);
    showList(p);


    p = so->reverseBetween(p, 2, 6);
    showList(p);
    p = so->reverseBetween(p, 2, 6);
    showList(p);
}
