#include <iostream>
#include <string>
#include <vector>

#include "../utils/binaryTree.h"
using std::vector;
using std::string;
class Solution {
private:
    int dfs(TreeNode* root, int prevSum) {
        if (!root) return 0;
        
        int sum = 10*prevSum + root->val;
        if (!root->left && !root->right) {
            return sum;
        } else {
            return dfs(root->left, sum)+dfs(root->right, sum);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> v;
    TreeNode *root;
    
    v = {"1","2","3"};
    root = buildBinaryTree(v);
    std::cout << so->sumNumbers(root) << std::endl; // 25

    v = {"4","9","0","5","1"};
    root = buildBinaryTree(v);
    std::cout << so->sumNumbers(root) << std::endl; // 1026
}

