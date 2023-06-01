#include <iostream>
#include <deque>
#include <vector>

#include "../utils/binaryTree.h"

using std::vector;
using std::deque;
using std::string;

class Solution {
private:
    void postOrderRecursively(vector<int>& v, TreeNode* root) {
        if (root != nullptr) {
            postOrderRecursively(v, root->left);
            postOrderRecursively(v, root->right);
            v.push_back(root->val);
        }
    }
    void postOrder(vector<int>& v, TreeNode* root) {
        deque<TreeNode*> stack;
        TreeNode* prev = nullptr;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push_front(root);
                root = root->left;
            }

            root = stack.front(); stack.pop_front();
            if (root->right == nullptr || root->right == prev) {
                v.push_back(root->val);
                prev = root;

                root = nullptr;
            } else {
                stack.push_front(root);
                root = root->right;
            }
        }
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
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
