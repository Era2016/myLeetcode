#include <iostream>
#include <string>
#include <vector>

#include "../utils/binaryTree.h"
using std::vector;
using std::string;
class Solution {
private:
    int sum;
    void dfs(TreeNode* root, string& str) {
        if (!root) return;
        
        str += std::to_string(root->val);
        if (!root->left && !root->right) {
            //std::cout << "leaf: "<< str << std::endl;
            sum += std::stoi(str);
        }
        dfs(root->left, str);
        dfs(root->right, str);
        str.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        this->sum = 0;
        string str;
        dfs(root, str);
        return this->sum;
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
