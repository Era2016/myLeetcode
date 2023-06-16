#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"
using std::vector;
class Solution {
private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
    vector<int>& postorder, int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd) return nullptr;
        if (preStart == preEnd) return new TreeNode(preorder[preStart]);

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // suppose preStart+1 -> root->left;
        int leftVal = preorder[preStart+1];

        int index;
        for (index = postStart; index <= postEnd; index ++) {
            if (postorder[index] == leftVal) break;
        }
        
        if (index > postEnd) return nullptr; // exception
        int cnt = index-postStart+1;
        
        root->left = build(preorder, preStart+1, preStart+cnt, postorder, postStart, index);
        root->right = build(preorder, preStart+cnt+1, preEnd, postorder, index+1, postEnd-1);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.size() == 0 || preorder.size() != postorder.size()) return nullptr;
        return build(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
