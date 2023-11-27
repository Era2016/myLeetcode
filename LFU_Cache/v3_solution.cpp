#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;
struct Node{
    int key, val;
    int freq;
    Node *next, *prev;
    Node(): key(0), val(0), freq(0), next(nullptr), prev(nullptr) {};
    Node(int key, int val): key(key), val(val), freq(1), next(nullptr), prev(nullptr) {};
    Node(int key, int val, Node* next, Node* prev): key(key), val(val), freq(1), next(next), prev(prev) {};
};
class LFUCache {
private:
    unordered_map<int, Node*> cache;
    Node *head, *tail;
    int capacity;
    int size;
    void insertNode(Node* node) {
        Node* prev = head, *ptr = head->next;
        while (ptr != tail && ptr->freq > node->freq) {
            prev = ptr;
            ptr = ptr->next;
        }
        node->next = prev->next;
        prev->next->prev = node;
        prev->next = node;
        node->prev = prev;
        return;
    }

    void deleteNode(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    Node* removeTail() {
        Node *node = tail->prev;
        cache.erase(node->key);
        deleteNode(node);
        return node;
    }
public:
    LFUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        this->size = 0;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } 
        Node* node = cache[key];
        node->freq ++;
        deleteNode(node);
        insertNode(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node *node = cache[key];
            node->val = value;
            node->freq ++;
            deleteNode(node);
            insertNode(node);
            return;
        }
        Node *node = new Node(key, value);
        cache[key] = node;
        //insertNode(node);
        this->size ++;
        if (this->size > this->capacity) {
            Node *toDel = removeTail();
            free(toDel);
            this->size --;
        }
        insertNode(node);
        return;
    }
};

int main() {
    LFUCache *lfu = new LFUCache(2);
    lfu->put(1, 1);              // cache=[1,_], cnt(1)=1
    lfu->put(2, 2);              // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lfu->get(1) << endl; // 返回 1
                                 // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu->put(3, 3);              // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                                 // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lfu->get(2) << endl; // 返回 -1（未找到）
    cout << lfu->get(3) << endl; // 返回 3
                                 // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu->put(4, 4);              // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                                 // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lfu->get(1) << endl; // 返回 -1（未找到）
    cout << lfu->get(3) << endl; // 返回 3
                                 // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lfu->get(4) << endl; // 返回 4
}
