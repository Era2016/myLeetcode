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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	if(nums.size() == 0) return NULL;
        if(nums.size() == 1) {
            return new TreeNode(nums[0]);
        }
        
        int middle = nums.size()/2;
        TreeNode* root = new TreeNode(nums[middle]);
        
        vector<int> leftInts(nums.begin(), nums.begin()+middle);
        vector<int> rightInts(nums.begin()+middle+1, nums.end());
        
        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);
        
        return root;    
    }

	TreeNode* sortedArrayToBSTV2(vector<int>& nums) {
		return help(nums, 0, nums.size()-1);
	}

	TreeNode* help(vector<int> &nums, int start, int end) {
		int _size = end - start;
		if(_size < 0) return NULL;
		if(_size == 0) return new TreeNode(nums[start]);
		int mid = (start+end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = help(nums, start, mid-1);
		root->right = help(nums, mid+1, end);
		return root;
	}
};
