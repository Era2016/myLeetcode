#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if (preorder.size() == 0 || preorder.size() != inorder.size()) {
    		return NULL;
    	}

    	int i = 0;
    	while (i < (int)inorder.size() && inorder[i] != preorder[0]) {
    		i ++;
    	}

    	// 数据异常
    	if (i == (int)inorder.size()) {
    		return NULL;
    	}

 		TreeNode* node = new TreeNode();
 		node->val = preorder[0]
 		// 构建左子树
 		node->left = construct(preorder, 0, i - 1, inorder, );
 		// 构建右子树
 		node->right = construct();
    }
private:
	TreeNode* construct(vector<int>& preorder, int startP, int endP, 
		vector<int>& inorder, int startI, int endI) {

	}
};