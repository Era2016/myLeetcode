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
    vector<vector<int> > levelTravel(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int> > vv;
        queue<TreeNode*> q; 
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> v(sz);
            for (int i = 0; i < sz; i ++) {
                TreeNode* node = q.front(); 
                q.pop();
                //v.push_back(node->val);
                v[i] = node->val;
                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
            vv.push_back(v);                
        }
        return vv;
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
    vector<vector<int> > vv = so->levelTravel(node);
    print(vv);
}
