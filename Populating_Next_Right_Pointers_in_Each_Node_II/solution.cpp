#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"
using std::vector;
using std::string;

// Definition for a Node.
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
private:
    void levelTravel(Node* root, int level, vector<vector<Node*>>& result) {
        if (!root) return;
        if (result.size() <= level) {
            result.push_back(vector<Node*>());
        }

        if (level < result.size() && !result[level].empty()) {
            Node* node = result[level].back();
            node->next = root;
        }
        result[level].push_back(root);
        levelTravel(root->left, level+1, result);
        levelTravel(root->right, level+1, result);
    }
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> res;
        levelTravel(root, 0, res);
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
