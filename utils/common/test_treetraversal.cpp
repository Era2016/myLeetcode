#include <iostream>
#include <stack>
using namespace std;

// 二叉树的节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    stack<TreeNode*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode* current = nodeStack.top();
        nodeStack.pop();

        // 处理当前节点
        cout << current->val << " ";

        // 先将右子树入栈，再将左子树入栈
        if (current->right != nullptr) {
            nodeStack.push(current->right);
        }
        if (current->left != nullptr) {
            nodeStack.push(current->left);
        }
    }
}

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    stack<TreeNode*> nodeStack;
    TreeNode* current = root;

    while (current != nullptr || !nodeStack.empty()) {
        // 将左子树的所有节点入栈
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->left;
        }

        // 弹出栈顶节点并处理
        current = nodeStack.top();
        nodeStack.pop();
        cout << current->val << " ";

        // 处理右子树
        current = current->right;
    }
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    stack<TreeNode*> nodeStack;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;

    while (current != nullptr || !nodeStack.empty()) {
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->left;
        }

        current = nodeStack.top();

        // 检查右子树
        if (current->right == nullptr || current->right == lastVisited) {
            // 如果右子树为空或已经访问过，访问当前节点
            cout << current->val << " ";
            nodeStack.pop();
            lastVisited = current;
            current = nullptr;
        } else {
            // 否则，处理右子树
            current = current->right;
        }
    }
}

int main() {
    // 构建一个二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 执行非递归后序遍历
    cout << "Postorder Traversal: ";
    postOrderTraversal(root);

    return 0;
}