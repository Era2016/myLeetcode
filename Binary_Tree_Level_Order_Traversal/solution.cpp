#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    //TreeNode(int v):val(v) {} // 指针随机赋值，需采用下面方法初始化
    TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r): val(v), left(l), right(r) {}
};

class Solution {
public:
    // bfs
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > vv; vector<int> v;
        queue<TreeNode*> q; int qLength;

        if (root) { 
            q.push(root); qLength = 1; 
        }

        while (!q.empty()) {
            TreeNode* pNode = q.front(); q.pop();
            //cout <<"val: " << pNode->val << endl;
            v.push_back(pNode->val);

            if (pNode->left) { q.push(pNode->left); }
            if (pNode->right) { q.push(pNode->right); }

            if (--qLength == 0) {
                vv.push_back(v); v.clear();
                qLength = (int)q.size();
            }
        }
        return vv;
    }

    // dfs, preorder: awesome !!
    vector<vector<int> > levelOrderV2(TreeNode* root) {
        vector<vector<int> > vv;
        __levelOrderV2(root, vv, 0); 
        return vv;
    }
private:
    void __levelOrderV2(TreeNode* root, vector<vector<int> >& vv, int depth) {
        if (root == nullptr) return;
        if ((int)vv.size() == depth) {
            vv.push_back(vector<int> ()); 
        }
        vv[depth].push_back(root->val);
        __levelOrderV2(root->left, vv, depth+1);
        __levelOrderV2(root->right, vv, depth+1);
    }
};

int main() {
    vector<vector<int> > vv;
    Solution* so = new Solution();

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(3);  TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(4);  TreeNode* node5 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(5);  TreeNode* node7 = new TreeNode(8);
    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5;
    node3->left = node6; node3->right = node7;

    vv = so->levelOrder(node1); 
    for (int i = 0; i < (int)vv.size(); i ++) {
        for (int j = 0; j < (int)vv[i].size(); j ++) {
            cout << vv[i][j] << "\t"; // 1 3 6 4 7 5 8 
        }
        cout << endl;
    }
    cout << endl;


    vv = so->levelOrderV2(node1);
    for (int i = 0; i < (int)vv.size(); i ++) {
        for (int j = 0; j < (int)vv[i].size(); j ++) {
            cout << vv[i][j] << "\t"; // 1 3 6 4 7 5 8 
        }
        cout << endl;
    }
    cout << endl;
}
