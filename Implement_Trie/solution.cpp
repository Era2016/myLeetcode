#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Trie
{
private:
    vector<Trie *> children;
    bool isEnd;

    Trie *searchPrefix(string prefix)
    {
        Trie *node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }
};

int main()
{
    // Trie *obj = new Trie();
    // string word, prefix;

    // word = "apple";
    // obj->insert(word);
    // std::cout << obj->search(word) << std::endl;

    // prefix = "app";
    // std::cout << obj->startsWith(prefix) << std::endl;

    Trie *trie = new Trie();
    trie->insert("apple");
    std::cout << trie->search("apple") << std::endl;   // 返回 True
    std::cout << trie->search("app") << std::endl;     // 返回 False
    std::cout << trie->startsWith("app") << std::endl; // 返回 True
    trie->insert("app");
    std::cout << trie->search("app") << std::endl; // 返回 True
}
