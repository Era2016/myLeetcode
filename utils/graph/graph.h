/*
说明
* 构造函数：可以指定节点数量、是否有向、是否加权、表示方式（0-邻接表，1-邻接矩阵，2-边列表）。
* 添加边：根据图的类型（有向/无向，加权/非加权）和表示方式存储边。
* 获取邻居：根据不同的表示方式，返回指定节点的邻居。
* 获取边数量：根据表示方式计算边数。
* 打印图：根据表示方式打印图的内容。

注意
在实际应用中，我们通常不会在一个类中同时实现多种表示方式，这里只是为了演示。

边列表方式在获取邻居时效率较低，因为需要遍历所有边。
邻接矩阵方式在稀疏图中会浪费空间。

根据具体需求，选择合适的表示方式：
* 邻接表：适用于稀疏图，需要频繁获取邻居的场景。
* 邻接矩阵：适用于稠密图，需要快速判断两个节点是否相邻。
* 边列表：适用于需要遍历所有边的场景，如Kruskal算法。

你可以根据实际需要调整这个类，例如增加删除边的功能，或者支持动态添加节点等。
*/
#include <vector>
#include <list>
#include <utility> // for pair

class Graph {
private:
    int numVertices;
    bool directed;
    bool weighted;

    // 邻接表表示：每个节点有一个列表，存储邻居和权重（如果加权）
    std::vector<std::list<std::pair<int, double>>> adjList;

    // 邻接矩阵表示：如果加权，存储权重；否则，存储1（表示有边）或0（表示无边）
    std::vector<std::vector<double>> adjMatrix;

    // 边列表：存储边（起点，终点，权重）
    std::vector<std::pair<int, std::pair<int, double>>> edgeList;

    // 表示方式：0-邻接表，1-邻接矩阵，2-边列表
    int representation;

public:
    // 构造函数
    Graph(int n, bool dir, bool weight, int rep); 
    // 添加边
    void addEdge(int u, int v, double w);
    // 获取节点的邻居（邻接表方式）
    std::vector<std::pair<int, double>> getNeighbors(int u); 
    // 获取所有边
    std::vector<std::pair<int, std::pair<int, double>>> getEdges();
    // 获取节点数量
    int getNumVertices();
    // 获取边数量
    int getNumEdges();
    // 打印图
    void printGraph();
};

