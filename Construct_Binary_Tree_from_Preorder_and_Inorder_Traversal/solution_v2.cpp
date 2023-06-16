#include <vector>
#include "../utils/binaryTree.h"

using std::vector;

class Solution {
private:
    TreeNode* build (vector<int>& preorder, int preStart, int preEnd, 
    vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        
        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);
        int index;
        for (index = inStart; index <= inEnd; index ++) {
            if (inorder[index] == rootVal) {
                break;
            }
        }
        // execption
        if (index > inEnd) return nullptr;

        int cnt = index-inStart;
        root->left = build(preorder, preStart+1, preStart+cnt, inorder, inStart, index-1);
        root->right = build(preorder, preStart+cnt+1, preEnd, inorder, index+1, inEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || preorder.size() != inorder.size()) return nullptr;

        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
