#include <iostream>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        Node* pre = root;
        while (pre->left) {
            Node* cur = pre;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }

    Node* connectV2(Node* root) {
        if (root) {
            __connectV2(root);
        }
        return root;
    }

private:
    void __connectV2(Node* root) {
        if (root->left == nullptr || root->right == nullptr) return;

        root->left->next = root->right;
        if (root->next != nullptr) root->right->next = root->next->left;

        __connectV2(root->left);
        __connectV2(root->right);
        return;
    }
};

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);  Node* node3 = new Node(3);
    Node* node4 = new Node(4);  Node* node5 = new Node(5);
    Node* node6 = new Node(6);  Node* node7 = new Node(7);
    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5;
    node3->left = node6; node3->right = node7;

    Solution* so = new Solution();
    Node* ptr = so->connect(node1);
    while (ptr){
        Node* p = ptr;
        while (p) {
            cout << p->val << "\t";
            p = p->next;
        }
        cout << endl;
        ptr = ptr->left;
    }

    ptr = so->connectV2(node1);
    while (ptr){
        Node* p = ptr;
        while (p) {
            cout << p->val << "\t";
            p = p->next;
        }
        cout << endl;
        ptr = ptr->left;
    }
}
