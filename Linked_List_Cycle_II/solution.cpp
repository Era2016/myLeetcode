#include <iostream>
#include <vector>
#include <cassert>

#include "../utils/listNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }

        if (!fast || !fast->next) return nullptr;

        ListNode* ptr = head; 
        ListNode* pp = fast;
        while (ptr != pp) {
            ptr = ptr->next;
            pp = pp->next;
        }
        return ptr;
    }

    // not work in leetcode
    ListNode *detectCycle(ListNode *head, int& index) {
        ListNode* pCross;
        bool cycle = isCycle(head, pCross);
        if (!cycle) return nullptr;

        ListNode* ptr = head;
        while (ptr != pCross) {
            ptr = ptr->next;
            pCross = pCross->next;
            index ++;
        }
        return ptr;
    }
};

int main() {
    Solution *so;
    std::vector<int> v;
    ListNode* head;

    v = {3,2,0,-4};
    head = createRingList(v,1);
    assert(isCycle(head, nullptr) == true);

    //head = createRingList(v,-1);
    //assert(isCycle(head, nullptr) == true);

    int index = 0;
    //so->detectCycle(head, index);
    so->detectCycle(head);
    //std::cout << "cross at: " << index << std::endl;


    v = {0,1};
    head = createRingList(v,0);
    assert(isCycle(head, nullptr) == true);

    index = 0;
    so->detectCycle(head, index);
    std::cout << "cross at: " << index << std::endl;

}
