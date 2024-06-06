#include <iostream>
#include <locale>
#include <unordered_map>

using std::unordered_map;
using std::string;
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode(): isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode *currentNode = root;
        for (char ch: word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode *currentNode = root;
        for (char ch: word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        TrieNode *currentNode = root;
        for (char ch: prefix) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return true;
    }
};

int main() {
    Trie* trie = new Trie();

    trie->insert("hello");
    trie->insert("world");
    trie->insert("hi");

    std::cout << "Search 'hello': " << trie->search("hello") << std::endl; // true
    std::cout << "Search 'world': " << trie->search("world") << std::endl; // true
    std::cout << "Search 'hell': " << trie->search("hell") << std::endl;   // false
    std::cout << "Starts with 'wor': " << trie->startsWith("wor") << std::endl; // true
    std::cout << "Starts with 'woe': " << trie->startsWith("woe") << std::endl; // false

    return 0;
}

