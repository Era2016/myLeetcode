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
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode ** first = &head;
        ListNode ** second = &head;
        int i =0;
        while(i<n){
            first=&((*first)->next);
            i++;
        }
        while(*first!=NULL){
            first=&((*first)->next);
            second=&((*second)->next);
        }
        *second=((*second)->next);
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *ptr_1, *ptr_2;
        ptr_1 = ptr_2 = head;
        int i = 0;
        for (; i < n && ptr_1 ->next != NULL; i ++) {
            ptr_1 = ptr_1 -> next;
        }
        // n is larger than length
        if (i < n) {
            return NULL;
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

        ListNode *ptr = new ListNode();
        ListNode *pHead = ptr;
        ptr->next = NULL;
        for (int i = 1; i <= n; i ++) {
            ListNode* node = new ListNode();
            node->val = i;
            node->next = NULL;

            ptr->next = node;
            ptr = ptr->next;
        }

        return pHead;
    }

    void print(ListNode* head) {
        for (ListNode* p = head->next; p != NULL; p = p->next) {
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
