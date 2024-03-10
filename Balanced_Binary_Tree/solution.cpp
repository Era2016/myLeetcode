#include <iostream>
#include <unordered_map>
#include <vector>

#include "../utils/binaryTree.h"
using std::unordered_map;
using std::vector;
using std::string;
class Solution {
private:
    unordered_map<TreeNode*, int> um;
    int nodeDepth(TreeNode* root) {
        if (!root) return 0;
        int left = nodeDepth(root->left);
        int right = nodeDepth(root->right);
        um[root] = std::max(left, right)+1;
        return um[root];
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!um.count(root)) {
            nodeDepth(root);
        }
        int left = um[root->left];
        int right = um[root->right];
        if (abs(left-right) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
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
