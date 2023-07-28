#include <iostream>
#include <string>
#include <vector>

#include "../utils/binaryTree.h"
using std::vector;
using std::string;

class Solution {
private:
    void dfs(TreeNode* root, string str, vector<string>& v) {
        if (root == nullptr) {
            return;
        }

        str += std::to_string(root->val)+"->";
        if (root->left == nullptr && root->right == nullptr) {
            v.push_back(str.substr(0, str.length()-2));
            return;
        }

        dfs(root->left, str, v);
        dfs(root->right, str, v);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        dfs(root, "", v);
        return v;
    }
};

int main() {
    Solution *so = new Solution();
    TreeNode *root;
    vector<string> v, res;

    auto print=[](vector<string>& arr) {
        for (const auto& val: arr) {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    };

    v = {"3","5","1","6","2","0","8","null","null","7","4"};
    root = buildBinaryTree(v);
    res = so->binaryTreePaths(root);
    
    print(res);
}
