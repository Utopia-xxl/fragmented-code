#include <vector>

using namespace std;
/**
 * 算法思想：将图中边按从小到大排序，然后从最小边开始扫描各边，并检测当前边是否为候选边，
 * 即是否该边大并入会构成回路，如不构成回路，则将该边并入当前生成树中，直到所有边都被检测完为止
 *
 * 适用：有权图，求连通所有节点的最小花费
 * 如果是边比较多的图更适合用Prim算法求解
 */
// kruskal中需要利用并查集
class UnionFind{
private:
    // 记录连通分量
    int count;
    // 节点x的节点是parent[x]
    vector<int> parent;
public:
    // 构造函数，n为图的节点个数
    UnionFind(int n){
        // 一开始互不连通
        this->count = n;
        // 父节点指针初始指向自己
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    void Union(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ)
            return;
        // 将两棵树合并为1棵
        parent[rootP] = rootQ;
        count--; // 两个连通分量合二为一
    }

    // 返回某个节点x的根节点
    int find(int x){
        // 根节点的parent[x] == x
        while (parent[x]!=x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return parent[x];
    }

    bool connected(int p, int q){
        return find(p)==find(q);
    }
};

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

class Kruskal {
public:
    int main(vector<Edge> &edges) {
        int n;  // n为图中的节点
        int mst = 0; //最小权值和
        // 根据Kruskal的算法思想，对所有边排序选最短的,从小到大排序好
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int { return a.weight < b.weight; });
        UnionFind uf(n);
        for(auto &edge:edges){
            int u = edge.p1;
            int v = edge.p2;
            int weight = edge.weight;
            // 若这条边会产生环，则不能加入mst
            if(uf.connected(u,v)){
                continue;
            }
            // 若这条边不会产生环，则属于最小生成树
            mst += weight;
            uf.Union(u,v);
        }
        return mst;
    }
};

