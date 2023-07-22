#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

#include "../utils/binaryTree.h"

using std::unordered_map;
using std::vector;
using std::string;
class Solution {
private:
    void dfs(TreeNode* root, unordered_map<int, TreeNode*>& um) {
        if (root == nullptr) return;

        if (root->left != nullptr) {
            um[root->left->val] = root;
            dfs(root->left, um);
        }

        if (root->right != nullptr) {
            um[root->right->val] = root;
            dfs(root->right, um);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        
        unordered_map<int, TreeNode*> um;
        um[root->val] = nullptr;
        dfs(root, um);

        unordered_map<int, bool> visit;
        while (p != nullptr) {
            visit[p->val] = true;
            p = um[p->val];
        }

        while (q != nullptr) {
            if (visit[q->val] == true) {
                break;
            }
            visit[q->val] = true;
            q = um[q->val];
        }

        return q;
    }
};

int main() {
    Solution *so = new Solution();
    TreeNode *root, **p, **q;
    TreeNode *lowest;
    vector<string> v;

    *p = new TreeNode();
    *q = new TreeNode();

    v = {"3","5","1","6","2","0","8","null","null","7","4"};
    root = buildBinaryTree(v);
    dfs(root, 5, p);
    dfs(root, 1, q);
    lowest = so->lowestCommonAncestor(root, *p, *q);
    std::cout << "lowest Ancestor: " << lowest->val << std::endl;


    dfs(root, 5, p);
    dfs(root, 4, q);
    lowest = so->lowestCommonAncestor(root, *p, *q);
    std::cout << "lowest Ancestor: " << lowest->val << std::endl;
    

    v = {"1","2"}; 
    root = buildBinaryTree(v);
    dfs(root, 1, p);
    dfs(root, 2, q);
    lowest = so->lowestCommonAncestor(root, *p, *q);
    std::cout << "lowest Ancestor: " << lowest->val << std::endl;
}
