#include <iostream>
#include <vector>

#include "../utils/listNode.h"

using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
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
