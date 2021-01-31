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
    // bfs效率低
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return vector<int> {};                
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        int qLength = 1, tmpMax = root->val;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (tmpMax < node->val) tmpMax = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);

            if (--qLength == 0) {
                v.push_back(tmpMax); qLength = q.size();
                if (qLength != 0) {
                    TreeNode* tmp = q.front(); tmpMax = tmp->val;
                }
            }
        }
        return v;
    }
    
    // 递归，vector全局变量比参数效率更高：避免值拷贝
    vector<int> largestValuesV2(TreeNode* root) {
        vector<int> v;
        if (root != nullptr) 
            __largestValuesV2(root, v, 0);

        return v;
    }

    void __largestValuesV2(TreeNode* root, vector<int>& v, int depth) {
        if (root == nullptr) return;

        if ((int)v.size() == depth) {
            v.push_back(root->val);
        } else {
            if (v[depth] < root->val) {
                v[depth] = root->val;
            }
        }

        __largestValuesV2(root->left, v, depth+1);
        __largestValuesV2(root->right, v, depth+1);
    }
};

int main() {

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(3);  TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(4);  TreeNode* node5 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(5);  TreeNode* node7 = new TreeNode(8);
    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5;
    node3->left = node6; node3->right = node7;

    vector<int> v;
    Solution* so = new Solution();
    v = so->largestValues(node1);
    for (int i = 0; i < (int)v.size(); i ++) {
        cout << v[i] << "\t";
    }
    cout << endl;

    v = so->largestValuesV2(node1);
    for (int i = 0; i < (int)v.size(); i ++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}
