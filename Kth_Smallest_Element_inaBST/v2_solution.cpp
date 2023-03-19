#include <iostream>
#include <unordered_map>

using std::unordered_map;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class MyBST {
private:
    TreeNode* root;
    unordered_map<TreeNode*, int> um;

    int initNodeInfo(TreeNode* root) {
        if (root == nullptr) return 0;

        um[root] = 1 + initNodeInfo(root->left) + initNodeInfo(root->right); 
        return um[root];
    }

    int getNodeNum(TreeNode* root) {
        if (root != nullptr && um.count(root)) {
            return um[root];
        } else {
            return 0;
        }
    }
public:
    MyBST(TreeNode* root):root(root) {
        initNodeInfo(root); 
    }

    int getkthSmallest(int k) {
        TreeNode* node = root;
        while (node != nullptr) {
            int left = getNodeNum(node->left);
            if (left < k-1) {
                k -= left + 1;
                node = node->right;
            } else if (left == k-1) {
                break;
            } else {
                node = node->left;
            } 
        }

        return node->val;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        MyBST* myBst = new MyBST(root);
        return myBst->getkthSmallest(k);
    }
};

int main() {
	TreeNode* node = new TreeNode(3);
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(4);
	TreeNode* node3 = new TreeNode(2);
	node->left = node1; node->right = node2; node1->right = node3;
	
	Solution* so = new Solution();
	int k = so->kthSmallest(node, 1);
    std::cout << k << std::endl;
}
