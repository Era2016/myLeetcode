#include <climits>
#include <iostream>

using namespace std;

//A path from start to end, goes up on the tree for 0 or more steps, then goes down for 0 or more steps. Once it goes down, it can't go up. Each path has a highest node, which is also the lowest common ancestor of all other nodes on the path.
//A recursive method maxPathDown(TreeNode node) (1) computes the maximum path sum with highest node is the input node, update maximum if necessary (2) returns the maximum sum of the path that can be extended to input node's parent.
//
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
    int maxPathSum(TreeNode* root) {
        maxVal = INT_MIN;
        maxPathDown(root);
        return maxVal;
    }
private:
    int maxVal;
    int maxPathDown(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = max(0, maxPathDown(root->left));
        int right = max(0, maxPathDown(root->right));

        maxVal = max(maxVal, left+right+root->val);
        return max(left, right)+root->val;
    }
};
