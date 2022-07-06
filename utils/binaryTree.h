
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr) {} ;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {};
    TreeNode(int v, TreeNode* left, TreeNode* right): val(v), left(left), right(right) {};
};

TreeNode* buildBinaryTree(std::vector<std::string>& v);
void bfs(TreeNode* root);