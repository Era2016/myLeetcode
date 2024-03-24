#include <iostream>	
#include <unordered_map>

using std::unordered_map;

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
    unordered_map<Node*, Node*> um;
    Node* dfs(Node* head) {
        if (!head) return nullptr;
//
        if (um.find(head) != um.end()) {
            return um[head];
        }

        Node* cloneNode = new Node(head->val);
        um[head] = cloneNode;

        cloneNode->next = dfs(head->next);  
        cloneNode->random = dfs(head->random);
        return cloneNode;
    }
public:
    Node* copyRandomList(Node* head) {
        return dfs(head);
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
