#include <iostream>
#include <vector>

#include "../utils/listNode.h"

using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-101, head);
        ListNode *fast = head, *slow = dummy;
        while (fast != nullptr) {
            if (fast->next == nullptr) {
                slow->next = fast;
                slow = slow->next;
                slow->next = nullptr;
                break;
            }
            ListNode *ptr = fast->next;
            if (fast->val == ptr->val) { 
                while (ptr != nullptr && ptr->val == fast->val) {
                    ListNode *toDel = ptr;
                    ptr = ptr->next;
                    delete(toDel);
                }
                if (ptr == nullptr) {
                    slow->next = nullptr;
                    break;
                }
                fast = ptr;
            } else {
                slow->next = fast;
                slow = slow->next;
                fast = fast->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    ListNode *head;

    v = {1,2,3,3,4,4,5};
    head = createList(v);
    head = so->deleteDuplicates(head);
    showList(head);

    v = {1,1,1,2,3};
    head = createList(v);
    head = so->deleteDuplicates(head);
    showList(head);

    v = {1,1,1};
    head = createList(v);
    head = so->deleteDuplicates(head);
    showList(head);

    v = {1,2,2};
    head = createList(v);
    head = so->deleteDuplicates(head);
    showList(head);
}
