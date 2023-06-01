#include <iostream>
#include <vector>
#include <stack>

#include "../utils/binaryTree.h"

using std::vector;
using std::stack;
using std::string;
class Solution {
    void inOrderRecursively(vector<int>& v, TreeNode* root) {
        if (root != nullptr) {
            inOrderRecursively(v, root->left);
            v.push_back(root->val);
            inOrderRecursively(v, root->right);
        }
    }

    void inOrder(vector<int>& v, TreeNode* root) {
        stack<TreeNode*> s;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            TreeNode* node = s.top(); s.pop();
            v.push_back(node->val);
            root = node->right;
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inOrderRecursively(v, root);
        return v;
    }
};

int main() {
    Solution* so = new Solution();
    vector<string> v;
    vector<int> ret;
    TreeNode* root;
    auto print=[](const vector<int>& v) {
        for (auto i: v) {
            std::cout << i << "\t";
        }
        std::cout << std::endl << std::endl;
    };

    v = {"1","null","2","3"};
    root = buildBinaryTree(v);
    print(so->inorderTraversal(root));

    v = {}; 
    root = buildBinaryTree(v);
    print(so->inorderTraversal(root));

    v = {"1"};
    root = buildBinaryTree(v);
    print(so->inorderTraversal(root));
}
