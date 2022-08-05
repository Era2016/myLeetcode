#include <iostream>
#include <queue>
#include <vector>
#include "../utils/listNode.h"

using std::vector;
using std::priority_queue;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto m_cmp = [](ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(m_cmp)> pq(m_cmp); 
        for (auto k: lists) {
            if (k != nullptr)
                pq.push(k);
        }

        ListNode *dummy = new ListNode(), *head = dummy;
        while (!pq.empty()) {
            ListNode* tmp = pq.top();
            pq.pop();

            dummy->next = tmp;
            dummy = dummy->next;

            if (tmp->next) {
                tmp = tmp->next;
                pq.push(tmp);
            }
        }
        return head->next;
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
