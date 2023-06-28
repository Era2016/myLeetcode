#include <iostream>
#include <vector>
#include <string>
#include "../utils/binaryTree.h"

using std::vector;
using std::string;
class Solution {
private:
    bool ret;
    long lastVal;
    void travel(TreeNode* root) {
        if (root != nullptr) {
            travel(root->left);
            if (root->val <= lastVal) {
                ret = false;
                return;
            } else {
                lastVal = root->val;
            }
            travel(root->right);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        this->ret = true;
        this->lastVal = (long)INT_MIN-1;//-2147483648
        travel(root);
        return this->ret;
    }
};

int main() {
    Solution* so = new Solution();
    vector<string> v;
    TreeNode* root;

    v = {"2","1","3"};
    root = buildBinaryTree(v);
    std::cout << so->isValidBST(root) << std::endl;

    v = {"5","1","4","null","null","3","6"};
    root = buildBinaryTree(v);
    std::cout << so->isValidBST(root) << std::endl;
    
    v = {"-2147483648"};
    root = buildBinaryTree(v);
    std::cout << so->isValidBST(root) << std::endl;

    root = buildBinaryTree(v);
    std::cout << so->isValidBST(root) << std::endl;
    v = {"2","2","2"};
}
