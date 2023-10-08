#include <iostream>
#include <vector>
#include "../utils/listNode.h"

using namespace std;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        
        int length = 0;
        ListNode *ptr = head, *prev = nullptr;
        while (ptr != nullptr) {
            length ++;
            prev = ptr;
            ptr = ptr->next;
        }

        int cnt = length-k%length; // 新链表的最后一个节点，即原链表的第 (n−1)−(k mod n)个节点[从0开始计算]
        prev->next = head; // tail->next=head; 循环链表
        ptr = head;
        while (cnt --) {
            ptr = ptr->next;
            prev = prev->next;
        }
        prev->next = nullptr;
        return ptr;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    ListNode *head;
    int k = 0;

    v = {1,2,3,4,5};
    k = 2;
    head = createList(v);
    head = so->rotateRight(head, k);
    showList(head);

    v = {0,1,2};
    k = 4;
    head = createList(v);
    head = so->rotateRight(head, k);
    showList(head);

    v = {1,2};
    k = 1;
    head = createList(v);
    head = so->rotateRight(head, k);
    showList(head);
}