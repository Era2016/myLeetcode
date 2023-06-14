#include <vector>
#include "../utils/binaryTree.h"

using std::vector;
class Solution {
private:
    TreeNode* build(vector<int>& nums, vector<int>::iterator start, vector<int>::iterator end) {
        if (start >= end) return nullptr;
        auto maxIter = std::max_element(start, end);
        //if (maxIter == end) return nullptr;

        TreeNode* root = new TreeNode(*maxIter);
        root->left = build(nums, start, maxIter);
        root->right = build(nums, maxIter+1, end);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return build(nums, nums.begin(), nums.end());
    }
};

int main() {
    Solution* so = new Solution();
    TreeNode* root;
    vector<int> v;

    v = {3,2,1,6,0,5};
    root = so->constructMaximumBinaryTree(v);
    bfs(root);
}
