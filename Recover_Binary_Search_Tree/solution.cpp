#include <deque>
#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"

using std::vector;
using std::string;
using std::deque;
class Solution {
public:
    void recoverTree(TreeNode* root) {
        deque<TreeNode*> q;        
        TreeNode *prev = nullptr;
        TreeNode *x = nullptr, *y = nullptr;
        while (root || !q.empty()) {
            while (root) {
                q.push_back(root);
                root = root->left;
            }
            TreeNode *node = q.back(); q.pop_back();
            if (prev && prev->val > node->val) {
                y = node;
                if (x == nullptr) {
                    x = prev;
                } else break;
            }
            prev = node;
            root = node->right;
        }
        std::swap(x->val, y->val);
    }
};

int main() {
    Solution *so = new Solution();
    TreeNode *root;
    vector<string> v;

    v = {"1","3","null","null","2"};
    root = buildBinaryTree(v);
    printDFSBinaryTree(root); 
    so->recoverTree(root);
    printDFSBinaryTree(root);

    v = {"3","1","4","null","null","2"};
    root = buildBinaryTree(v);
    printDFSBinaryTree(root); 
    so->recoverTree(root);
    printDFSBinaryTree(root);
}
