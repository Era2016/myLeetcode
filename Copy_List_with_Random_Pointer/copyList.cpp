#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void print(Node* head);

class Solution {
public:
    Node* copyRandomList(Node* head) {
    	// new and connect
    	nodeConnect(head);
    	//print(head);

    	// random pointer copy
    	pointerCopy(head);
    	//print(head);

    	// link decoupling
    	return decoupling(head);
    }
private:
	void nodeConnect(Node* head) {
		while (head != NULL) {
			Node* n = new Node(head->val);
			Node* tmp = head->next;
			head->next = n;
			n->next = tmp;
			head = tmp;
		}
	}

	void pointerCopy(Node* head) {
		while (head != NULL) {
			if (head->random != NULL) {
				head->next->random = head->random->next;	
			}
			
			head = head->next->next;
		}
	}

	Node* decoupling(Node* head) {
		Node* p = head->next;
		Node* newHead = p;
		while (head != NULL) {
			Node* tmp = p->next;

			head->next = tmp;
			p->next = tmp->next;

			head = tmp;
			if (head == NULL) {
				break;
			}
			p = tmp->next;
		}
		print(newHead);
		return newHead;
	}
};

void print(Node* head) {
	while(head != NULL) {
		cout << head->val << "\t";
		head = head->next;
	}

	cout << endl;
}

int main() {
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	node1->next = node2;
	node1->random = node2;
	node2->random = node2;

	print(node1);
	Solution* so = new Solution();
	Node* head = so->copyRandomList(node1);
	print(head);
}