#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr) {} ;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {};
    TreeNode(int v, TreeNode* left, TreeNode* right): val(v), left(left), right(right) {};
};

TreeNode* buildBinaryTree(vector<string>& v) {
    if (v.size() < 1 || v[0] == "null") return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(v[0]));
    q.push(root);
    int index = 1;

    while (!q.empty() && index < v.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left == nullptr) {
            if (index >= v.size()) break;

            if( v[index] != "null") {
                node->left = new TreeNode(stoi(v[index]));
                q.push(node->left);
            }
            index ++;
        }

        if (node->right == nullptr) {
            if (index >= v.size()) break;

            if (v[index] != "null") {
                node->right = new TreeNode(stoi(v[index]));
                q.push(node->right);
            }
            index ++;
        }
    }

    return root;
}

void bfs(TreeNode* root) {
    if (root == nullptr) return;

    TreeNode* pRoot = root;
    int depth = 1;

    queue<TreeNode*> q;
    q.push(pRoot);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i ++) {
            TreeNode* ptr = q.front();
            cout << "the depth: "<< depth << " "<< ptr->val << "\t";
            q.pop();

            if (ptr->left != nullptr) {
                q.push(ptr->left);
            }

            if (ptr->right != nullptr) {
                q.push(ptr->right);
            }
        }

        depth ++;
        cout << endl;
    }

}

void print(vector<vector<int>>& vv) {

    for (vector<vector<int>>::iterator iter = vv.begin(); iter != vv.end(); iter ++) {
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it ++) {
            cout << *it << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
private:
    vector<vector<int>> vv;
    vector<int> v;
    // dfs
    void traverse(TreeNode* r, int targetSum) {
        if (r == nullptr) {
            return;
        }

        v.push_back(r->val);
        targetSum -= r->val;
        if (r->left == nullptr && r->right == nullptr && targetSum == 0) { 
            vv.push_back(v);
            //return; // cannot return, data in stack not pop
        }

        traverse(r->left, targetSum);
        traverse(r->right, targetSum);
        v.pop_back();
    } 
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        traverse(root, targetSum);
        return vv;
    }
};

int main() {
    vector<string> v = {"5","4","8","11","null","13","4","7","2","null","null","5","1"};
    TreeNode* root = buildBinaryTree(v); 
    //bfs(root);
    
    Solution* so = new Solution();
    vector<vector<int>> vv = so->pathSum(root, 22);
    print(vv);
}

