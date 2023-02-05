#include <iostream>
#include <vector>
#include <string>
#include "../utils/binaryTree.h"

using std::string;
using std::vector;
using std::to_string;

const string flag = "#";
const string sp = ",";

class Codec {
private:
    void dfs_serialize(TreeNode *root, string& str) {
        if (!root) {
            str += flag + sp;
            return ;
        }

        str += to_string(root->val) + sp;
        dfs_serialize(root->left, str);
        dfs_serialize(root->right, str);
    }

    TreeNode* dfs_deserialize(string& str) {

        int pos = str.find(sp, 0);
        if (pos == -1) {
            return nullptr;
        }
        string val = str.substr(0, pos);
        str = str.substr(pos+1, str.length());
        if (val == flag) return nullptr;

        TreeNode *root = new TreeNode(stoi(val));
        root->left = dfs_deserialize(str);
        root->right = dfs_deserialize(str);
        return root;
    }

    void print(vector<int> v) {
        for (auto val: v) {
            std::cout << val << "\t";
        }

        std::cout << std::endl;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string str;
        dfs_serialize(root, str);
        str = str.substr(0, str.length()-1);
        //std::cout << str << std::endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         
        data += sp;
        TreeNode *root = dfs_deserialize(data);
        return root;
    }
};

int main() {
    Codec *c = new Codec();
    vector<string> v;
    TreeNode *root;
    string str;

    v = {"1","2","3","null","null","4","5"}; 
    root = buildBinaryTree(v); 
    //str = c->serialize(root);
    //std::cout << str << std::endl;
    //root = c->deserialize(str);
    root = c->deserialize(c->serialize(root));
    bfs(root);

    std::cout << std::endl << std::endl;

    v = {};
    root = buildBinaryTree(v); 
    //str = c->serialize(root);
    //std::cout << str << std::endl;
    //root = c->deserialize(str);
    root = c->deserialize(c->serialize(root));
    bfs(root);


    v = {"-1000", "null", "-1000"};
    root = buildBinaryTree(v);
    root = c->deserialize(c->serialize(root));
    bfs(root);
}

