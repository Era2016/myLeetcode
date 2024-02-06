#include <iostream>
#include <unordered_map>
#include <vector>

#include "../utils/binaryTree.h"

using std::vector;
using std::unordered_map;
using std::string;
class Solution {
private:
    unordered_map<TreeNode*, int> f,g;
    void dfs(TreeNode* node) {
        if (!node) return;

        dfs(node->left);
        dfs(node->right);
        f[node] = node->val+g[node->left]+g[node->right];
        g[node] = std::max(f[node->left], g[node->left]) + std::max(f[node->right], g[node->right]);
    }
public:
    int rob(TreeNode *root) {
        dfs(root);
        return std::max(f[root], g[root]);
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> v;
    TreeNode *root;

    v = {"3","2","3","null","3","null","1"};
    root = buildBinaryTree(v);
    std::cout << so->rob(root) << std::endl; // 7

    v = {"3","4","5","1","3","null","1"};
    root = buildBinaryTree(v);
    std::cout << so->rob(root) << std::endl; // 9

    v = {};
    root = buildBinaryTree(v);
    std::cout << so->rob(root) << std::endl;
}
