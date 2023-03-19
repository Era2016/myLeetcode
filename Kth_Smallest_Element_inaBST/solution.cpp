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
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        this->cnt = 0;

        int ret = 0;
		inOrder(root, &ret);
        return ret;
    	//vector<int> v;    
        //inOrderWithoutRecursive(root, v);
		//print(v);	
        //return v[k-1];
    }

private:
    int k, cnt;
	void inOrder(TreeNode* root, int* ret) {
		if (root != nullptr) {
			inOrder(root->left, ret);
            cnt ++;
            if (cnt == k) {
                *ret = root->val;
                //std::cout << "root: " << root->val<< "; cnt: " << cnt << std::endl;
                return;
            }
			inOrder(root->right, ret);	
		}
	}

    void inOrderWithoutRecursive(TreeNode* root, vector<int>& v) {
        vector<TreeNode*> stack;
        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.push_back(root);
                root = root->left;
            }   
            TreeNode* node = stack.back();
            stack.pop_back();

            v.push_back(node->val);
            root = node->right;
        }
    }

	void print(vector<int> v) {
		for (int i = 0; i < (int)v.size(); i ++) {
			cout << v[i] << "\t";
		}
		cout << endl;
	}
};

int main() {
	TreeNode* node = new TreeNode(3);
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(4);
	TreeNode* node3 = new TreeNode(2);
	node->left = node1; node->right = node2; node1->right = node3;
	
	Solution* so = new Solution();
	int k = so->kthSmallest(node, 2);
	cout << k << endl;
}
