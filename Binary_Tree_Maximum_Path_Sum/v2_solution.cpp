#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../utils/binaryTree.h"
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        postOrderTravel(root);
        return maxVal;
    }
private:
    unordered_map<TreeNode*, int> um;
    int maxVal = INT_MIN;
    int postOrderTravel(TreeNode* root) {
        if (!root) return 0;

        // 多余，后续遍历每个节点只会遍历一次
        //if (um.count(root)) { std::cout << um[root] << std::endl; return um[root]; }

        int leftVal = std::max(postOrderTravel(root->left), 0);
        int rightVal = std::max(postOrderTravel(root->right), 0);

        //um[root] = root->val + std::max(leftVal, rightVal);
        maxVal = std::max(maxVal, root->val+leftVal+rightVal);
        //return um[root];
        return root->val + std::max(leftVal, rightVal);
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
