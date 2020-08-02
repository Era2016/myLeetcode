#include <iostream>
#include <vector>

using namespace std;

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
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> v;
		inorderTraversal(root, v);
		return v; 
    }

private:
	void inorderTraversal(TreeNode* root, vector<int>& v) {
		if (root != NULL) {
			inorderTraversal(root->left, v);
			v.push_back(root->val);
			inorderTraversal(root->right, v);
		}
	}
};

void print(vector<int> v) {
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter ++) {
		cout << *iter << "\t";
	}
	cout << endl;
}

int main() {
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);

	node1->right = node2;
	node2->left = node3;

	vector<int> v;
	Solution* so = new Solution();
	v = so->inorderTraversal(node1);

	print(v);	
}
