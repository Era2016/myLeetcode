#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"

using std::vector;
using std::string;
class Solution {
private:
    bool isSymmetric(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) return true;
        if (!node1 && node2 || node1 && !node2) return false;
        if (node1->val != node2->val) return false;

        return isSymmetric(node1->left, node2->right) &&
            isSymmetric(node1->right, node2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
};

int main() {
    Solution* so = new Solution();
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);  TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(3);  TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(4);  TreeNode* node7 = new TreeNode(3);
    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5;
    node3->left = node6; node3->right = node7;
    
    bool flag = so->isSymmetric(node1);
    std::cout << flag << std::endl;
    
    bool flag2 = so->isSymmetric(node1);
    std::cout << flag2 << std::endl;
    return 0;
}
