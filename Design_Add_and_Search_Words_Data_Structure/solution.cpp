#include <iostream>
#include <vector>

using std::string;
using std::vector;
class Trie
{
public:
    bool isEnd;
    vector<Trie *> children;
    Trie() : children(26), isEnd(false) {}

    void insert(string word)
    {
        Trie *node = this;

        for (auto ch : word)
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
};

class WordDictionary
{
private:
    Trie *trie;
    bool dfs(const string &word, int index, Trie *node)
    {
        if (index == word.size())
        {
            return node->isEnd;
        }

        char ch = word[index];
        if (ch >= 'a' && ch <= 'z')
        {
            node = node->children[ch - 'a'];
            if (node != nullptr && dfs(word, index + 1, node))
            {
                return true;
            }
        }
        else if (word[index] == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                Trie *child = node->children[i];
                if (child != nullptr && dfs(word, index + 1, child))
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    WordDictionary()
    {
        trie = new Trie();
    }

    void addWord(string word)
    {
        trie->insert(word);
    }

    bool search(string word)
    {
        return dfs(word, 0, trie);
    }
};

int main()
{
    WordDictionary *wordDictionary = new WordDictionary();
    wordDictionary->addWord("bad");
    wordDictionary->addWord("dad");
    wordDictionary->addWord("mad");
    std::cout << wordDictionary->search("pad") << std::endl; // 返回 False
    std::cout << wordDictionary->search("bad") << std::endl; // 返回 True
    std::cout << wordDictionary->search(".ad") << std::endl; // 返回 True
    std::cout << wordDictionary->search("b..") << std::endl; // 返回 True
}