#include <iostream>
#include <queue>
#include <vector>

#include "../utils/binaryTree.h"

using std::queue;
using std::string;
using std::vector;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size -- != 0) {
                TreeNode* node = q.front(); q.pop();
                if (node->left == nullptr && node->right == nullptr) 
                    return level;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            level ++;
        }
        return level;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> v;
    TreeNode *root;
    
    v = {"3","9","20","null","null","15","7"};
    root = buildBinaryTree(v);
    std::cout << so->minDepth(root) << std::endl;

    v = {};
    root = buildBinaryTree(v);
    std::cout << so->minDepth(root) << std::endl;
}
