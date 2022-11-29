#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    void flatten(TreeNode *root) {
        postOrderTravel(root);
    }

    void postOrderTravel(TreeNode *root) {
        if (!root) return;

        // 利用定义，把左右子树拉平
        postOrderTravel(root->left);
        postOrderTravel(root->right);


        /**** 后序遍历位置 ****/
        // 1、左右子树已经被拉平成一条链表
        TreeNode *_left = root->left;
        TreeNode *_right = root->right;

        // 2、将左子树作为右子树
        root->left = nullptr;
        root->right = _left;

        // 3、将原先的右子树接到当前右子树的末端
        TreeNode *ptr = root;
        while (ptr->right) {
            ptr = ptr->right;
        }

        ptr->right = _right;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> v;
    TreeNode *root;
    auto print = [](TreeNode *ptr) { 
        while (ptr) { 
            cout << ptr->val << "\t";
            ptr = ptr->right;
        }

        cout << endl;
    };

    v = {"1","2","5","3","4","null","6"};
    root = buildBinaryTree(v);
    so->flatten(root);
    print(root);


    v = {};
    root = buildBinaryTree(v);
    so->flatten(root);
    print(root);

    v = {"0"};
    root = buildBinaryTree(v);
    so->flatten(root);
    print(root);
}
