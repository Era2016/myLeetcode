#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
class Solution {
private:
    bool hasCycle = false;
    vector<bool> visited;
    vector<bool> onPath;
    list<int> postOrder;
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses, vector<int>());
        for (const auto& edge: prerequisites) {
            graph[edge[1]].emplace_back(edge[0]);
        }
        return graph;
    }

    void traverse(vector<vector<int>>& graph, int s) {
        if (onPath[s]) {
            hasCycle = true;
        }
        if (visited[s] || hasCycle) {
            return;
        }
        onPath[s] = true;
        visited[s] = true;

        for (int t: graph[s]) {
            traverse(graph, t);
        }
        postOrder.emplace_back(s);
        onPath[s] = false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);

        visited.clear(); visited.resize(numCourses);
        onPath.clear(); onPath.resize(numCourses);
        postOrder.clear();

        for (int i = 0; i < numCourses; i ++) {
            traverse(graph, i);
        }

        if (hasCycle) {
            return {};
        }
        postOrder.reverse();
        
        return vector<int>(postOrder.begin(), postOrder.end());
    }    
};

void print(vector<int>& v) {
    for (auto i: v) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
}

int main() {
    Solution* so = new Solution();
    int numCourses;
    vector<int> ret;
    vector<vector<int>> vv;

    numCourses = 2; vv = {{1,0}}; 
    ret = so->findOrder(numCourses, vv);
    print(ret);

    numCourses = 4; vv = {{1,0},{2,0},{3,1},{3,2}}; 
    ret = so->findOrder(numCourses, vv);
    print(ret);

    numCourses = 1; vv = {}; 
    ret = so->findOrder(numCourses, vv);
    print(ret);
}
