#include <iostream>
#include <vector>
#include "../utils/binaryTree.h"

using std::vector;
class Solution {
private:
    vector<TreeNode*> build(int left, int right) {
        if (left > right) {
            return { nullptr };
        }

        vector<TreeNode*> res;
        for (int i = left; i <= right; i ++) {
            vector<TreeNode*> leftSet = build(left, i-1);
            vector<TreeNode*> rightSet = build(i+1, right);
            for (const auto& l: leftSet) {
                for (const auto& r: rightSet) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        res = build(1, n);
        return res;
    } 
};

int main() {
    Solution* so = new Solution();
    vector<TreeNode*> v;

    v = so->generateTrees(0);
    for (auto node: v) {
        std::cout << "<<<<" << std::endl;
        bfs(node);
        std::cout << ">>>>" << std::endl;
    }

    v = so->generateTrees(1);
    for (auto node: v) {
        std::cout << "<<<<" << std::endl;
        bfs(node);
        std::cout << ">>>>" << std::endl;
    }

    v = so->generateTrees(3);
    for (auto node: v) {
        std::cout << "<<<<" << std::endl;
        bfs(node);
        std::cout << ">>>>" << std::endl;
    }

    v = so->generateTrees(8);
    for (auto node: v) {
        std::cout << "<<<<" << std::endl;
        bfs(node);
        std::cout << ">>>>" << std::endl;
    }
}
