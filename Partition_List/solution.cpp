#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int _val): val(_val), next(nullptr) {}
    ListNode(int _val, ListNode *_next): val(_val), next(_next) {}
};

class Solution {
public:
    /*ListNode* patition2(ListNode *head, int x) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *small = dummy, *ptr = head, *pre = dummy;

        while (ptr != nullptr) {
            if (ptr->val < x) {
                ListNode *tmp = ptr->next;
                pre->next = tmp;
                ptr->next = small->next;
                small->next = ptr;

                small = small->next;
                ptr = tmp;
            } else {
                pre = ptr;
                ptr = ptr->next;
            }
        }

        return dummy->next;
    }*/
    
    ListNode* partition(ListNode *head, int x) {
        ListNode *dummySmall = new ListNode(), *pSmall = dummySmall;
        ListNode *dummyLarge = new ListNode(), *pLarge = dummyLarge;
        ListNode *ptr = head;
        while (ptr != nullptr) {
            if (ptr->val < x) {
                pSmall->next = ptr;
                pSmall = pSmall->next;
            } else {
                pLarge->next = ptr;
                pLarge = pLarge->next;
            }

            ptr = ptr->next;
        }
        pLarge->next = nullptr;
        pSmall->next = dummyLarge->next;
        return dummySmall->next;
    }
};

int main() {
    Solution *so = new Solution();
    auto print = [](ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val << "\t";
            head = head->next;
        }
        std::cout << std::endl;
    };
    auto construct1 = []() {
        ListNode *dummy = new ListNode(), *ptr = dummy;
        ListNode *node1 = new ListNode(1); ptr->next = node1; ptr = node1;
        ListNode *node2 = new ListNode(4); ptr->next = node2; ptr = node2;
        ListNode *node3 = new ListNode(3); ptr->next = node3; ptr = node3;
        ListNode *node4 = new ListNode(2); ptr->next = node4; ptr = node4;
        ListNode *node5 = new ListNode(5); ptr->next = node5; ptr = node5;
        ListNode *node6 = new ListNode(2); ptr->next = node6; ptr = node6;
        return dummy->next;
    };

    ListNode *head = construct1();
    print(head);
    ListNode *ptr = so->partition(head, 3);
    print(ptr);

    auto construct2 = []() {
        ListNode *dummy = new ListNode(), *ptr = dummy;
        ListNode *node1 = new ListNode(2); ptr->next = node1; ptr = node1;
        ListNode *node2 = new ListNode(1); ptr->next = node2; ptr = node2;
        return dummy->next;
    }; 
    head = construct2();
    print(head);
    ptr = so->partition(head, 2);
    print(ptr);

    auto construct3 = []() {
        ListNode *dummy = new ListNode(), *ptr = dummy;
        ListNode *node1 = new ListNode(1); ptr->next = node1; ptr = node1;
        ListNode *node2 = new ListNode(4); ptr->next = node2; ptr = node2;
        ListNode *node3 = new ListNode(3); ptr->next = node3; ptr = node3;
        ListNode *node4 = new ListNode(0); ptr->next = node4; ptr = node4;
        ListNode *node5 = new ListNode(2); ptr->next = node5; ptr = node5;
        ListNode *node6 = new ListNode(5); ptr->next = node6; ptr = node6;
        ListNode *node7 = new ListNode(2); ptr->next = node7; ptr = node7;
        return dummy->next;
    }; 
    head = construct3();
    print(head);
    ptr = so->partition(head, 3);
    print(ptr);

    auto construct4 = []() {
        ListNode *dummy = new ListNode(), *ptr = dummy;
        ListNode *node1 = new ListNode(1); ptr->next = node1; ptr = node1;
        ListNode *node2 = new ListNode(1); ptr->next = node2; ptr = node2;
        return dummy->next;
    }; 
    head = construct4();
    print(head);
    ptr = so->partition(head, 2);
    print(ptr);
}
