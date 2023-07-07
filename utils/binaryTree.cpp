#include <iostream>
#include <vector>
#include <queue>
#include "binaryTree.h"

//using namespace std;
using std::vector;
using std::string;
using std::queue;
using std::cout;
using std::endl;

TreeNode* buildBinaryTree(vector<string>& v) {
    if (v.size() < 1 || v[0] == "null") return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(v[0]));
    q.push(root);
    int index = 1;

    while (!q.empty() && index < v.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left == nullptr) {
            if (index >= v.size()) break;

            if( v[index] != "null") {
                node->left = new TreeNode(stoi(v[index]));
                q.push(node->left);
            }
            index ++;
        }

        if (node->right == nullptr) {
            if (index >= v.size()) break;

            if (v[index] != "null") {
                node->right = new TreeNode(stoi(v[index]));
                q.push(node->right);
            }
            index ++;
        }
    }

    return root;
}

void bfs(TreeNode* root) {
    if (root == nullptr) return;

    int depth = 1;
    TreeNode* pRoot = root;
    queue<TreeNode*> q;
    q.push(pRoot);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i ++) {
            TreeNode* ptr = q.front();
            if (i == 0) cout << "the depth: "<< depth << "-> ";
            cout << ptr->val << "\t";

            q.pop();
            if (ptr->left != nullptr) { q.push(ptr->left); }
            if (ptr->right != nullptr) { q.push(ptr->right); }
        }

        depth ++;
        cout << endl;
    }
    cout << endl;
}
