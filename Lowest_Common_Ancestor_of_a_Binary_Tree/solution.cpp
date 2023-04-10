#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

#include "../utils/binaryTree.h"

using std::unordered_map;
using std::vector;
class Solution {
private:
    unordered_map<int, TreeNode*> um;
    unordered_map<int, TreeNode*> visit;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        TreeNode* node;
        um[root->val] = nullptr;
        dfs(root);

        while (p != nullptr) {
            visit[p->val] = p;
            p = um[p->val];
        }
        //printMap(visit);
        
        while (q != nullptr) {
            if (visit.count(q->val) == 1) {
                node = q;
                std::cout <<"found: " << node->val << std::endl;
                break;
            }

            q = um[q->val];
        }
        return node;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        if (root->left) {
            um[root->left->val] = root;    
            dfs(root->left);
        }

        if (root->right) {
            um[root->right->val] = root;
            dfs(root->right);
        }
    }

    void printMap(unordered_map<int, TreeNode*> mm) {
        for (std::pair<int, TreeNode*> m: mm) {
            std::cout << "key: " << m.first << " ;value: " << m.second->val << std::endl; 
        }
    }
    void printPath(TreeNode* node) {
        while (node != nullptr) {
            std::cout << node->val << "\t";
            node = um[node->val];
        } 
        std::cout << std::endl;
    } 

    void searchTreeNode(TreeNode* node, int value, TreeNode** target) {
        if (node != nullptr) {
            if (node->val == value) {
                *target = node;
                std::cout <<"target address: " << *target << std::endl;
                return ;
            }
            searchTreeNode(node->left, value, target);
            searchTreeNode(node->right, value, target);
        }
    }
};

int main() {
    Solution* so = new Solution();
    TreeNode *root, **p, **q;
    TreeNode *lowest;
    TreeNode *tmp1, *tmp2;
    vector<std::string> v;


    v = {"3","5","1","6","2","0","8","null","null","7","4"};
    root = buildBinaryTree(v);
    std::cout << "build binaryTree done" << std::endl;

    tmp1 = new TreeNode(); 
    p = &tmp1;
    so->searchTreeNode(root, 5, p);
    std::cout << "p: " << (*p)->val << std::endl;

    tmp2 = new TreeNode();
    q = &tmp2;
    so->searchTreeNode(root, 1, q);
    std::cout << "q: " << (*q)->val << std::endl;
    
    //std::cout << "root: " << root->val << std::endl;
    so->printPath(*p);
    so->printPath(*q);
    lowest = so->lowestCommonAncestor(root, *p, *q);    
    std::cout << "lowest Ancestor: " << lowest->val << std::endl;

    //tmp1 = new TreeNode(); 
    p = &tmp1;
    so->searchTreeNode(root, 5, p);
    std::cout << "p: " << (*p)->val << std::endl;

    //tmp2 = new TreeNode();
    q = &tmp2;
    so->searchTreeNode(root, 4, q);
    std::cout << "q: " << (*q)->val << std::endl;
    
    //std::cout << "root: " << root->val << std::endl;
    so->printPath(*p);
    so->printPath(*q);
    lowest = so->lowestCommonAncestor(root, *p, *q);    
    std::cout << "lowest Ancestor: " << lowest->val << std::endl;

    delete tmp1;
    delete tmp2;
}
