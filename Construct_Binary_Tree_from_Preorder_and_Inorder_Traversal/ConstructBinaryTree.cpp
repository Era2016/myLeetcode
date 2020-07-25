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

		if (startP > endP && startI > endI) {
			return NULL;
		}

    	// 左子树数据范围确认
		int i = startI;
    	while (i <= endI && inorder[i] != preorder[startP]) {
    		i ++;
    	}

    	// 数据异常，前序中序数据不一致
    	if (i > endI) {
    		//cout << "data exception" << endl;
    		return NULL;
    	}

    	// 右子树数据范围确认
    	// int counter = i - startI;
    	// startP+counter+1 <= endp <=> counter+1 <= endp-startp
    	// startI+counter <= endI <=> counter <= endI-startI

 		TreeNode* node = new TreeNode();
 		node->val = preorder[startP];
 		// 构建左子树  counter = i - startI;
 		node->left = construct(preorder, startP+1, startP+i-startI, inorder, startI, i-1);	
 		// 构建右子树
 		node->right = construct(preorder, startP+i-startI+1, endP, inorder, i+1, endI);	
 		return node;
	}
};

void print(TreeNode* root) {
	if (root) {
		cout << root->val << "\t";
		print(root->left);
		print(root->right);
	}
	//cout << endl;
}

int main() {
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};

	TreeNode* root = new TreeNode{};
	Solution* so = new Solution();
	root = so->buildTree(preorder, inorder);
	print(root);
}