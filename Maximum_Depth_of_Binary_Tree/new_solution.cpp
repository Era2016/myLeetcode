#include <iostream>
#include <vector>
#include <cassert>

#include "../binaryTree.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    Solution* so = new Solution();
    std::vector<std::string> v;
    TreeNode* root;

    v = {"3","9","20","null","null","15","7"};
    std::cout << "size:: " << v.size() << std::endl;
    root = buildBinaryTree(v);
    assert(so->maxDepth(root) == 3);


    v = {"1","null","2"};
    std::cout << "size:: " << v.size() << std::endl;
    root = buildBinaryTree(v);
    assert(so->maxDepth(root) == 2);
}
