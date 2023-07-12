#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/binaryTree.h"

using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::string;
class Solution {
private:
    unordered_map<string, TreeNode*> um;
    unordered_set<TreeNode*> filter;
    string postTravel(TreeNode* root) {
        if (root == nullptr) return "";
        string _left = postTravel(root->left);
        string _right = postTravel(root->right);
        string str = _left + ","+ _right + "," + std::to_string(root->val);
        
        auto it = um.find(str);
        if (it != um.end()) {
            filter.insert(it->second);
        } else {
            um[str] = root;
        }
        return str;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        filter.clear();
        um.clear();
        postTravel(root);
        //std::cout << dfs(root) << std::endl;
        //auto print = [](unordered_map<string, TreeNode*> um) {
        //    std::cout << "curr serialization: " << std::endl;
        //    for (auto i: um) {
        //        std::cout << i.first << "#####";
        //    }
        //    std::cout << std::endl;
        //};
        //print(um);
        return {filter.begin(), filter.end()};
    }
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
    //so->clear();

    v = {"2","1","1"};
    root = buildBinaryTree(v);
    bfs(root);
    ret = so->findDuplicateSubtrees(root);
    print(ret);
    //so->clear();

    v = {"2","2","2","3","null","3","null"};
    root = buildBinaryTree(v);
    bfs(root);
    ret = so->findDuplicateSubtrees(root);
    print(ret);
    //so->clear();
}
