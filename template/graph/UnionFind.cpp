#include <vector>
using namespace std;

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

