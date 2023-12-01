#include <iostream>
#include <map>
#include <list>

using std::map;
using std::list;

struct Node {
    int key, value;
    int freq;
    Node(int key, int value): key(key), value(value), freq(1) {};
    Node(int key, int value, int freq): key(key), value(value), freq(freq) {};
};
class LFUCache {
private:
    map<int, list<Node*>> m_freq; // freq->list
    map<int, list<Node*>::iterator> m_cache;  // key->Node*
    int capacity;
    int minFreq;
public:
    LFUCache(int _capaticy): capacity(_capaticy), minFreq(0) {
        m_freq.clear();
        m_cache.clear();
    }
    int get(int key) {
        auto it = m_cache.find(key);
        if (it == m_cache.end()) {
            return -1;
        }
        list<Node*>::iterator node = it->second;
        int val = (*node)->value, freq = (*node)->freq;
        m_freq[freq].erase(node);
        if (m_freq[freq].empty()) {
            m_freq.erase(freq);
            if (minFreq == freq) {
                minFreq += 1;
            }
        }
        m_freq[freq+1].push_front(new Node(key, val, freq+1));
        m_cache[key] = m_freq[freq+1].begin();
        return val;
    }

    void put(int key, int value) {
        auto it = m_cache.find(key);
        if (it != m_cache.end()) {
            list<Node*>::iterator node = it->second;
            int freq = (*node)->freq;
            m_freq[freq].erase(node); 
            if (m_freq[freq].empty()) {
                m_freq.erase(freq);
                minFreq = (minFreq == freq)? minFreq+1: minFreq;
            }
            m_freq[freq + 1].push_front(new Node(key, value, freq + 1));
            m_cache[key] = m_freq[freq + 1].begin();
            return;
        }

        if (m_cache.size() == capacity) {
            auto toDel = m_freq[minFreq].back();
            m_freq[minFreq].pop_back();
            m_cache.erase(toDel->key);
            if (m_freq[minFreq].empty()) {
                m_freq.erase(minFreq);
            }
        }
        m_freq[1].push_front(new Node(key, value, 1));
        m_cache[key] = m_freq[1].begin();
        minFreq = 1;
    }
};
