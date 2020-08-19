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
        ListNode* pHead = head;
        quickSort(pHead, NULL);
        return head;
    }

private:
    void quickSort(ListNode* pHead, ListNode* pTail) {
        if (pHead != pTail && pHead->next != pTail) {
            ListNode* pMid = partation(pHead, pTail);
            cout << "partation is: " << pMid->val << endl;
            quickSort(pHead, pMid);
            quickSort(pMid->next, pTail);
        }
    }

    ListNode* partation(ListNode* pHead, ListNode* pTail) {
        ListNode* pIndex = pHead;
        ListNode* pStart = pHead->next; // require pHead != NULL
        while (pStart != pTail) {
            if (pStart->val < pHead->val) {
                if (pStart != pIndex) {
                    pIndex = pIndex->next; // require pHead->next != NULL
                    swap(pStart->val, pIndex->val);
                }
            }
            pStart = pStart->next;
        }
        swap(pIndex->val, pHead->val);
        return pIndex;
    }
};

//void swap(int &a, int &b) {
//    int tmp = a;
//    a = b;
//    b = tmp;
//}

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
