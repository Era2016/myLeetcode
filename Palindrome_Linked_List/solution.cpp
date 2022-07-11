#include <iostream>
#include <vector>
#include <cassert>
#include "../utils/listNode.h"

class Solution {
private:
    ListNode* findMid(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast != nullptr) return slow->next; 
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMid(head);
        ListNode* rmid = reverse(mid);

        while (rmid != nullptr) {
            if (head->val != rmid->val) return false;
            head = head->next;
            rmid = rmid->next;
        } 
        return true;
    }
};

int main() {
    Solution* so;
    std::vector<int> v;
    ListNode* head;

    v = {1,2,3,4};
    head = createList(v); 
    //showList(head);
    //head = reverse(head);
    //showList(head);
    assert(so->isPalindrome(head) == false);

    v = {1,2,2,1};
    head = createList(v); 
    //showList(head);
    //head = reverse(head);
    //showList(head);
    assert(so->isPalindrome(head) == true);

    v = {1,2,3,2,1};
    head = createList(v); 
    //showList(head);
    //head = reverse(head);
    //showList(head);
    assert(so->isPalindrome(head) == true);

    std::cout<<"test success" << std::endl;
}
