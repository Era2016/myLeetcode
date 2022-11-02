#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::pair;
using std::srand;
using std::rand;
using std::time;

class RandomizedSet {
private:
    vector<int> v;
    unordered_map<int, int> um;
public:
    RandomizedSet() {
        v = {}; 
        um = {};
        srand(time(0));
    }

    bool insert(int val) {
        if (um.count(val)) {
            return false;
        }

        um.insert(pair<int,int>(val, v.size()));
        v.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!um.count(val)) {
            return false;
        }

        int index = um[val];
        um[v.back()] = index;
        v[index] = v[v.size()-1];

        um.erase(val);
        v.pop_back();
        return true;
    }

    int getRandom() {
        return v[rand()%v.size()];
    }
};

int main() {
    RandomizedSet *rs = new RandomizedSet();
    int res;

    res = rs->insert(1);
    std::cout << res << std::endl;
    res = rs->remove(2);
    std::cout << res << std::endl;
    res = rs->insert(1);
    std::cout << res << std::endl;
    res = rs->getRandom();
    std::cout << res << std::endl;
    res = rs->remove(1);
    std::cout << res << std::endl;
    res = rs->insert(2);
    std::cout << res << std::endl;
    res = rs->getRandom();
    std::cout << res << std::endl;
}
