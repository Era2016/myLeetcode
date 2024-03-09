#include <iostream>
#include <queue>
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
    bool isSymmetricV2(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode* p1 = q.front(); q.pop();
            TreeNode* p2 = q.front(); q.pop();
            if (p1 == nullptr && p2 == nullptr) { continue; }
            if (p1 == nullptr || p2 == nullptr) { return false; }
            if (p1->val != p2->val) { return false; }
            q.push(p1->left);
            q.push(p2->right);

            q.push(p1->right);
            q.push(p2->left);
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return __isSymmetric(root, root);
    }

private:
    bool __isSymmetric(TreeNode* r1, TreeNode* r2) {
        if (r1 == nullptr && r2 == nullptr) { return true; }
        if (r1 == nullptr || r2 == nullptr) { return false; }
        return (r1->val == r2->val) && 
            __isSymmetric(r1->left, r2->right) && 
            __isSymmetric(r1->right, r2->left);
    }
};

int main() {
    Solution* so = new Solution();
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);  TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(3);  TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(4);  TreeNode* node7 = new TreeNode(3);
    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5;
    node3->left = node6; node3->right = node7;
    
    bool flag = so->isSymmetric(node1);
    cout << flag << endl;
    
    bool flag2 = so->isSymmetricV2(node1);
    cout << flag2 << endl;
    return 0;
}
