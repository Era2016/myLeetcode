#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(NULL) {};
	ListNode(int x): val(x), next(NULL) {};
	ListNode(int x, ListNode* next): val(x), next(next) {};
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) { return head; }
        ListNode* pHead = head;
        ListNode* pTail = head;
        while (pTail->next != NULL) {
            pTail = pTail->next;
        }

        cout << "tail node: " << pTail->val << endl;
        quickSort(pHead, pTail);
        //quickSort(pHead, NULL);
        return head;
    }

private:
    void quickSort(ListNode* pHead, ListNode* pTail) {
        if (pHead != pTail) {
            ListNode* pMid = partation(pHead, pTail);
            cout << "partation is: " << pMid->val << endl;
            quickSort(pHead, pMid);
            quickSort(pMid->next, pTail);
        }
    }

    ListNode* partation(ListNode* pHead, ListNode* pTail) {
        ListNode* pIndex = pHead; 
        ListNode* pStart = pHead;
        swap(pStart->val, pTail->val);
        while (pStart != pTail) {
            if (pStart->val < pTail->val) {
                if (pStart != pIndex) {
                    swap(pStart->val, pIndex->val);
                    pIndex = pIndex->next; 
                }
            }
            pStart = pStart->next;
        }
        //pIndex = pIndex->next;
        swap(pIndex->val, pTail->val);
        return pIndex;
    }
};

void print(ListNode* pHead) {
    while (pHead != NULL) {
        cout << pHead->val << "\t";
        pHead = pHead->next;
    } 
    cout << endl;
}

int main() {
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(3);
    node1->next = node2; node2->next = node3; node3->next = node4;
    print(node1);

    Solution* so = new Solution();
    ListNode* head = so->sortList(node1);
    print(head);
}
