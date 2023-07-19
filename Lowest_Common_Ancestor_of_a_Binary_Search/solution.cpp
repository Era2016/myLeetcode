#include <iostream>
#include <vector>
#include <string>

#include "../utils/binaryTree.h"

using std::vector;
using std::string;
class Solution {
private:
    vector<TreeNode*> path1, path2;
    void getPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        while (root) {
            path.push_back(root);
            if (p->val < root->val) {
                root = root->left;
            } else if (p->val > root->val) {
                root = root->right;
            } else {
                break;
            }
        }
        return;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        path1.clear(), path2.clear();
        getPath(root, p, path1);
        getPath(root, q, path2);
        reverse(path1.begin(), path1.end());
        reverse(path2.begin(), path2.end());

        //print(path1);
        //print(path2);
        vector<TreeNode*>::reverse_iterator it1 = path1.rbegin();
        vector<TreeNode*>::reverse_iterator it2 = path2.rbegin();

        while (it1 != path1.rend() && it2 != path2.rend()) {
            //std::cout << "path1: " << (*it1)->val << "\t" << "path2: " << (*it2)->val << std::endl;
            if (*it1 != *it2) {
                break;
            }
            it1 ++, it2 ++;
        }
        return *(--it1);
    }

    void print(vector<TreeNode*>& arr) {
        for (const auto& val: arr) {
            std::cout << val->val << "\t";
        }
        std::cout << std::endl;
    }
};

void dfs(TreeNode* root, int target, TreeNode** node) {
    if (root) {
        if (root->val == target) {
            *node = root;
            return;
        }
        dfs(root->left, target, node);
        dfs(root->right, target, node);
    }
}

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
