#include <iostream>
#include <vector>

#include "../binaryTree.h"

class Solution {
private:
    //  in order search
    void traverse(TreeNode* root, int& sum) {
        if (root == nullptr) return ;

        traverse(root->right, sum);

        sum += root->val;
        root->val = sum;

        traverse(root->left, sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        traverse(root, sum);
        return root;
    }
};

int main() {
    Solution* so = new Solution();

    std::vector<std::string> v;
    TreeNode* root;

    v = {"4","1","6","0","2","5","7","null","null","null","3","null","null","null","8"};
    root = buildBinaryTree(v);
    root = so->convertBST(root);
    bfs(root);

    v = {"0","null","1"};
    root = buildBinaryTree(v);
    root = so->convertBST(root);
    bfs(root);
}
