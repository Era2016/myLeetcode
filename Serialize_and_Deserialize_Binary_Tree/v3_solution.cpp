#include <iostream>
#include <list>
#include <string>
#include <type_traits>
#include <vector>

#include "../utils/binaryTree.h"

using std::string;
using std::to_string;
using std::list;
using std::vector;

class Codec {
public:
    void rserialize(TreeNode* root, string& str){
        if(root==nullptr)
        {
            str+="None,";
        }else{
            str+= to_string(root->val)+",";
            rserialize(root->left,str);
            rserialize(root->right,str);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        rserialize(root,ret);
        return ret;
    }
    TreeNode *rdeserialize(list<string>& dataArray){
        if(dataArray.front() =="None")
        {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       list<string> dataArray;
       string str;
       for(auto& ch:data)
       {
           //std::cout << "===>" << ch << "<===" << std::endl; 
           if(ch == ','){
               dataArray.push_back(str);
               str.clear();
           }else{
               str.push_back(ch);
           }
       } 

       if(!str.empty())
       {
           dataArray.push_back(str);
           str.clear();
       }
       return rdeserialize(dataArray);
    }

    
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main() {
    Codec *c = new Codec();
    vector<string> v;
    TreeNode *root;
    string str;

    v = {"1","2","3","null","null","4","5"}; 
    root = buildBinaryTree(v); 
    str = c->serialize(root);
    std::cout << str << std::endl;
    root = c->deserialize(str);
    //root = c->deserialize(c->serialize(root));
    bfs(root);

    return 0;
    std::cout << std::endl << std::endl;

    v = {};
    root = buildBinaryTree(v); 
    str = c->serialize(root);
    std::cout << str << std::endl;
    root = c->deserialize(str);
    //root = c->deserialize(c->serialize(root));
    bfs(root);


    v = {"-1000", "null", "-1000"};
    root = buildBinaryTree(v);
    root = c->deserialize(c->serialize(root));
    bfs(root);
}
