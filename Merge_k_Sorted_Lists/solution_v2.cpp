#include <iostream>
#include <vector>
#include <queue>
#include "../utils/listNode.h"

using std::vector;
using std::priority_queue;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto my_comp = [](const ListNode* l1, const ListNode* l2) {
            return l2->val < l1->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(my_comp)> pq(my_comp); 
        for (const auto& ptr: lists) {
            if (ptr != nullptr) {
                pq.push(ptr); 
            }
        }

        ListNode *dummy = new ListNode(), *ptr = dummy;
        while (!pq.empty()) {
            ListNode *node = pq.top(); pq.pop();
            ptr->next = node;
            ptr = ptr->next;
            if (node->next != nullptr) pq.push(node->next);
        }

        return dummy->next;
    }
};

int main() {
    vector<int> v1 = {1,3,5,7,9};
    vector<int> v2 = {2,4,6,8,10};
    vector<int> v3 = {11,14};
    vector<int> v4 = {13,19};
    vector<int> v5 = {10,15};
    ListNode* l1 = createList(v1); 
    ListNode* l2 = createList(v2); 
    ListNode* l3 = createList(v3); 
    ListNode* l4 = createList(v4); 
    ListNode* l5 = createList(v5); 

    //showList(l1);
    //showList(l2);

    vector<ListNode*> vl = {l1, l2, l3, l4, l5};
    Solution *so = new Solution();
    ListNode* ll = so->mergeKLists(vl);
    showList(ll);
    
    vl = {};
    ll = so->mergeKLists(vl);
    showList(ll);
}
