#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;
using std::string;
using std::cout;
using std::endl;
struct Node{
    map<string, Node*> children;
    string name;
    string content;
    bool isDir;
    Node():children(std::less<string>()) {}; 
    Node(string _name, bool _isdir): children(std::less<string>()), name(_name), isDir(_isdir) {};
    Node(string _name, string _content): children(std::less<string>()), name(_name), content(_content) {};

    string getName() { return name; }
    bool dir() { return isDir == true; }
    string read() { return content; }
    void write(string data) { content += data; }
};

class FileSystem {
private:
    Node* root;
public:
    FileSystem() {
        this->root = new Node("/", true);
    }

    vector<string> splitString(const string& input, char delimiter) {
        vector<string> tokens;
        auto start = input.begin();
        auto end = std::find(start, input.end(), delimiter); 
        while (end != input.end()) {
            tokens.emplace_back(start, end);
            start = std::next(end);
            end = std::find(start, input.end(), delimiter);
        }
        tokens.emplace_back(start, end);
        return tokens;
    }

    vector<string> ls(string path) {
        vector<string> tokens = splitString(path, '/');
        if (tokens.empty() ) return {};

        Node* node = root;
        for (const auto& token: tokens) {
            if (node->children.find(token) == node->children.end() ) return {};
            node = node->children[token]; 
        }
        
        if (!node->dir() ) { 
            return { node->getName() }; 
        }
        vector<string> res;
        for (const auto& k: node->children) {
            res.emplace_back(k.first);
        }
        return res;
    }

    void mkdir(string path) {
        vector<string> tokens = splitString(path, '/');
        Node *ptr = this->root;
        for (const auto& token: tokens) {
            if (ptr->children.count(token) ) { 
                ptr = ptr->children[token];
                continue; 
            }
            Node* node = new Node(token, true);
            ptr->children[token] = node;
            ptr = node;
        }
    }

    void addContentToFile(string path, string content) {
        vector<string> tokens = splitString(path, '/');
        Node *ptr = this->root;
        auto start = tokens.begin();
        for (; start != tokens.end()-1; start ++) {
            if (ptr->children.count(*start) == 0) {
                return;
            }
            ptr = ptr->children[*start];
        }
        Node *file = new Node(*start, false);
        ptr->children[*start] = file;
        return file->write(content); 
    }

    string readContentFromFile(string path) {
        vector<string> tokens = splitString(path, '/');
        Node *ptr = this->root;
        for (const auto& token: tokens) {
            if (ptr->children.count(token) == 0) {
                return "";
            }
            ptr = ptr->children[token];
        }
        return ptr->read();
    }
};

int main() {
    FileSystem* fs = new FileSystem();
    vector<string> v;
    auto print=[](vector<string>& arr) {
        for (auto iter: arr) {
            cout << iter << endl;
        }
        cout << endl;
    };
    v = fs->ls("/"); // ls /a/b -> exception
    print(v);

    fs->mkdir("/home/fan/test");
    v = fs->ls("/home");
    print(v);

    fs->mkdir("/home/fan/bin");
    v = fs->ls("/home/fan");
    print(v);

    fs->addContentToFile("/home/fan/text.txt", "hello world");
    v = fs->ls("/home/fan");
    print(v);

    cout << fs->readContentFromFile("/home/fan/text.txt");
}
