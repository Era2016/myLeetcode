#include <vector>
#include "../utils/binaryTree.h"

using std::vector;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* _construct(vector<int> &preorder, int preStart, int preEnd,
        vector<int> &inorder, int inStart, int inEnd) {
            
            // 等效 if (inStart > inEnd) return nullptr;
            if (preStart > preEnd) return nullptr; 
            int rootVal = preorder[preStart];
            int cnt = 0;
            while (cnt <= inEnd-inStart && inorder[cnt+inStart] != rootVal) {
                cnt ++;
            }

            TreeNode *root = new TreeNode(rootVal);
            root->left = _construct(preorder, preStart+1, preStart+cnt, inorder, inStart, inStart+cnt-1);
            root->right = _construct(preorder, preStart+cnt+1, preEnd, inorder, inStart+cnt+1, inEnd);
            return root;
        }
};
