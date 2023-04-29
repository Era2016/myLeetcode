#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
class Solution {
private:
    bool hasCycle = false;
    vector<int> visit;
    list<int> postOrder;
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (const auto& info: prerequisites) {
            graph[info[1]].push_back(info[0]);
        }
        return graph;
    }
    void dfs(vector<vector<int>>& graph, int s) {
        visit[s] = 1;
        for (int v: graph[s]) {
            if (visit[v] == 0) {
                dfs(graph, v);
                if (hasCycle) return;
            } else if (visit[v] == 1) {
                hasCycle = true;
                return;
            }
        }
        visit[s] = 2;
        postOrder.push_back(s);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);

        visit.clear(); visit.resize(numCourses);
        postOrder.clear();

        for (int i = 0; i < numCourses && !hasCycle; i ++) {
            if (visit[i] == 0) {
                dfs(graph, i);
            }
        }

        if (hasCycle) return {};

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
