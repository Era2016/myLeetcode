#include <vector>
#include "../utils/binaryTree.h"

using std::vector;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return _construct(nums, 0, nums.size()-1);
    }

    TreeNode* _construct(vector<int> &nums, int start, int end) {
        if (start <= end) {
            int index = findMaxIndex(nums, start, end);
            TreeNode *root = new TreeNode(nums[index]);
            root->left = _construct(nums, start, index-1);
            root->right = _construct(nums, index+1, end);
            return root;
        }
        return nullptr;
    }

    int findMaxIndex(vector<int> &nums, int start, int end) {
        int maxVal = nums[start];
        int maxIndex = start;
        for (int i = start+1; i <= end; i ++) {
            if (maxVal < nums.at(i)) {
                maxVal = nums.at(i);
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};

