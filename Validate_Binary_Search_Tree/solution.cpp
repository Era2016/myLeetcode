#include <iostream>
#include <vector>
#include <limits.h> 

using namespace std;

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
	// 只能保证左节点<根节点<右节点，但是不能保证右子树的节点数据都比左节点大 
    // 只能局部有序,不能满足要求
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) { 
            return true;
        }

        if (root->left != nullptr) {
            if (root->val <= root->left->val) {
                return false;
            }
        }

        if (root->right != nullptr) {
            if (root->val >= root->right->val) {
                return false;
            }
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }

    bool isValidBST2(TreeNode* root) {
        return inOrder(root);
    }

    bool isValidBST3(TreeNode* root) {
       return isValid(root, LONG_MIN, LONG_MAX); 
    }
private:
    bool inOrder(TreeNode* root) {
        vector<TreeNode*> v;
        vector<int> order;
        while (root != nullptr || !v.empty()) {
            while (root != nullptr) {
                v.push_back(root);
                root = root->left;
            }
            TreeNode* node = v.back();
            v.pop_back();
            if (!order.empty()) {
                if (order.back() >= node->val) {
                    return false;
                }
            }
            //cout << "order push data:" << node->val << endl;
            order.push_back(node->val);
            root = node->right;
        }
        return true;
    }

    bool isValid(TreeNode* root, long minVal, long maxVal) {
        if (root == nullptr) return true;
        
        if (root->val <= minVal) { return false; }
        if (root->val >= maxVal) { return false; }

        return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);

        //if (!isValid(root->left, minVal, root->val)) return false;
        //if (!isValid(root->right, root->val, maxVal)) return false;

        //return true;
    }

    /*bool inOrder(TreeNode* root, vector<int>& v) {
        if (root != nullptr) {
            inOrder(root->left, v);
            if (v.size() != 0) {
                if (v.back() > root->val) {
                    cout << "should quit: " << root->val << endl;
                    return false; // 只是当前递归退出，整个程序并没有全部退出，达不到效果
                }
            }
            v.push_back(root->val);
            inOrder(root->right, v);
        }
        return true;
    }*/
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
    flag = so->isValidBST3(node);
    cout << flag << endl;


    TreeNode* node11 = new TreeNode(10);
    TreeNode* node12 = new TreeNode(5);
    TreeNode* node13 = new TreeNode(15);
    TreeNode* node14 = new TreeNode(6);
    TreeNode* node15 = new TreeNode(20);
    node11->left = node12; node11->right = node13;
    node13->left = node14; node13->right = node15;
    
    flag = so->isValidBST3(node11);
    cout << flag << endl;


    TreeNode* node21 = new TreeNode(2);
    TreeNode* node22 = new TreeNode(1);
    TreeNode* node23 = new TreeNode(3);
    node21->left = node22; node21->right = node23;

    flag = so->isValidBST3(node21);
    cout << flag << endl;

}
