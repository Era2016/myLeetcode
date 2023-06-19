#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

#include "../utils/binaryTree.h"
using std::istringstream;
using std::string;
using std::vector;
using std::deque;
class Codec {
private:
    string serialization;
    void firstTravel(TreeNode* root) {
        if (root != nullptr) {
            serialization += std::to_string(root->val) + ',';
            firstTravel(root->left);
            firstTravel(root->right);
        } else {
            serialization += "null,";
        }
    }
 
    TreeNode* build(deque<string>& tokens) {
        if (tokens.empty()) return nullptr;
        deque<string>::iterator it = tokens.begin();
        if (*it == "null") {
            tokens.erase(it);
            return nullptr;
        }
        TreeNode* root = new TreeNode(std::stoi(*it));
        tokens.erase(it);
        root->left = build(tokens);
        root->right = build(tokens);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        this->serialization = "";
        this->firstTravel(root);
        return serialization.erase(serialization.size()-1, 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        string token;
        char delimiter = ',';
        deque<string> tokens;
        while (getline(iss, token, delimiter)) {
            tokens.push_back(token);
        }

        return build(tokens);
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
