#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) return;
            } else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.clear(); edges.resize(numCourses);
        visited.clear(); visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < numCourses && valid; ++ i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
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
