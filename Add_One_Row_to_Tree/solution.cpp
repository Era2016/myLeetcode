#include <iostream>
#include <vector>

#include "../binaryTree.h"

class Solution {
private:
    int depth = 0;
    void traverse(TreeNode* root, int val, int depth) {
        if (root == nullptr) return;

        this->depth ++;
        if (this->depth == depth-1) {
            TreeNode* pLeft = new TreeNode(val);
            TreeNode* pRight = new TreeNode(val);

            pLeft->left = root->left;
            root->left = pLeft;

            pRight->right = root->right;
            root->right = pRight;
        }

        traverse(root->left, val, depth);
        traverse(root->right, val, depth);
        this->depth --;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* p = new TreeNode(val);
            p->left = root;
            root = p;
        } else {
            traverse(root, val, depth);
        }

        return root;
    }
};

int main() {
    Solution* so = new Solution();
    std::vector<std::string> v;
    TreeNode* root;

    v = {"4","2","null","3","1"};
    root = buildBinaryTree(v);
    bfs(root);
    std::cout << std::endl;
    root = so->addOneRow(root, 1, 3);
    bfs(root);
    std::cout << std::endl;
    std::cout << std::endl;

    v = {"4","2","6","3","1","5"};
    root = buildBinaryTree(v);
    bfs(root);
    std::cout << std::endl;
    root = so->addOneRow(root, 1, 2);
    bfs(root);
    std::cout << std::endl;
    std::cout << std::endl;

    v = {"4","2","6","3","1","5"};
    root = buildBinaryTree(v);
    bfs(root);
    std::cout << std::endl;
    root = so->addOneRow(root, 1, 1);
    bfs(root);
    std::cout << std::endl;
    std::cout << std::endl;
}
