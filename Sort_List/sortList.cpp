#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() {};
	ListNode(int x): val(x), next(NULL) {};
	ListNode(int x, ListNode* next): val(x), next(next) {};
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	if (head == NULL || head->next == NULL) {
    		return head;
    	}

    	ListNode* pStart = head;
    	ListNode* pEnd = head->next;
    	while (pEnd->next != NULL) {
    		pEnd = pEnd->next;
    	}

    	quickSort(pStart, pEnd);
    	return head;
    }

private:
	void quickSort(ListNode* pStart, ListNode* pEnd) {
		if (pStart != pEnd) {
			ListNode* pIndex = partation(pStart, pEnd);
			quickSort(pStart, pIndex);
			quickSort(pIndex->next, pEnd);
		}
	}

	ListNode* partation(ListNode* pStart, ListNode* pEnd) {
		ListNode* pIndex = pStart;
		swap(pStart.val, pEnd.val);
		
		for (ListNode* p = pStart; p != pEnd; p = p->next) {
			if (p.val < pEnd.val) {
				if (pIndex != p) {
					swap(p.val, pIndex.val);
					pIndex = pIndex->next;
				}
			}
		}

		pIndex = pIndex->next;
		swap(pIndex.val, pEnd.val);
		return pIndex;
	}
};

void print(ListNode* p) {
	while (p != NULL) {
		cout << p->val << "\t";
	}
	cout << endl;
}

int main() {
	ListNode* n1 = new ListNode(4);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(1);
    ListNode* n4 = new ListNode(3);

    n1->next = n2; n2->next = n3; n3->next = n4;
    print(n1);
    Solution* so = new Solution();
    ListNode* n = so->sortList(n1);
    print(n);
}