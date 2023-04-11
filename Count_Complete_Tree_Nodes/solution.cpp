#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "../utils/binaryTree.h"

using std::vector;
using std::pow;
class Solution {
    public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftDepth = 1, rightDepth = 1;
        TreeNode* node = root;
        while (node->left != nullptr) {
            leftDepth ++; 
            node = node->left;
        }

        node = root;
        while (node->right != nullptr) {
            rightDepth ++;
            node = node->right;
        }

        if (leftDepth == rightDepth) {
            return pow(2, leftDepth)-1; 
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

int main() {
    Solution* so = new Solution();
    vector<std::string> v;
    TreeNode* root;

    v = {"1","2","3","4","5","6"};
    root = buildBinaryTree(v); 
    std::cout << so->countNodes(root) << std::endl;

    v = {}; 
    root = buildBinaryTree(v); 
    std::cout << so->countNodes(root) << std::endl;

    v = {"1"};
    root = buildBinaryTree(v); 
    std::cout << so->countNodes(root) << std::endl;

    v.clear();
    for (int i = 0; i <= 15; i ++) {
        v.push_back(std::to_string(i));
        root = buildBinaryTree(v); 
        std::cout <<i << ": "<< so->countNodes(root) << std::endl;
    }
}
