#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
        if (n <= 0) {
            return NULL;
        }

        ListNode *ptr_1, *ptr_2;
        ptr_1 = ptr_2 = head;
        int i = 0;
        for (; i < n && ptr_1 != NULL; i ++) {
            ptr_1 = ptr_1 -> next;
        }
        // n is too big
        if (i < n) {
            return NULL;
        }

        if (ptr_1 == NULL) {
            ListNode *pNode = head;
            head = head -> next;
            delete(pNode);
            return head;
        }

        while (ptr_1 -> next != NULL) {
            ptr_1 = ptr_1 -> next;
            ptr_2 = ptr_2 -> next;
        }

        ListNode* pNode = ptr_2 -> next;
        ptr_2 -> next = pNode -> next;
        delete(pNode);
        
        return head;
    }

    ListNode* initList(int n) {
        if (n <= 0) {
            return NULL;
        }

        ListNode *ptr = new ListNode();
        ListNode *pHead = ptr;
        ptr->val = 1;
        ptr->next = NULL;
        for (int i = 2; i <= n; i ++) {
            ListNode* node = new ListNode();
            node->val = i;
            node->next = NULL;

            ptr->next = node;
            ptr = ptr->next;
        }

        return pHead;
    }

    void print(ListNode* head) {
        for (ListNode* p = head; p != NULL; p = p->next) {
            cout << p->val << "\t";
        }
        cout << endl;
    }
};

int main()
{
    Solution* solution = new Solution();
    ListNode* pHead = solution->initList(2);
    solution->print(pHead); 

    ListNode* ptr = solution->removeNthFromEnd(pHead, 2);
    //cout << ptr->val << endl;
    solution->print(ptr);
    return 0;
}
