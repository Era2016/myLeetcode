#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            stack.push_back(root);
            root = root->left;
        }    
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* p = stack.back();
        stack.pop_back();

        int val = p->val;
        p = p->right;
        while (p) {
            stack.push_back(p);
            p = p->left;
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty(); 
    }

    vector<TreeNode*> stack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(3); node1->left = node2;
    TreeNode* node3 = new TreeNode(9); node1->right = node3;
    TreeNode* node4 = new TreeNode(1); node2->left = node4;
    TreeNode* node5 = new TreeNode(6); node3->left = node5;

    BSTIterator* obj = new BSTIterator(node1);
    int val = 0;
    while (obj->hasNext()) {
        val = obj->next();
        cout << val << "\t";
    }
    cout << endl;
}
