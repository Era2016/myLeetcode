#include <iostream>
#include <vector>
#include <stack>

#include "../utils/binaryTree.h"

using std::vector;
using std::stack;
using std::string;
class Solution {
    void postOrderRecursively(vector<int>& v, TreeNode* root) {
        if (root != nullptr) {
            postOrderRecursively(v, root->left);
            postOrderRecursively(v, root->right);
            v.push_back(root->val);
        }
    }

    void postOrder(vector<int>& v, TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* prev = nullptr;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }

            root = s.top(); s.pop();
            if (root->right == nullptr || root->right == prev) {
                v.push_back(root->val);
                
                prev = root;
                root = nullptr;
            } else {
                s.push(root);
                root = root->right;
            }
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        //postOrderRecursively(v, root);
        postOrder(v, root);
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
    print(so->postorderTraversal(root));

    v = {}; 
    root = buildBinaryTree(v);
    print(so->postorderTraversal(root));

    v = {"1"};
    root = buildBinaryTree(v);
    print(so->postorderTraversal(root));
}
