#include <iostream>
#include <vector>
#include "../binaryTree.h"

using namespace std;
class Solution {
private:
    // first root search
    void frs(TreeNode* root, int& sum) {
        if (root == nullptr) return;

        if (root->left != nullptr &&
                root->left->left == nullptr &&
                root->left->right == nullptr) {
            sum += root->left->val;
        }
        
        frs(root->left, sum);
        frs(root->right, sum);
    }

    //bool isLeaf(TreeNode* root) { 
    //    return root->left == nullptr && root->right == nullptr; 
    //}

    int dfs(TreeNode* root) {
        int sum = 0;

        auto isLeaf = [](TreeNode* root) { return !root->left && !root->right; };
        if (root->left != nullptr) {
            sum += isLeaf(root->left)? root->left->val: dfs(root->left); 
        }

        if (root->right != nullptr && !isLeaf(root->right)) {
            sum += dfs(root->right);
        }

        return sum;
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        //int sum = 0;
        //frs(root, sum);
        //return sum;
        return !root? 0 :dfs(root);
    }
};

int main() {
    vector<string> v = {"3","9","20","null","null","15","7"};
    TreeNode* root = buildBinaryTree(v);

    //bfs(root);
    Solution* so = new Solution();
    cout << so->sumOfLeftLeaves(root) << endl;
}
