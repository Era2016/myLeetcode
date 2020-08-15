#include <iostream>
#include <vector>
#include <queue>	// priority_queue
#include <map>		// multimap

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {};
	ListNode(int x) : val(x), next(NULL) {};
	ListNode(int x, ListNode *next) : val(x), next(next) {};
};
 
struct compare {
  	bool operator() (const ListNode* n1, const struct ListNode* n2) const
  	{
    	return n1->val > n2->val;
  	}
};

class Solution {
public:
	// 优先队列
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (int i = 0; i < (int) lists.size(); i ++) {
        	if (lists[i] != NULL) {
        		pq.push(lists[i]);
        	}
        }

        ListNode* pHead = new ListNode();
        ListNode* p = pHead;
        while (!pq.empty()) {
        	p->next = pq.top();  pq.pop();	
        	p = p->next;
        	if (p->next != NULL) {
        		pq.push(p->next);
        	}
        }

        return pHead->next;
    }

    // 堆
    static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
	}
	ListNode* mergeKLists2(vector<ListNode*>& lists) { //make_heap
	    ListNode head(0);
	    ListNode *curNode = &head;
	    vector<ListNode*> v;   
	    for(int i =0; i<lists.size(); i++){
	        if(lists[i]) v.push_back(lists[i]);
	    }
	    make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

	    while (v.size() > 0){
	        curNode->next = v.front();
	        pop_heap(v.begin(), v.end(), heapComp); 
	        v.pop_back(); 
	        curNode = curNode->next;
	        if (curNode->next) {
	            v.push_back(curNode->next); 
	            push_heap(v.begin(), v.end(), heapComp);
	        }
	    }
	    return head.next;
	}

	// multimap
	ListNode *mergeKLists3(vector<ListNode *> &lists) {
        multimap<int, ListNode*> mp;  //a new multimap<val, head> to store data
        for (auto p : lists) {
            if (p != NULL) { //every List , <val, ListHead>, if ListHead != NULL
                mp.insert(make_pair(p->val, p)); 
            }
        }
        ListNode *ret = NULL;
        ListNode *p = NULL;
        while (!mp.empty()) {
            multimap<int, ListNode*>::iterator it = mp.begin();
//it is the iterator of max value, because map use RB tree to implement
            if (ret == NULL) {
                ret = it->second;
                p = ret;
            } else {
                p->next = it->second;
                p = p->next;
            }
            if (it->second->next != NULL) {
                mp.insert(make_pair(it->second->next->val, it->second->next));
            } //add the next node of the max value of list 
            mp.erase(it); //delete the max value which already add the result list
        }
        return ret;
    }

	// 分治法
    ListNode* mergeKLists4(vector<ListNode*>& lists) {
        
        int length = (int) lists.size();
        for (int step = 1; step < length; step = step * 2) {
        	// j的增长变化，见test 测试用例
        	for (int j = 0; j < length - step; j += step * 2) {
        		lists[j] = merge2Lists(lists[j], lists[j + step]);
        	}
        }
        return (length == 0)? NULL: lists[0];
    }

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
	ListNode* l = so->mergeKLists3(v);
	print(l);
}