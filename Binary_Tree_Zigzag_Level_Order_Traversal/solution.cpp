#include <iostream>
#include <vector>

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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > vv;
        travel(vv, root, 0);
        return vv;
    }

private:
    void travel(vector<vector<int> >& vv, TreeNode* root, int level) {
        if (level <= (int)vv.size()) {
            vector<int> v;
            vv.push_back(v);
        } else {
            return;
        } 

        vector<int> curV = vv[level];
        if (level % 2) { 
            if (root->right) {curV.push_back(root->right->val); }
            if (root->left) {curV.push_back(root->left->val); }
        } else {
            if (root->left) {curV.push_back(root->left->val); }
            if (root->right) {curV.push_back(root->right->val); }
        }

        travel(vv, root->left, level+1);
        travel(vv, root->right, level+1);
    }
};
