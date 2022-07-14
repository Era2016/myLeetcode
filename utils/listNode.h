// Definition for singly-linked list.
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(std::vector<int>& v);

// pos == -1, meaning no ring
ListNode* createRingList(std::vector<int>& v, int pos);

void showList(ListNode* p);

ListNode* reverse(ListNode* head); 

bool isCycle (ListNode* head, ListNode* pCross);
