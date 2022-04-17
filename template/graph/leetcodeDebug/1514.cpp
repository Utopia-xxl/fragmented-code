//
// Created by 向新亮 on 2022/4/16.
//
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct State{
    // 图中节点的id
    int id;
    // 从start节点到当前节点的距离
    double distFromStart;

    State(int id, double distFromStart):id(id),distFromStart(distFromStart){}

};

struct Cmp{
    bool operator()(State& a,State& b){
        return a.distFromStart < b.distFromStart;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // 以邻接表的形式构建graph
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        //  存储最大的概率
        vector<double> distTo(n,0);
        distTo[start] = 1;
        priority_queue<State,vector<State>,Cmp> pq;
        pq.push({start,1.0});
        while(!pq.empty()){
            State curState = pq.top();
            pq.pop();
            int curNodeID = curState.id;
            double curDistFromStart = curState.distFromStart;
            if(curDistFromStart<distTo[curNodeID]){
                // 已经有一条更短的路径到达此节点，因此可以直接跳过. ->> 已经有成功概率更大的路径
                continue;
            }
            // 将curNode 的相邻节点装入队列
            for(pair<int,double> &neighbor: graph[curNodeID]){
                int nextNodeID = neighbor.first;
                // 看看从 curNode 到 nextNode的距离是否会更短 ->> 概率是否会更大
                // 它相邻的节点，能否通过此节点获得更大的概率
                double distToNextNode = distTo[curNodeID]*neighbor.second;
                if(distTo[nextNodeID]<distToNextNode){
                    // 更新 dp table
                    distTo[nextNodeID] = distToNextNode;
                    //将这个节点以及距离放入队列
                    pq.push({nextNodeID,distToNextNode});
                }
            }
        }
        return distTo[end];
    }
};
int main(){
    Solution obj;
    vector<vector<int>> times{{0,1},{1,2},{0,2}};
    vector<double> prop{0.5,0.5,0.2};
    obj.maxProbability(3,times,prop,0,2);
    return 0;
}