// Definition for singly-linked list.
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(-1), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(const ListNode& l) : val(l.val), next(l.next) {}
};

ListNode* createList(std::vector<int>& v);

// pos == -1, meaning no ring
ListNode* createRingList(std::vector<int>& v, int pos);

void showList(ListNode* p);

ListNode* reverse(ListNode* head); 
ListNode* reverseN(ListNode *head, int n);
ListNode* reverseBetween(ListNode* head, int left, int right);
ListNode* reverseBetweenRecursively(ListNode* head, int left, int right);


bool isCycle (ListNode* head, ListNode* pCross);
