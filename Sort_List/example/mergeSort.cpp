#include <iostream>
#include "nodeDef.h"

using namespace std;

//归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head);
private:
    ListNode* cut(ListNode* list, int num);
    ListNode* merge(ListNode* A, ListNode* B);
};

ListNode* Solution::merge(ListNode* A, ListNode* B)
{
    ListNode headnull(-1);
    ListNode* p = &headnull;
    while (A && B)
    {
        if (A->val < B->val)
        {
            p->next = A;
            p = p->next;
            A = A->next;
        }
        else
        {
            p->next = B;
            p = p->next;
            B = B->next;
        }
    }
    p->next = A ? A : B;
    return headnull.next;
}

ListNode* Solution::cut(ListNode* list, int num)
{
    if (!list)
        return nullptr;
    ListNode* p = list;
    int i = 1;
    while (i < num && p)
    {
        p = p->next;
        i++;
    }
    if (!p)
        return nullptr;
    ListNode* temp = p->next;
    p->next = nullptr;
    return temp;
}

ListNode* Solution::sortList(ListNode* head)
{
    ListNode headnull(-1);
    ListNode* p = &headnull;
    p->next = head;          
    ListNode* cur = head;
    int step = 1;
    int size = 0;
    while (cur)
    {
        size++;
        cur = cur->next;
    }

    while (step < size)
    {
        cur = headnull.next;   //*必须将head接到头节点headnull后面，否则只有一个节点时将出错；例如：输入：1；会输出空
        ListNode* cur = head;
        p = &headnull;         //*每轮排序都是新的，cur，p都要初始化
        p->next = nullptr;     //*
        while (cur)
        {
            ListNode* left = cur;
            ListNode* right = cut(left, step);
            cur = cut(right, step);

            p->next = merge(left, right);
            while (p->next)
                p = p->next;
        }
        step *= 2;
    }
    return headnull.next;
}
