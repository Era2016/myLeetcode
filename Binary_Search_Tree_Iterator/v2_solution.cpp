#include <deque>
#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"
using std::vector;
using std::deque;
using std::string;

class BSTIterator {
private:
    deque<TreeNode*> q;
    int cursor;
    void buildQueue(TreeNode* root) {
        if (root) {
            buildQueue(root->left);
            q.push_back(root);
            buildQueue(root->right);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        cursor = 0;
        buildQueue(root);
    }
    
    int next() {
        if (cursor < q.size()) {
            return q[cursor ++]->val;
        } 
        return -1;
    }
    
    bool hasNext() {
        return cursor < q.size();
    }
};
