#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"

using std::vector;
using std::string;
class Solution {
public:
    bool dfs(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr && targetSum == root->val) {
            return true;
        }

        return dfs(root->left, targetSum-root->val) || 
            dfs(root->right, targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};

int main() {
    Solution *so = new Solution();
    TreeNode *root;
    vector<string> v;

    v = {"5","4","8","11","null","13","4","7","2","null","null","null","1"};
    root = buildBinaryTree(v);
    std::cout << so->hasPathSum(root, 22) << std::endl;

    v = {"1","2","3"};
    root = buildBinaryTree(v);
    std::cout << so->hasPathSum(root, 5) << std::endl;

    v = {"1","2"};
    root = buildBinaryTree(v);
    std::cout << so->hasPathSum(root, 1) << std::endl;

    v = {};
    root = buildBinaryTree(v);
    std::cout << so->hasPathSum(root, 0) << std::endl;
}
