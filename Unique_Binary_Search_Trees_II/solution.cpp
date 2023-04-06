#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"

using std::vector;
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return { nullptr };
        // 区间范围[1,n], 结果展示中数字范围是[1,n]
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int lo, int hi) {
        vector<TreeNode*> v;
        if (lo > hi) {
            return { nullptr };
        }

        for (int i = lo; i <= hi; i ++) {
            vector<TreeNode*> left = generateTrees(lo, i-1);
            vector<TreeNode*> right = generateTrees(i+1, hi);

            for (auto& l: left) {
                for (auto& r: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    v.push_back(root);
                }
            }
        }
        return v;
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
