#include <iostream>
#include "graph.h"

using std::vector;
using std::pair;
using std::cerr;
using std::cout;
using std::endl;

// 构造函数
Graph::Graph(int n, bool dir = false, bool weight = false, int rep = 0) 
    : numVertices(n), directed(dir), weighted(weight), representation(rep) {
    // 根据表示方式初始化
    if (representation == 0) {
        // 邻接表
        adjList.resize(n);
    } else if (representation == 1) {
        // 邻接矩阵
        adjMatrix.resize(n, vector<double>(n, 0));
    }
    // 边列表不需要初始化，直接为空
}

// 添加边
void Graph::addEdge(int u, int v, double w = 1.0) {
    if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
        cerr << "Invalid vertex index!" << endl;
        return;
    }

    // 如果非加权图，权重默认为1.0
    if (!weighted) {
        w = 1.0;
    }

    // 根据表示方式添加边
    if (representation == 0) {
        // 邻接表
        adjList[u].push_back({v, w});
        if (!directed) {
            adjList[v].push_back({u, w});
        }
    } else if (representation == 1) {
        // 邻接矩阵
        adjMatrix[u][v] = w;
        if (!directed) {
            adjMatrix[v][u] = w;
        }
    }

    // 边列表：总是添加
    edgeList.push_back({u, {v, w}});
    if (!directed) {
        // 如果是无向图，添加反向边
        edgeList.push_back({v, {u, w}});
    }
}

// 获取节点的邻居（邻接表方式）
vector<pair<int, double>> Graph::getNeighbors(int u) {
    vector<pair<int, double>> neighbors;
    if (representation == 0) {
        // 直接从邻接表获取
        for (auto& edge : adjList[u]) {
            neighbors.push_back(edge);
        }
    } else if (representation == 1) {
        // 从邻接矩阵获取
        for (int v = 0; v < numVertices; v++) {
            if (adjMatrix[u][v] != 0) {
                neighbors.push_back({v, adjMatrix[u][v]});
            }
        }
    } else {
        // 如果当前是边列表表示，我们也可以从边列表构建邻居列表
        // 但这样效率较低，通常我们不会直接用边列表来获取邻居
        // 这里为了完整性，我们也实现一下
        for (auto& edge : edgeList) {
            if (edge.first == u) {
                neighbors.push_back(edge.second);
            }
        }
    }
    return neighbors;
}

// 获取所有边
vector<pair<int, pair<int, double>>> Graph::getEdges() {
    return edgeList;
}

// 获取节点数量
int Graph::getNumVertices() {
    return numVertices;
}

// 获取边数量
int Graph::getNumEdges() {
    if (representation == 0) {
        int count = 0;
        for (int i = 0; i < numVertices; i++) {
            count += adjList[i].size();
        }
        return directed ? count : count / 2;
    } else if (representation == 1) {
        int count = 0;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] != 0) {
                    count++;
                }
            }
        }
        return directed ? count : count / 2;
    } else {
        return directed ? edgeList.size() : edgeList.size() / 2;
    }
}

// 打印图
void Graph::printGraph() {
    cout << "Graph representation: ";
    if (representation == 0) {
        cout << "Adjacency List" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (auto& edge : adjList[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << endl;
        }
    } else if (representation == 1) {
        cout << "Adjacency Matrix" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Edge List" << endl;
        for (auto& edge : edgeList) {
            cout << "(" << edge.first << ", " << edge.second.first << ", " << edge.second.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    // 创建一个有5个节点的无向加权图，使用邻接表表示
    Graph g(5, false, true, 0);
    g.addEdge(0, 1, 1.5);
    g.addEdge(0, 2, 2.0);
    g.addEdge(1, 3, 1.0);
    g.addEdge(2, 4, 2.5);

    g.printGraph();

    cout << "Number of edges: " << g.getNumEdges() << endl;

    // 获取节点0的邻居
    auto neighbors = g.getNeighbors(0);
    cout << "Neighbors of node 0: ";
    for (auto& n : neighbors) {
        cout << "(" << n.first << ", " << n.second << ") ";
    }
    cout << endl;

    return 0;
}