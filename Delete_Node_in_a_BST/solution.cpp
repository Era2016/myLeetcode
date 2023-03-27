#include <iostream>
#include <vector>
#include "../utils/binaryTree.h"

class Solution {
    public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (root->val == key) {
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left; 

            if (root->left != nullptr && root->right != nullptr) {
                TreeNode* minNode = this->getMinNode(root->right);
                root->right = deleteNode(root->right, minNode->val);
                TreeNode* toDelete = root;
                minNode->left = root->left;
                minNode->right = root->right;
                root = minNode;
                delete toDelete;
            }
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }

    TreeNode* getMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

int main () {
    Solution* so;
    std::vector<std::string> v;

    v = {"5","3","6","2","4","null","7"};
    TreeNode* root = buildBinaryTree(v);
    bfs(root);

    root = so->deleteNode(root, 3);
    bfs(root);
    //std::cout << "val: " << toDelete->val << " ; leftAddress: "<<toDelete->left 
    //   << " ; rightAddress: "<< toDelete->right << std::endl;


    v = {"5","3","6","2","4","null","7"};
    root = buildBinaryTree(v);
    bfs(root);

    root = so->deleteNode(root, 0);
    bfs(root);
}
