#include <algorithm>
#include "../utils/binaryTree.h"
using std::max;

class Solution {
private:
    int maxDepth;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDepth;
    }

    int dfs(TreeNode *root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int curDepth = left + right;
        maxDepth = max(curDepth, maxDepth);
        return max(left, right)+1;
    }
};
