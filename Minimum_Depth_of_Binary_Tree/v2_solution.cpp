#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <deque>

#include "../utils/binaryTree.h"
using std::vector;
using std::string;
using std::deque;
class Solution {
public:
    // 不满足最小深度是叶子结点
    /*int dfs(TreeNode* root) {
        if (!root) return 0;
        int minVal = INT_MAX;
        int depth = std::min(dfs(root->left), dfs(root->right)) + 1;
        if (root->left && root->right) {
            depth = std::min(depth, minVal);
        }
        return depth;
    }*/
    // 最小深度需满足叶子结点要求
    // 即只统计根节点到叶子结点的深度，再这其中选取最小的那个
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;

        int minVal = INT_MAX;
        if (root->left != nullptr) {// 需要，否则会导致0的出现
            minVal = std::min(minDepth(root->left), minVal);
        }
        if (root->right != nullptr) {
            minVal = std::min(minDepth(root->right), minVal);
        }

        return minVal+1; 
    }

    int minDepth_v2(TreeNode* root) {
        if (!root) return 0;
        deque<TreeNode*> q;
        q.push_back(root);
        int level = 1;
        while (!q.empty()) {
            int siz = q.size();
            for (int i = 0; i < siz; i ++) {
                TreeNode *node = q.front(); q.pop_front();
                if (!node->left && !node->right) {
                    return level;
                }
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            level ++;
        }
        return -1;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> v;
    TreeNode *root;
    
    v = {"3","9","20","null","null","15","7"};
    root = buildBinaryTree(v);
    std::cout << so->minDepth(root) << std::endl;
    std::cout << so->minDepth_v2(root) << std::endl;

    v = {};
    root = buildBinaryTree(v);
    std::cout << so->minDepth(root) << std::endl;
    std::cout << so->minDepth_v2(root) << std::endl;

    v = {"2","null","3","null","4","null","5","null","6"};
    root = buildBinaryTree(v);
    std::cout << so->minDepth(root) << std::endl;
    std::cout << so->minDepth_v2(root) << std::endl;
}
