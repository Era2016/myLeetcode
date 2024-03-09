#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"

using std::vector;
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> num;
        inorder(root, num);
        sort(num.begin(),num.end());
        int index = 0;
        inorder(root, num, index);

    }
    void inorder(TreeNode* root, vector<int>& num) {
        if(root == nullptr)
            return;
        inorder(root -> left, num);
        num.push_back(root -> val);
        inorder(root -> right, num);
    }
    void inorder(TreeNode* root,vector<int> num, int& index) {
        if(root == nullptr)
            return;
        inorder(root -> left, num, index);
        root -> val = num[index++];
        inorder(root -> right, num ,index);
    }
};
