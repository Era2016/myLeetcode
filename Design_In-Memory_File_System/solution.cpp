#include <iostream>
#include <vector>
#include <map>

using namespace std;

class FileSystem {
public:
    FileSystem() {
        root = new Directory("");
    }

    // 缺少目录是否存在的判断，如果ls 一个不存在的目录，会出现空指针的问题
    vector<string> ls(string path) {
        vector<string> tokens = tokenize(path);
        Node* cur = root;
        for (auto& token : tokens) {
            cur = cur->next[token];
        }

        return cur->ls();
    }

    void mkdir(string path) {
        vector<string> tokens = tokenize(path);
        Node* cur = root;
        for (auto& token : tokens) {
            if (cur->next.count(token) == 0) {
                cur->next[token] = new Directory(token);
            }
            cur = cur->next[token];
        }
    }

    void addContentToFile(string filePath, string content) {
        vector<string> tokens = tokenize(filePath);
        Node* cur = root;
        for (auto& token : tokens) {
            if (cur->next.count(token) == 0) {
                cur->next[token] = new File(token);
            }
            cur = cur->next[token];
        }

        ((File*) cur)->append(content);
    }

    string readContentFromFile(string filePath) {
        vector<string> tokens = tokenize(filePath);
        Node* cur = root;
        for (auto& token : tokens) {
            cur = cur->next[token];
        }

        return ((File*) cur)->read();
    }

private:
    class Node {
    public:
        Node(const string& name) {
            this->name = name;
        }

        string getName() {
            return name;
        }

        virtual bool isDirectory() = 0;
        virtual vector<string> ls() = 0; 

        map<string, Node*> next;
    protected:
        string name;
    }; // end of Node

    class File : public Node {
    public:
        File(const string& name): Node(name) {}

        bool isDirectory() override{
            return false;
        }

        vector<string> ls() override {
            return {name};
        }

        void append(const string& str) {
            data.append(str);
        }

        string read() {
            return data;
        }
    private:
        string data;
    }; // end of File

    class Directory : public Node {
    public:
        Directory(const string& name): Node(name) {}

        bool isDirectory() override {
            return true;
        }

        vector<string> ls() override {
            vector<string> ret;
            for (auto it = next.begin(); it != next.end(); ++it) {
                ret.push_back(it->first);
            }

            return ret;
        }
    private:

    }; // end of Directory

    vector<string> tokenize(const string& path) {
        vector<string> ret;
        int pos = 1;
        string token;
        while (pos < (int)path.length()) {
            if (path[pos] == '/') {
                ret.push_back(token);
                token.clear();
            } else {
                token.push_back(path[pos]);
            }
            ++pos;
        }

        if (token.length() > 0) {
            ret.push_back(token);
        }

        return ret;
    }

    Node* root;
}; // end of FileSystem

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */

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
