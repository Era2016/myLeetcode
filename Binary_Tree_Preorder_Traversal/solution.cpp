#include <iostream>
#include <vector>
#include <stack>

#include "../utils/binaryTree.h"

using std::vector;
using std::stack;
using std::string;
class Solution {
    void preOrderRecursively(vector<int>& v, TreeNode* root) {
        if (root != nullptr) {
            v.push_back(root->val);
            preOrderRecursively(v, root->left);
            preOrderRecursively(v, root->right);
        }
    }

    void preOrder(vector<int>& v, TreeNode* root) {
        if (root == nullptr) return;

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top(); s.pop();
            v.push_back(node->val);
            if (node->right != nullptr) s.push(node->right);
            if (node->left != nullptr) s.push(node->left); 
        }
    }

    void preOrder2(vector<int>& v, TreeNode* root) {
        stack<TreeNode*> s;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                v.push_back(root->val);
                s.push(root);
                root = root->left;
            }

            TreeNode* node = s.top(); s.pop();
            root = node->right;
        }
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        //preOrderRecursively(v, root);
        //preOrder(v, root);
        preOrder2(v, root);
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
    print(so->preorderTraversal(root));

    v = {}; 
    root = buildBinaryTree(v);
    print(so->preorderTraversal(root));

    v = {"1"};
    root = buildBinaryTree(v);
    print(so->preorderTraversal(root));
}
