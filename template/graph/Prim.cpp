#include <vector>
#include <queue>

using namespace std;

// 定义边的结构体
struct Edge{
    int p1;
    int p2;
    int weight;
    Edge(int _p1,int _p2,int _weight){
        p1=_p1;
        p2=_p2;
        weight=_weight;
    }
};

struct Cmp{
    bool operator()(Edge& a,Edge& b){
        return a.weight>b.weight;
    }
};

class Prim{
private:
    // 核心数据结构，存储 横切边 的优先队列
    priority_queue<Edge,vector<Edge>,Cmp> pq;
    // 类似 visited 数组的作用，记录哪些节点已经成为最小生成树的一部分
    vector<bool> inMST;
    // 记录最小生成树的权重和
    int weightSum = 0;
    // graph 是用邻接表表示的一幅图
    // graph[s] 记录s所有相邻的边
    // 三元组  {form to weight} 表示一条边
    vector<vector<Edge>> graph;
public:
    Prim(vector<vector<Edge>> &graph){
        // init
        this->graph = graph;
        int n = graph.size(); // 图中有n个节点
        this->inMST.resize(n);

        // 随便从哪个节点开始切都可以，默认从0开始
        inMST[0] = true;
        cut(0);
        // 不断进行切分，向最小生成树中添加边
        while(!pq.empty()){
            Edge edge = pq.top();
            pq.pop();
            int to = edge.p2;
            int weight = edge.weight;
            if(inMST[to]){
                // 节点to 已经在最小生成树中，跳过
                // 否则这条边会产生环
                continue;
            }
            // 将边 edge 加入最小生成树
            weightSum += weight;
            inMST[to] = true;
            // 节点 to 加入后， 进行新一轮切分， 会产生更多横切边
            cut(to);
        }
    }

    // 将 s 的横切边加入优先队列
    void cut(int s){
        // 遍历s的邻边
        for(Edge &edge : graph[s]){
            int to = edge.p2;
            if(inMST[to]){
                // 相邻节点to已经在最小生成树中，跳过
                // 否则这条边会产生环
                continue;
            }
            // 加入横切边队列
            pq.emplace(edge);
        }
    }

    // 最小生成树的权重和
    int getWeightSum(){
        return weightSum;
    }

    // 判断最小生成树是否包含图中所有节点
    bool allConnected(){
        for(auto && i : inMST){
            if(!i){
                return false;
            }
        }
        return true;

    }
};

