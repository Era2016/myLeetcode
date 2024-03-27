#include <iostream>
#include <ratio>
#include <vector>

#include "../utils/listNode.h"

using std::vector;
class Solution {
public:
    // insertSort
    ListNode *sortListV1(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode *dummy = new ListNode(-1, head);
        ListNode *sorted = head;
        ListNode *curr = head->next;
        while (curr != nullptr) {
            if (curr->val >= sorted->val) {
                sorted = sorted->next;
            } else {
                ListNode *prev = dummy;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }

                sorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = sorted->next;
        }

        return dummy->next;
    }

    ListNode* midList(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        return prev;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *ptr = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            
            ptr = ptr->next;
        }

        if (l1 != nullptr) {
            ptr->next = l1;
        }

        if (l2 != nullptr) {
            ptr->next = l2;
        }
        return dummy->next;
    }

    // mergeSort
    ListNode *sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }        
    
        ListNode *mid = midList(head);
        ListNode *l2 = mid->next;
        mid->next = nullptr;
        ListNode *l1 = head;

        l1 = sortList(l1);
        l2 = sortList(l2);
        return merge(l1, l2);
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    ListNode *head;

    v = {4,2,1,3};
    head = createList(v);
    head = so->sortList(head); 
    showList(head);

    v = {-1,5,3,4,0};
    head = createList(v);
    head = so->sortList(head); 
    showList(head);
}
