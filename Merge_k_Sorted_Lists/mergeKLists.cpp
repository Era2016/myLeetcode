#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {};
	ListNode(int x) : val(x), next(NULL) {};
	ListNode(int x, ListNode *next) : val(x), next(next) {};
};
 

class Solution {
public:
	// 分治法
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int length = (int) lists.size();
        for (int step = 1; step < length; step = step * 2) {
        	// j的增长变化，见test 测试用例
        	for (int j = 0; j < length - step; j += step * 2) {
        		lists[j] = merge2Lists(lists[j], lists[j + step]);
        	}
        }
        return (length == 0)? NULL: lists[0];
    }

    // 优先队列
    /*ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    }*/

private:
	ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
		ListNode* pHead = new ListNode();
		ListNode* p = pHead;

		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				p->next = l1; l1 = l1->next;
			} else {
				p->next = l2; l2 = l2->next;
			}
			p = p->next;
		}

		if (l1 != NULL) { p->next = l1; }

		if (l2 != NULL) { p->next = l2; }

		return pHead->next;
    }
};

void print(ListNode* l) {
	while(l != NULL) {
		cout << l->val << "\t";
		l = l -> next;
	}

	cout << endl;
}

int main() {
	ListNode* l1 = new ListNode(1); 
	ListNode* l11 = new ListNode(4); 
	ListNode* l111 = new ListNode(5);
	l1->next = l11; l11->next = l111;

	ListNode* l2 = new ListNode(1);
	ListNode* l22 = new ListNode(3);
	ListNode* l222 = new ListNode(4);
	l2->next = l22; l22->next = l222;

	ListNode* l3 = new ListNode(2);
	ListNode* l33 = new ListNode(6);
	l3->next = l33;

	vector<ListNode*> v;
	v.push_back(l1); 
	v.push_back(l2); 
	v.push_back(l3);

	Solution* so = new Solution();
	ListNode* l = so->mergeKLists(v);
	print(l);
}