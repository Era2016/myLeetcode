#include <iostream>
#include <vector>
#include "../utils/binaryTree.h"

using std::vector;
using std::string;
class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight-rightHeight) > 1) {
            return -1;
        } else {
            return std::max(leftHeight, rightHeight)+1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> v;
    TreeNode *root;

    v = {"1","2","2","3","3","null","null","4","4"};
    root = buildBinaryTree(v);
    std::cout << so->isBalanced(root) << std::endl;
}
