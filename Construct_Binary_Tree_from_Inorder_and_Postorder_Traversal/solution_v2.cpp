#include <vector>

#include "../utils/binaryTree.h"
using std::vector;

class Solution {
private:
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
    vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        int index;
        for (index = inStart; index <= inEnd; index ++) {
            if (inorder[index] == rootVal) {
                break;
            }
        }
        // exception
        if (index > inEnd) return nullptr;
        int cnt = index-inStart;
        root->left = build(inorder, inStart, index-1, postorder, postStart, postStart+cnt-1);
        root->right = build(inorder, index+1, inEnd, postorder, postStart+cnt, postEnd-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || inorder.size() != postorder.size()) {
            return nullptr;
        }

        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
