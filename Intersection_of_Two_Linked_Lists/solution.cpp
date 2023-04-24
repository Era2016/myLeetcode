#include <iostream>

using std::swap;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
//private:
    public:
    int len(ListNode *head) {
        int i = 0;
        while (head != nullptr) {
            i ++;
            head = head->next;
        }
        return i;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = len(headA);
        int lengthB = len(headB);

        if (lengthA > lengthB) {
            int minus = lengthA - lengthB;
            while (minus > 0) {
                headA = headA->next;
                minus --;
            }
        } else {
            int minus = lengthB - lengthA;
            while (minus > 0) {
                headB = headB->next;
                minus --;
            }
        }

        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};

ListNode* Construct(int start, int end) {
    if (start > end) { return nullptr; }
    ListNode *head = new ListNode(-1);
    ListNode *ptr = head;
    for (int i = start; i <= end; i ++) {
        ListNode *node = new ListNode(i); 
        ptr->next = node;
        ptr = ptr->next;
    } 

    return head->next;
}

void print(ListNode *head) {
    int length = 0;
    while (head != nullptr) {
        std::cout << head->val << "\t";
        head = head->next;
        length ++;
    }
    std::cout << std::endl << "length: " << length << std::endl;
    std::cout << std::endl;
}

int main () {
    Solution *so = new Solution();
    ListNode *head1 = Construct(1, 5);    

    std::cout << so->len(head1) << std::endl; 
    std::cout << so->len(head1) << std::endl; 
    
    ListNode *head2 = head1->next->next; 
    ListNode *intersection = so->getIntersectionNode(head2, head1);
    print(intersection);
}
