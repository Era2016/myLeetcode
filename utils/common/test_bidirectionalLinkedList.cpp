#include <iostream>

class MyLinkedList {
private:
    class BiDirectionalListNode {
    public:
        int val;
        BiDirectionalListNode *next, *prev;
        BiDirectionalListNode() : val(0), next(nullptr), prev(nullptr) {}
        BiDirectionalListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
    };
    BiDirectionalListNode *dummyHead, *dummyTail;

public:
    MyLinkedList() {
        this->dummyHead = new BiDirectionalListNode();
        this->dummyTail = new BiDirectionalListNode();
        this->dummyHead->next = this->dummyTail;
        this->dummyTail->prev = this->dummyHead;
    }

    int get(int index) {
        if (index < 0)
            return -1;
        BiDirectionalListNode* p = dummyHead->next;
        int cursor = 0;
        while (cursor < index && p != dummyTail) {
            cursor++;
            p = p->next;
        }

        if (cursor == index && p != dummyTail) {
            return p->val;
        }
        return -1;
    }

    void addAtHead(int val) {
        BiDirectionalListNode* node = new BiDirectionalListNode(val);
        node->next = dummyHead->next;
        node->prev = dummyHead;

        dummyHead->next->prev = node;
        dummyHead->next = node;
    }

    void addAtTail(int val) {
        BiDirectionalListNode* node = new BiDirectionalListNode(val);
        node->next = dummyTail;
        node->prev = dummyTail->prev;

        dummyTail->prev->next = node;
        dummyTail->prev = node;
    }

    void addAtIndex(int index, int val) {
        if (index == 0)
            return addAtHead(val);

        // 1->2->3
        BiDirectionalListNode* p = dummyHead;
        int cursor = 0;
        while (cursor < index && p->next != dummyTail) {
            cursor++;
            p = p->next;
        }
        if (p->next == dummyTail && cursor < index) {
            return;
        }

        BiDirectionalListNode* node = new BiDirectionalListNode(val);
        node->next = p->next;
        node->prev = p;
        p->next->prev = node;
        p->next = node;
    }

    void deleteAtIndex(int index) {
        BiDirectionalListNode* p = dummyHead;
        if (p->next == dummyTail) {
            return;
        }

        // 1->2->3
        int cursor = 0;
        while (cursor < index && p->next->next != dummyTail) {
            cursor++;
            p = p->next;
        }
        if (cursor < index && p->next->next == dummyTail)
            return;

        BiDirectionalListNode* toDelete = p->next;
        toDelete->next->prev = p;
        p->next = toDelete->next;
    }

    void destroy() {
        BiDirectionalListNode *node = dummyHead->next;
        int index = 0;
        while (node != dummyTail) {
            deleteAtIndex(index);
            node = node->next;
        }
    }

    void print() {
        BiDirectionalListNode *node = dummyHead->next;
        while (node != dummyTail) {
            std::cout << node->val << "\t";
            node = node->next;
        }
        std::cout << std::endl;
    }
};


int main () {

    MyLinkedList* obj = new MyLinkedList();

    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);    // 链表变为 1->2->3
    obj->print();

    std::cout << obj->get(1) << std::endl;              // 返回 2
    obj->deleteAtIndex(1);    // 现在，链表变为 1->3
    std::cout << obj->get(1) << std::endl;              // 返回 3
    obj->print();             // 现在，链表变为 1->3


    obj->destroy(); 
    obj->print();

    obj->deleteAtIndex(1);


    obj->addAtIndex(1, 0);
    std::cout << obj->get(0) << std::endl;              // 返回-1
}
