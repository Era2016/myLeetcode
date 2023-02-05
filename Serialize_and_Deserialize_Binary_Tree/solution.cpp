#include <iostream>
#include <vector>
#include <string>
#include "../utils/binaryTree.h"

using std::string;
using std::vector;
using std::to_string;

const int flag = -1001;
const string sp = ",";

class Codec {
private:
    void dfs_serialize(TreeNode *root, vector<int>& v) {
        if (!root) {
            v.push_back(flag);
            return ;
        }

        v.push_back(root->val);
        dfs_serialize(root->left, v);
        dfs_serialize(root->right, v);
    }

    TreeNode* dfs_deserialize(vector<int>& v) {

        int val = *(v.begin());
        v.erase(v.begin());

        if (val == flag) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(val);
        root->left = dfs_deserialize(v);
        root->right = dfs_deserialize(v);
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
        vector<int> v;
        dfs_serialize(root, v);
        //print(v);
        string str;
        for (auto i: v ){
            str += to_string(i) + sp;
        }
        str = str.substr(0, str.length()-1);
        //std::cout << str << std::endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         
        data += sp;
        vector<int> vv;
        for (int i = 0; i < data.length(); i ++) {
            int pos = data.find(sp, i);
            if (pos != -1) {
                vv.push_back(stoi(data.substr(i, i-pos)));
                i = pos; // i = pos + ",".length() - 1;
            }
        }
        TreeNode* root = dfs_deserialize(vv);
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

