#include <iostream>

using std::cout;
using std::endl;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValid(TreeNode* root) {
        return isValid(root, nullptr, nullptr); 
    }

    bool isValid(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) return true;

        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;
        
        return isValid(root->left, min, root) && isValid(root->right, root, max);
    }
};

int main() {
    bool flag;
    Solution* so = new Solution();

    TreeNode* node = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(6);

    node->left = node1; node->right = node2;
    node2->left = node3; node2->right = node4;
    flag = so->isValid(node);
    cout << flag << endl;


    TreeNode* node11 = new TreeNode(10);
    TreeNode* node12 = new TreeNode(5);
    TreeNode* node13 = new TreeNode(15);
    TreeNode* node14 = new TreeNode(6);
    TreeNode* node15 = new TreeNode(20);
    node11->left = node12; node11->right = node13;
    node13->left = node14; node13->right = node15;
    
    flag = so->isValid(node11);
    cout << flag << endl;


    TreeNode* node21 = new TreeNode(2);
    TreeNode* node22 = new TreeNode(1);
    TreeNode* node23 = new TreeNode(3);
    node21->left = node22; node21->right = node23;

    flag = so->isValid(node21);
    cout << flag << endl;

}
