#include <iostream>
#include <stdexcept>
#include <vector>

#include "../binaryTree.h"

class Solution {
private:
    void traverse(TreeNode* root) {
        if (root == nullptr) return;

        std::swap(root->left, root->right);

        traverse(root->left);
        traverse(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
};

int main() {
    Solution* so = new Solution();
    TreeNode* root;
    std::vector<std::string> v;

    v = {"2", "1", "3"};
    root = buildBinaryTree(v);
    bfs(root);
    std::cout<< std::endl << std::endl;
    so->invertTree(root);
    bfs(root);

    std::cout<< std::endl << std::endl;
    std::cout<< std::endl << std::endl;

    v = {};
    root = buildBinaryTree(v);
    bfs(root);
    std::cout<< std::endl << std::endl;
    so->invertTree(root);
    bfs(root);
}
