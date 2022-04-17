//
// Created by 向新亮 on 2022/4/16.
//
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
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 节点编号是从1开始的，所以要一个大小为n+1的邻接表
        vector<vector<vector<int>>> graph(n+1);
        // build graph
        for(vector<int> &edge: times){
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            // 邻接表存储图结构，同时保存边的权重信息
            vector<int> oneEdge{to,weight};
            graph[from].push_back(oneEdge);
        }
        // 启动dijkstra算法计算以节点k为起点到其他节点的最短路径
        vector<int> distTo = dijkstra(k,graph);

        int res=0;
        // 找到最长的路径，即distTo[]中的最大值
        for(int i=1;i<distTo.size();i++){
            if(distTo[i]==INT_MAX){
                // 有节点不可达
                return -1;
            }
            res = max(res,distTo[i]);
        }
        return res;
    }

    // 输入一个图和一个起点start，计算start到其他节点的最短路径
    vector<int> dijkstra(int start,vector<vector<vector<int>>> &graph){
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
                // 已经有一条更短的路径到达此节点，因此可以直接跳过
                continue;
            }
            // 将curNode 的相邻节点装入队列
            for(vector<int> &neighbor: graph[curNodeID]){
                int nextNodeID = neighbor[0];
                // 看看从 curNode 到 nextNode的距离是否会更短
                int distToNextNode = distTo[curNodeID]+neighbor[1];
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
};
int main(){
    Solution obj;
    vector<vector<int>> times{{2,1,1},{2,3,1},{3,4,1}};

    obj.networkDelayTime(times,4,2);
    return 0;
}