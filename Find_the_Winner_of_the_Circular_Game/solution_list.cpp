#include <iostream>
using namespace std;

// 节点定义
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// 约瑟夫环函数
int josephus(int n, int m) {
    Node* head = new Node(1);
    Node* current = head;

    // 构建循环链表
    for (int i = 2; i <= n; ++i) {
        current->next = new Node(i);
        current = current->next;
    }

    // 将尾节点连接到头节点，形成循环链表
    Node* prev = current;
    current->next = head;

    // 模拟约瑟夫环过程
    while (head->next != head) {
        for (int i = 1; i < m; ++i) {
            prev = head;
            head = head->next;
        }

        // 移除第 m 个节点
        prev->next = head->next;
        delete head;
        head = prev->next;
    }

    int survivor = head->data;
    delete head; // 删除最后一个节点

    return survivor;
}

int main() {
    int n = 7; // 总人数
    int m = 3; // 数到第 m 个人

    cout << "The survivor is at position: " << josephus(3, 1) << endl;
    cout << "The survivor is at position: " << josephus(3, 2) << endl;
    cout << "The survivor is at position: " << josephus(5, 2) << endl;
    cout << "The survivor is at position: " << josephus(5, 3) << endl;

    return 0;
}
