#include <vector>

#include "../utils/binaryTree.h"
using std::vector;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return _construct(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* _construct(vector<int> &preorder, int preStart, int preEnd,
            vector<int> &postorder, int postStart, int postEnd) {

        if (preStart > preEnd) return nullptr;

        if (preStart == preEnd) return new TreeNode(preorder[preStart]);

        int rootval = preorder[preStart];

        // 假设preorder[preStart+1]为左子树的根节点
        // (也有可能是右子树的根节点，此时左子树为空)
        int rootLeftval = preorder[preStart+1];
        int cnt = 0;
        while (cnt <= postEnd-postStart-1 && postorder[postStart+cnt] != rootLeftval) {
            cnt ++;
        }

        TreeNode *root = new TreeNode(rootval);
        root->left = _construct(preorder, preStart+1, preStart+1+cnt, postorder, postStart, postStart+cnt);
        root->right = _construct(preorder, preStart+2+cnt, preEnd, postorder, postStart+cnt+1, postEnd-1);
        return root;
    }
};
