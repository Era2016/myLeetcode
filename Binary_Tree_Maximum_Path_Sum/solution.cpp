#include <climits>
#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"
using namespace std;

//A path from start to end, goes up on the tree for 0 or more steps, then goes down for 0 or more steps. Once it goes down, it can't go up. Each path has a highest node, which is also the lowest common ancestor of all other nodes on the path.
//A recursive method maxPathDown(TreeNode node) (1) computes the maximum path sum with highest node is the input node, update maximum if necessary (2) returns the maximum sum of the path that can be extended to input node's parent.
//

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

int main() {
    Solution *so = new Solution();
    vector<string> v;
    TreeNode *root;

    v = {"1","2","3"};
    root = buildBinaryTree(v);
    std::cout << so->maxPathSum(root) << std::endl; // 6 

    v = {"-10","9","20","null","null","15","7"};
    root = buildBinaryTree(v);
    std::cout << so->maxPathSum(root) << std::endl; // 42
                                                    
    v = {"5","4","8","11","null","13","4","7","2","null","null","null","1"};
    root = buildBinaryTree(v);
    std::cout << so->maxPathSum(root) << std::endl; // 48
}
