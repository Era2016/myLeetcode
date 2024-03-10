#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"

using std::vector;
using std::string;
class Solution {
private:
    vector<vector<int>> res;
    void dfs(TreeNode* root, int target, vector<int>& interm) {
        if (!root) return;

        interm.push_back(root->val);
        if (!root->left && !root->right && root->val == target) {
            res.push_back(interm);
        }

        dfs(root->left, target-root->val, interm);
        dfs(root->right, target-root->val, interm);
        interm.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> interm;
        res.clear();
        dfs(root, target, interm);
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v; vector<string> nodes;
    vector<vector<int>> vv;
    TreeNode *root;
    auto print=[&]() {
        for (const auto& arr: vv) {
            for (const auto& val: arr) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    };

    nodes = {"5","4","8","11","null","13","4","7","2","null","null","5","1"};
    root = buildBinaryTree(nodes);
    vv = so->pathSum(root, 22);
    print();

    nodes = {"1","2","3"};
    root = buildBinaryTree(nodes);
    vv = so->pathSum(root, 5);
    print();

    nodes = {}; 
    root = buildBinaryTree(nodes);
    vv = so->pathSum(root, 0);
    print();
}
