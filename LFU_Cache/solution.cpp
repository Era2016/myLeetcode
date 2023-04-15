#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::pair;
using std::unordered_map;

struct DLinkNode
{
    int key, value;
    int frequency;
    DLinkNode *prev, *next;
    DLinkNode() : key(0), value(0), frequency(0), prev(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _value) : key(_key), value(_value), frequency(1), prev(nullptr), next(nullptr) {}
};

struct DLinkList
{
    DLinkNode *head, *tail;
    int size;
    DLinkList() : size(0), head(nullptr), tail(nullptr) {}
    DLinkList(DLinkNode *_head, DLinkNode *_tail) : size(0), head(_head), tail(_tail) {}
};

class LFUCache
{
private:
    unordered_map<int, DLinkNode *> m_cache; // key->node
    unordered_map<int, DLinkList *> m_freq;  // freq->headNode
    int capacity;
    int minFreq;

public:
    LFUCache(int cap) : capacity(cap), minFreq(0)
    {
        m_cache.clear();
        m_freq.clear();
    }
    int get(int key);
    void put(int key, int value);

    // DLinkList encapsulation
    void addToHead(int frequency, DLinkNode *node);
    void remove(int frequency, DLinkNode *node);
    DLinkNode *removeTail(int frequency);
};

void LFUCache::addToHead(int frequency, DLinkNode *node)
{
    DLinkNode *dummyHead, *dummyTail;
    if (!m_freq.count(frequency))
    {
        dummyHead = new DLinkNode();
        dummyTail = new DLinkNode();
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;

        DLinkList *dlist = new DLinkList(dummyHead, dummyTail);
        m_freq[frequency] = dlist;
    }

    DLinkList *dlist = m_freq[frequency];
    dlist->size++;

    dummyHead = dlist->head;

    node->next = dummyHead->next;
    node->prev = dummyHead;
    dummyHead->next->prev = node;
    dummyHead->next = node;
}

void LFUCache::remove(int frequency, DLinkNode *node)
{
    DLinkList *dlist = m_freq[frequency];
    dlist->size--;
    if (dlist->size == 0)
    {
        m_freq.erase(frequency);
        if (frequency == minFreq)
        {
            minFreq++;
        }
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = nullptr;
    node->prev = nullptr;
}

DLinkNode *LFUCache::removeTail(int frequency)
{
    DLinkNode *toDelete = m_freq[frequency]->tail->prev;
    remove(frequency, toDelete);
    return toDelete;
}

int LFUCache::get(int key)
{
    if (!m_cache.count(key))
    {
        return -1;
    }

    DLinkNode *node = m_cache[key];
    int freq = node->frequency;

    remove(freq, node);
    addToHead(freq + 1, node);
    node->frequency++;
    return node->value;
}

void LFUCache::put(int key, int value)
{
    if (!m_cache.count(key))
    {
        DLinkNode *node = new DLinkNode(key, value);
        addToHead(1, node);
        m_cache[key] = node;

        if (m_cache.size() > capacity)
        {
            DLinkNode *node = removeTail(minFreq);
            m_cache.erase(node->key);
            delete node;
        }
        minFreq = 1;
    }
    else
    {
        DLinkNode *node = m_cache[key];
        node->value = value;
        remove(node->frequency, node);
        addToHead(node->frequency + 1, node);
        node->frequency++;
    }
}

int main()
{
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
                                 // cache=[3,4], cnt(4)=2, cnt(3)=3
}