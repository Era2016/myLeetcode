class TrieNode:
    def __init__(self):
        self.children = {}
        self.nicknames = set()

class NicknameSearch:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, nickname):
        node = self.root
        for char in nickname:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
            node.nicknames.add(nickname)

    def search(self, query):
        node = self.root
        for char in query:
            if char not in node.children:
                return []
            node = node.children[char]

        return list(node.nicknames)

# Example usage:
nickname_search = NicknameSearch()
nicknames = ["john", "jane", "jack", "jill", "hello world", "hi world"]
for nickname in nicknames:
    nickname_search.insert(nickname)

search_result = nickname_search.search("world")
#search_result = nickname_search.search("h")
print(search_result)  # Output: ['hello world']

