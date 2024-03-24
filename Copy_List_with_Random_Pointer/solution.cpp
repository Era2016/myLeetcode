#include <iostream>	

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

class Solution {
private:
    //Node* dfs(Node* head) {
    //    if (!head) return nullptr;
//
    //    Node* cloneNode = new Node(head->val);
    //    cloneNode->next = dfs(head->next);  
    //    cloneNode->random = dfs(head->random);
    //    return cloneNode;
    //}
    Node* split(Node* head) {
        Node *ptr = head;
        Node *pHead = ptr->next, *newPtr = pHead;
        while (ptr && ptr->next) {
            Node *next = ptr->next->next;
            newPtr->next = ptr->next;
            newPtr = ptr->next;
            newPtr->next = nullptr;
            
            ptr->next = next;
            ptr = next;
        }
        return pHead;
    }
public:
    Node* copyRandomList(Node* head) {
        //return dfs(head);
        if (!head) return nullptr;
        Node *ptr = head;
        while (ptr) {
            Node *next = ptr->next;
            Node *cloneNode = new Node(ptr->val);
            cloneNode->next = ptr->next;
            ptr->next = cloneNode;

            ptr = next;
        }

        ptr = head;
        while (ptr && ptr->next) {
            if (ptr->random) {
                ptr->next->random = ptr->random->next;
            } else {
                ptr->next->random = nullptr;
            }
            ptr = ptr->next->next;
        } 

        return split(head);
    }
};

void print(Node* head) {
	while(head != NULL) {
        std::cout << head->val << "\t";
		head = head->next;
	}

    std::cout << std::endl;
}

int main() {
    Solution *so = new Solution();
    Node *head;

	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	node1->next = node2; node1->random = node2;
	node2->random = node2;

	print(node1);
	head = so->copyRandomList(node1);
	print(head);


    node1 = new Node(3);
    node2 = new Node(3);
    Node* node3 = new Node(3);
    node1->next = node2; node1->random = NULL;
    node2->next = node3; node2->random = node1;
    node3->random = NULL;

    print(node1);
    head = so->copyRandomList(node1);
    print(head);
}
