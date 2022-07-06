#include <iostream>
#include <vector>

#include "../utils/listNode.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;

        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p2 && p1 != p2) {
            p1 = p1->next;
            if (p2->next) 
                p2 = p2->next->next;
            else
                return false;
        }

        return p2==nullptr? false: true;
    }
};

int main() {
    Solution* so = new Solution();
    std::vector<int> v; 
    ListNode* p; 

    v = {3,2,0,-4};
    p = createList(v);
    if (!so->hasCycle(p)) showList(p);
    std::cout << "has cycle: " << so->hasCycle(p) << std::endl;
}
