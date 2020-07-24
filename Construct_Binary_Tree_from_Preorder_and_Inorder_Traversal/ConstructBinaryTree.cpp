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

    	return construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
	TreeNode* construct(vector<int>& preorder, int startP, int endP, 
		vector<int>& inorder, int startI, int endI) {

		if (startP == endP && startI == endI) {
			return NULL;
		}

    	// 左子树数据范围确认
		int i = startI;
    	while (i < (int)inorder.size() && inorder[i] != preorder[startP]) {
    		i ++;
    	}

    	// 数据异常，前序中序数据不一致
    	if (i == (int)inorder.size()) {
    		return NULL;
    	}

    	int counter = i - startI + 1;

    	// 右子树数据范围确认

		// counter >= 1
    	if (counter < 1) {
    		return NULL;
    	}

    	// startP+counter+1 <= enp
    	// startI+counter <= endI

 		TreeNode* node = new TreeNode();
 		node->val = preorder[startP]
 		// 构建左子树
 		node->left = construct(preorder, startP+1, startP+counter, inorder, startI, startI+counter-1);
 		// 构建右子树
 		node->right = construct(preorder, startP+counter+1, endP, inorder, startI+counter, endI);
 		return node;
	}
};