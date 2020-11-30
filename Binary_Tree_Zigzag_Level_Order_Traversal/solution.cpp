#include <iostream>
#include <vector>

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
        travel(vv, root, 0);
        return vv;
    }

private:
    void travel(vector<vector<int> >& vv, TreeNode* root, int level) {
        if (root == nullptr) return;

        if (level < (int)vv.size()) { vv.push_back(vector<int>{}); }
    
        vector<int> curV = vv[level];
        if (level % 2) { curV.push_back(root->val); }
        else { curV.insert(curV.begin(), root->val); }

        travel(vv, root->left, level+1);
        travel(vv, root->right, level+1);
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
    TreeNode* node = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2); TreeNode* node2 = new TreeNode(3); node->left = node1; node->right = node2; 
    Solution* so = new Solution();
    vector<vector<int> > vv = so->zigzagLevelOrder(node);
    print(vv);
}
