#include <iostream>
#include <sstream>
#include <queue>

#include "../utils/binaryTree.h"

using std::istringstream;
using std::string;
using std::vector;
using std::deque;
using std::to_string;
using std::stoi;

class Codec {
private:
    string dfs(TreeNode* root) {
        if (root == nullptr) {
            return "null";
        } else {
            return to_string(root->val).append(",")+dfs(root->left).append(",")+dfs(root->right);
        }
    }

    TreeNode* build(deque<string>& dq) {
        if (dq.empty()) return nullptr;
        string str = dq.front(); dq.pop_front();
        if (str == "null") {
            return nullptr;
        }

        TreeNode *node = new TreeNode(stoi(str));
        node->left = build(dq);
        node->right = build(dq);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return dfs(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        string token;
        deque<string>  dq;
        while (getline(is, token, ',')) {
            dq.push_back(token);
        }
        return build(dq);
    }
};

int main() {
    Codec* cc = new Codec();
    vector<string> v;
    TreeNode* root;
    string str;
    
    // normal
    v = {"1","2","3","null","null","4","5"};
    root = buildBinaryTree(v);
    str = cc->serialize(root);
    std::cout << str << std::endl;

    root = cc->deserialize(str);
    bfs(root);

    // speciall
    v = {};
    root = buildBinaryTree(v);
    str = cc->serialize(root);
    std::cout << str << std::endl;

    root = cc->deserialize(str);
    bfs(root);
}