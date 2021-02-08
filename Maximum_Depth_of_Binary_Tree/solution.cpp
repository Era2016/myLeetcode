#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return (leftDepth > rightDepth)? leftDepth+1: rightDepth+1;
    }

    int maxDepthV2(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int depth = 0, size = 1; 
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) { q.push(node->left); } 
            if (node->right) { q.push(node->right); }
            if (-- size == 0) {
                size = q.size(); depth ++;
            }
        }
        return depth;
    }
};

int main() {
    
    Solution* so = new Solution();

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(3);  TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(4);  TreeNode* node5 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(5);  TreeNode* node7 = new TreeNode(8);
    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5;
    node3->left = node6; node3->right = node7;

    int length = so->maxDepth(node1);
    int length2 = so->maxDepthV2(node1);
    cout << length << endl;
    cout << length2 << endl;
}
