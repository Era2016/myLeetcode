#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
class Solution {
private:
    vector<bool> onPath;
    vector<bool> visited;
    bool hasCycle;

    vector<list<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> graph = vector<list<int>>(numCourses, list<int>());
        for (auto edge: prerequisites) {
            int from = edge[1], to = edge[0];
            graph[from].emplace_back(to);
        }
        return graph;
    }

    void traverse(vector<list<int>> graph, int s) {
        if (onPath[s]) {
            hasCycle = true;
        }

        if (visited[s] || hasCycle) {
            return;
        }

        visited[s] = true;
        // 开始遍历
        onPath[s] = true;
        for (auto t : graph[s]) {
            traverse(graph, t);
        }

        // 遍历完成
        onPath[s] = false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> graph = buildGraph(numCourses, prerequisites);

        visited = vector<bool>(numCourses, false);
        onPath = vector<bool>(numCourses, false);
        //visited.resize(numCourses);
        //onPath.resize(numCourses);

        for (int i = 0; i < numCourses; i ++) {
            traverse(graph, i);
        }

        return !hasCycle;
    }
};

int main() {
    Solution* so = new Solution();
    int numCourses;
    vector<vector<int>> vv;

    numCourses = 2, vv = {{1,0}};
    std::cout << so->canFinish(numCourses, vv) << std::endl;

    numCourses = 2, vv = {{1,0}, {0,1}};
    std::cout << so->canFinish(numCourses, vv) << std::endl;
}
