#include <vector>
#include <queue>
using namespace std;
// 维护节点的状态，辅助算法运行
struct State{
    // 图中节点的id
    int id;
    // 从start节点到当前节点的距离
    int distFromStart;

    State(int id, int distFromStart):id(id),distFromStart(distFromStart){}

};

struct Cmp{
    bool operator()(State& a,State& b){
        return a.distFromStart > b.distFromStart;
    }
};

    // 输入一个图和一个起点start，计算start到其他节点的最短路径
    vector<int> dijkstra(int start,vector<vector<int>> &graph){
        int n = graph.size(); // 节点个数
        // 记录最短路径的权重， 你可以理解为 dp table
        // 定义：distTo[i] 的值就是节点start 到达节点i的最短路径权重,求最小值，所以初始化为最大值
        vector<int> distTo(n,INT_MAX);
        distTo[start] = 0;

        // 优先队列，distFromStart较小的排在前面
        priority_queue<State,vector<State>,Cmp> pq;
        pq.push({start,0});
        while(!pq.empty()){
            State curState = pq.top();
            pq.pop();
            int curNodeID = curState.id;
            int curDistFromStart = curState.distFromStart;
               if(curDistFromStart>distTo[curNodeID]){
                   // 已经有一条更短的路径路
                   continue;
               }
               // 将curNode 的相邻节点装入队列
               for(int &nextNodeID: graph[curNodeID]){
                   // 看看从 curNode 到 nextNode的距离是否会更短
                   int distToNextNode = distTo[curNodeID]+weight(curNodeID,nextNodeID);
                   if(distTo[nextNodeID]>distToNextNode){
                       // 更新 dp table
                       distTo[nextNodeID] = distToNextNode;
                       //将这个节点以及距离放入队列
                       pq.push({nextNodeID,distToNextNode});
                   }
               }
        }
        return distTo;
    }

