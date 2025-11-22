/*
 * 队列长度，减少逻辑判断
 * 双向链表，根据index判断是从头开始遍历还是尾开始遍历 TODO
 * 节点缓存，避免频繁申请、释放内存 TODO
 */

#include <iostream>
#include <vector>


class MyLinkedList {
private:
    class BiDirectionalListNode {
    public:
        int val;
        BiDirectionalListNode *next, *prev;
        BiDirectionalListNode() : val(0), next(nullptr), prev(nullptr) {}
        BiDirectionalListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
    };
    class NodePool {
        std::vector<BiDirectionalListNode> block;
        int index = 0;
    public:
        BiDirectionalListNode *allocate(int val) {
            if (index >= block.size())
                block.resize(block.size() + 100);
            return new (&block[index++]) BiDirectionalListNode(val);
        }
};
    BiDirectionalListNode *dummyHead, *dummyTail;
    int length;

public:
    MyLinkedList() {
        this->length = 0;
        this->dummyHead = new BiDirectionalListNode();
        this->dummyTail = new BiDirectionalListNode();
        this->dummyHead->next = this->dummyTail;
        this->dummyTail->prev = this->dummyHead;
    }
    ~MyLinkedList() {
        BiDirectionalListNode *node = dummyHead;
        while (node) {
            BiDirectionalListNode *next = node->next;
            delete node;
            node = next;
        }
        this->length = 0;
    }

    bool isValidIndex(int index) {
        return index >= 0 && index < length;
    }
    bool canInsertIndex(int index) {
        return index >= 0 && index <= length;
    }

    int get(int index) {
        if (!isValidIndex(index)) return -1;
        BiDirectionalListNode* p = dummyHead->next;
        int cursor = 0;
        while (cursor < index) {
            cursor++;
            p = p->next;
        }

        return p->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(length, val);
    }

    void addAtIndex(int index, int val) {
        if (!canInsertIndex(index)) return;

        // 1->2->3
        BiDirectionalListNode* p = dummyHead;
        int cursor = 0;
        while (cursor < index) {
            cursor++;
            p = p->next;
        }

        BiDirectionalListNode* node = new BiDirectionalListNode(val);
        node->next = p->next;
        node->prev = p;
        p->next->prev = node;
        p->next = node;

        this->length ++;
    }

    void deleteAtIndex(int index) {
        if (!isValidIndex(index)) return;

        // 1->2->3
        BiDirectionalListNode* p = dummyHead;
        int cursor = 0;
        while (cursor < index) {
            cursor++;
            p = p->next;
        }

        BiDirectionalListNode* toDelete = p->next;
        toDelete->next->prev = p;
        p->next = toDelete->next;

        this->length --;
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
