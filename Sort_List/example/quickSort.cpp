#include <iostream>
#include "nodeDef.h"

using namespace std;

//快速排序
class Solution {
public:
    ListNode* sortList(ListNode* head);
private:
    void QuickSort(ListNode* begin, ListNode* end);
    ListNode* quick(ListNode* begin, ListNode* end);
    //template<class T>
    //void swap(T& a, T& b);
};

//template<class T>
//void Solution::swap(T& a, T& b)
//{
//    T c;
//    c = a;
//    a = b;
//    b = c;
//}

ListNode* Solution::quick(ListNode* begin, ListNode* end)
{
    ListNode* p = begin->next;
    ListNode* ok = begin; // ok 小于begin的最有索引位置 
    while (p != end)
    {
        if (p->val < begin->val)
        {
            ok = ok->next;
            if (ok != p)
                swap(ok->val, p->val);
            p = p->next;
        }
        else
            p = p->next;
    }
    swap(ok->val, begin->val);
    return ok;
}

void Solution::QuickSort(ListNode* begin, ListNode* end)
{
    // 当前节点为空或者只剩下一个节点时，直接返回
    if (begin == end || begin->next == end)
        return;
    ListNode* pivotpoint = quick(begin, end);
    QuickSort(begin, pivotpoint);
    QuickSort(pivotpoint->next, end);
}

ListNode* Solution::sortList(ListNode* head)
{
    QuickSort(head, nullptr);
    return head;
}

void print(ListNode* pHead) {
    while (pHead != NULL) {
        cout << pHead->val << "\t";
        pHead = pHead->next;
    } 
    cout << endl;
}

int main() {
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(3);
    node1->next = node2; node2->next = node3; node3->next = node4;
    print(node1);

    Solution* so = new Solution();
    ListNode* head = so->sortList(node1);
    print(head);
}
