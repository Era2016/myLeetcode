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
    vector<int> levelTravel(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q; 
        if (root) { q.push(root); }
        while (!q.empty()) {
            TreeNode* pNode = q.front(); q.pop();
            //cout <<"val: " << pNode->val << endl;
            v.push_back(pNode->val);

            if (pNode->left) { q.push(pNode->left); }
            if (pNode->right) { q.push(pNode->right); }
        }
        return v;
    }
};

int main() {
    vector<int> v;
    Solution* so = new Solution();

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(3);  TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(4);  TreeNode* node5 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(5);  TreeNode* node7 = new TreeNode(8);
    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5;
    node3->left = node6; node3->right = node7;

    v = so->levelTravel(node1); 
    for (int i = 0; i < (int)v.size(); i ++) {
        cout << v[i] << "\t"; // 1 3 6 4 7 5 8 
    }
    cout << endl;
}
