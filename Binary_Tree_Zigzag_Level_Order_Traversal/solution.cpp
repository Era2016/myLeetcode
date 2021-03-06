#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > vv;
        //dfsWithRecursive(vv, root, 0);
        
        if (!root) return {};
        dfs(vv, root);
        return vv;
    }

private:
    void dfs(vector<vector<int> >& vv, TreeNode* root) {
        vector<int> v;
        int level = 0;
        queue<TreeNode*> q;
        
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            int sz = q.size();
            for (int i = 0; i < sz; i ++) {
                TreeNode* node = q.front();
                q.pop();
                if (level % 2 == 0) { v.push_back(node->val); }
                else { v.insert(v.begin(), node->val); }

                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
            vv.push_back(v);
            level ++;
        }
    }

    void dfsWithRecursive(vector<vector<int> >& vv, TreeNode* root, int level) {
        if (root == nullptr) return;

        if (level >= (int)vv.size()) { vv.push_back(vector<int>{}); }
    
        if (level % 2 == 0) { vv[level].push_back(root->val); }
        else { vv[level].insert(vv[level].begin(), root->val); }

        dfsWithRecursive(vv, root->left, level+1);
        dfsWithRecursive(vv, root->right, level+1);
    }
};

void print(vector<vector<int> > vv) {
    for (vector<vector<int> >::iterator it=vv.begin();
            it != vv.end(); it ++) {
        for (vector<int>::iterator i=it->begin(); i != it->end(); i ++) {
            cout << *i << "\t";
        }
        cout << endl;
    }
}
int main() {
    TreeNode* node = new TreeNode(3);
    TreeNode* node1 = new TreeNode(9); TreeNode* node2 = new TreeNode(20); node->left = node1; node->right = node2; 
    TreeNode* node3 = new TreeNode(15); TreeNode* node4 = new TreeNode(7); node2->left = node3; node2->right = node4; 
    Solution* so = new Solution();
    vector<vector<int> > vv = so->zigzagLevelOrder(node);
    print(vv);
}
