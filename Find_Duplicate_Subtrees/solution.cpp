#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

#include "../utils/binaryTree.h"
using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::to_string;

class Solution {
private:
    unordered_map<string, TreeNode*> um;
    unordered_set<TreeNode*> us;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode *root) {
        //std::cout << dfs(root) << std::endl;
        //auto print = [](unordered_map<string, TreeNode*> um) {
        //    std::cout << "curr serialization: " << std::endl;
        //    for (auto i: um) {
        //        std::cout << i.first << "#####";
        //    }
        //    std::cout << std::endl;
        //};
        //print(um);
        dfs(root);
        return {us.begin(), us.end()};
    } 

    string dfs(TreeNode *root) {
        if (! root) return "null";

        string serialization = to_string(root->val).append(",")+dfs(root->left).append(",")+dfs(root->right);
        auto p = um.find(serialization); 
        if (p != um.end()) {
            //us.insert(root);
            us.insert(p->second);
        } else {
            um.insert(make_pair(serialization, root));
        }

        return serialization;
    }

    void clear() { us.clear(); um.clear(); }
};

int main() {
    Solution* so = new Solution();
    vector<string> v;
    vector<TreeNode*> ret;
    TreeNode* root;
    auto print = [](vector<TreeNode*> v) {
        std::cout << std::endl << "<<======" << std::endl;
        for (auto i:v) {
            bfs(i);
            std::cout << "-----"<< std::endl;
        }
        std::cout << ">>======" << std::endl;
    };

    v = {"1","2","3","4","null","2","4","null","null","4"};
    root = buildBinaryTree(v);    
    bfs(root);
    ret = so->findDuplicateSubtrees(root);
    print(ret);
    so->clear();

    v = {"2","1","1"};
    root = buildBinaryTree(v);
    bfs(root);
    ret = so->findDuplicateSubtrees(root);
    print(ret);
    so->clear();

    v = {"2","2","2","3","null","3","null"};
    root = buildBinaryTree(v);
    bfs(root);
    ret = so->findDuplicateSubtrees(root);
    print(ret);
    so->clear();
}
