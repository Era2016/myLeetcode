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
        //cout << "nodeConnect finished" << endl;

    	// random pointer copy
    	pointerCopy(head);
    	//print(head);
        //cout << "pointerCopy finished" << endl;

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
        if (head == NULL) {
            return NULL;
        }

		Node* p = head->next;
		Node* newHead = p;
		while (head != NULL) {
			Node* tmp = p->next;

            if (tmp == NULL) {
                head->next = NULL;
                p->next = NULL; 
                break;
            } else {
                head->next = tmp;
                p->next = tmp->next;
            }

			head = tmp;
			p = tmp->next;
		}
		//print(newHead);
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
	/*Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	node1->next = node2; node1->random = node2;
	node2->random = node2;*/

    /*Node* node1 = new Node(3);
    Node* node2 = new Node(3);
    Node* node3 = new Node(3);
    node1->next = node2; node1->random = NULL;
    node2->next = node3; node2->random = node1;
    node3->random = NULL;*/

    Node* node1 = NULL;// = new Node(1);
	print(node1);
	Solution* so = new Solution();
	Node* head = so->copyRandomList(node1);
	print(head);
}
