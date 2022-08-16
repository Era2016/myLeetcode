#include <iostream>
#include <vector>
#include "../utils/listNode.h"

using std::vector;
// a->b->c->d->e->f
// a->d->c->b->e->f
class Solution {
public:
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
