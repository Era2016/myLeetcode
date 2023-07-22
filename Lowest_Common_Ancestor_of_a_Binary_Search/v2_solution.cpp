#include <iostream>
#include <vector>
#include <string>

#include "../utils/binaryTree.h"

using std::vector;
using std::string;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else {
                break;
            }
        }

        return root;
    }
};

int main() {
    Solution *so = new Solution();
    TreeNode *root, *node;
    TreeNode *p, *q;
    vector<string> v;
    
    v = {"6","2","8","0","4","7","9","null","null","3","5"};
    root = buildBinaryTree(v); 
    dfs(root, 2, &p);
    dfs(root, 8, &q);
    node = so->lowestCommonAncestor(root, p, q);
    std::cout << node->val << std::endl;

    dfs(root, 2, &p);
    dfs(root, 4, &q);
    node = so->lowestCommonAncestor(root, p, q);
    std::cout << node->val << std::endl;
}
