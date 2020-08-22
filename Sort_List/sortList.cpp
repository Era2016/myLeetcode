#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(NULL) {};
	ListNode(int x): val(x), next(NULL) {};
	ListNode(int x, ListNode* next): val(x), next(next) {};
};

void print(ListNode* p);

class Solution {
public:
	/* 递归快排序: 时间复杂度: nlgn; 空间复杂度: nlgn */
    ListNode* sortList1(ListNode* head) {
        ListNode* pHead = head;
        quickSort(pHead, NULL);
        return head;
    }

    /* 非递归归并排序: 时间复杂度: nlgn; 空间复杂度: n*/
    ListNode* sortList3(ListNode* head) {
    	return mergeSort(head);
    }

     /* 递归归并排序: 时间复杂度: nlgn; 空间复杂度: n*/
    ListNode* sortList2(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* ptr1 = head->next, *ptr2 = head;
        while(ptr1 && ptr1->next)
        {
            ptr1 = ptr1->next->next;
            ptr2 = ptr2->next;
        }
        ListNode* mid = ptr2->next;
        ptr2->next = nullptr;
        return merge(sortList2(head), sortList2(mid));
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


    ListNode* mergeSort(ListNode* head) {
		/*if(head == NULL || head->next == NULL) {
			return head;
		}*/

    	int length = 0;
    	ListNode* cur = head;
    	while (cur != NULL) {
    		length ++; cur = cur->next;
    	}

    	int step = 1;
    	ListNode* dummyNode = new ListNode(-1);
    	dummyNode->next = head;
    	while (step < length) {
    		ListNode* cur = dummyNode->next;
    		ListNode* tail = dummyNode;
    		while (cur != NULL) {
    			ListNode* left = cur;
	    		ListNode* right = split(left, step);
	    		//ListNode* cur = split(right, step); // 作用域问题，会被覆盖
	    		cur = split(right, step);
	    		tail = merge(left, right, tail);
    		}
    		step *= 2;
    	}
    	return dummyNode->next;
    }

    /**
	 * Divide the linked list into two lists,
     * while the first list contains first n ndoes
	 * return the second list's head
	 */
    ListNode* split(ListNode* head, int num) {
    	ListNode* p = head;
    	for (int i = 1; p != NULL && i < num; i ++) {
    		p = p->next;
    	}

    	if (p == NULL) {
    		return NULL;
    	}

    	ListNode* tmp = p->next;
    	p->next = NULL;
    	return tmp;
    }

    /**
	  * merge the two sorted linked list l1 and l2,
	  * then append the merged sorted linked list to the node head
	  * return the tail of the merged sorted linked list
	 */
    ListNode* merge(ListNode* p1, ListNode* p2, ListNode* p) {
    	while (p1 != NULL && p2 != NULL) {
    		if (p1->val < p2->val) {
    			p->next = p1;  p1 = p1->next;
    		} else {
    			p->next = p2;  p2 = p2->next;
    		}
    		p = p->next;
    	}

    	if (p1 != NULL) { p->next = p1; }
    	if (p2 != NULL) { p->next = p2; }
    	//print(p);

    	while (p->next) {
    		p = p->next;
    	}
    	return p;
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }
            else
            {
                 tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }
        if(l1) tail->next = l1;
        else tail->next = l2;
        return dummy.next;
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
    ListNode* head = so->sortList2(node1);
    print(head);
}
