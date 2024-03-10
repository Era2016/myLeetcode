#include <iostream>
#include <vector>

#include "../utils/listNode.h"
#include "../utils/binaryTree.h"

using std::vector;
using std::string;
class Solution {
private:
    ListNode* getMidListNode(ListNode* left, ListNode* right) {
        ListNode *fast = left, *slow = left;
        while (fast != right && fast->next != right) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode* build(ListNode *head, ListNode *tail) {
        if (head == tail) {
            return nullptr;
        }
        ListNode *mid = getMidListNode(head, tail);
        TreeNode *root = new TreeNode(mid->val);
        root->left = build(head, mid);
        root->right = build(mid->next, tail);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, nullptr);
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    ListNode *head;
    TreeNode *root;

    v = {-10,-3,0,5,9};
    head = createList(v);
    showList(head);
    root = so->sortedListToBST(head);
    bfs(root);

    v = {};
    head = createList(v);
    showList(head);
    root = so->sortedListToBST(head);
    bfs(root);
}
