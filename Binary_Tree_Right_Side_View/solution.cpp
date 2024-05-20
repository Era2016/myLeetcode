#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"
using std::vector;
using std::string;
class Solution {
private:
    void dfs(TreeNode* root, int depth, vector<int>& res) {
        if (root == nullptr) return;
        if (depth == res.size()) res.push_back(root->val);

        dfs(root->right, depth+1, res);
        dfs(root->left, depth+1, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> v;
    vector<int> res;
    TreeNode *root;
    auto print=[&]() {
        for (auto val: res) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    };

    v = {"1","2","3","null","5","null","4"};
    root = buildBinaryTree(v);
    res = so->rightSideView(root);
    print();

    v = {"1","null","3"};
    root = buildBinaryTree(v);
    res = so->rightSideView(root);
    print();

    v = {}; 
    root = buildBinaryTree(v);
    res = so->rightSideView(root);
    print();
}
