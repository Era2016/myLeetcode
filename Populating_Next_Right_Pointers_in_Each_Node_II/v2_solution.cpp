#include <iostream>
#include <deque>

using std::deque;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node *cur = root;
        while (cur) {
            Node *dummy = new Node();
            Node *prev = dummy;
            while (cur) {
                if (cur->left) {
                    prev->next = cur->left;
                    prev = prev->next;
                }
                if (cur->right) {
                    prev->next = cur->right;
                    prev = prev->next;
                }
                cur = cur->next;
            }

            cur = dummy->next;
        }
        return root;
    }
};

int main() {
    Solution *so = new Solution();

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);  Node* node3 = new Node(3);
    Node* node4 = new Node(4);  Node* node5 = new Node(5);
    Node* node6 = new Node(6);  Node* node7 = new Node(7);
    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5;
    //node3->left = node6; 
    node3->right = node7;

    Node* ptr = so->connect(node1);
    while (ptr){
        Node* p = ptr;
        while (p) {
            std::cout << p->val << "\t";
            p = p->next;
        }
        std::cout << std::endl;
        ptr = ptr->left;
    }

    return 0;
}
