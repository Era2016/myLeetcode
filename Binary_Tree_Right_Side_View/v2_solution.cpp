#include <cstddef>
#include <iostream>
#include <vector>
#include <deque>

#include "../utils/binaryTree.h"
using std::vector;
using std::string;
using std::deque;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int siz = dq.size();
            TreeNode* node;
            for (int i = 0; i < siz; i ++) {
                node = dq.front(); dq.pop_front();
                if (node->left != nullptr) dq.push_back(node->left);
                if (node->right != nullptr) dq.push_back(node->right);
            }
            res.push_back(node->val);
        }
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
